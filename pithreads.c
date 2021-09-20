#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

//#define PRINT_DEBUG_INFO
//#define PRINT_GENERAL_INFO

struct threadHelper 
{
    uint64_t start;
    uint64_t end;
    double partialSum;
};

bool isIntegerString(char * str)
{
    int i;
    for(i = 0; str[i] != '\0'; i++)
        if(!isdigit(str[i])) return false;

    return true;
}

void *threadWork(void *threadHelper) 
{ 
    uint64_t start = ((struct threadHelper*) threadHelper)->start;
    uint64_t end = ((struct threadHelper*) threadHelper)->end;
    double partialSum = 0;
    uint64_t current;

    for(current = start; current < end; current++)
    {
        partialSum += ( (current & 1) ? 
            ( - ( 1 / ( (double) ((current << 1) + 1) ) ) ) : 
            ( ( 1 / ( (double) ((current << 1) + 1) ) ) ) );
    }

    ((struct threadHelper*) threadHelper)->partialSum = partialSum;

    #ifdef PRINT_DEBUG_INFO
    printf("start: %lu    end: %lu    partial: %.20lf\n", 
        start, end, partialSum); //DEBUG
    #endif

    return threadHelper; 
}

int main(int argc, char **argv)
{
    uint64_t terms, threads, quota, rest, index;
    struct threadHelper *helperArray;
    pthread_t *threadArray;
    int fail = 0;
    double answer = 0;

    if(argc != 3) 
        printf("Usage: ./pithreads number_of_terms number_of_threads\n");
    else
    {
        if(!isIntegerString(argv[1]) || !isIntegerString(argv[2]))
            printf("Please pass only positive integers as arguments.\n");
        else
        {
            terms = strtol(argv[1], NULL, 0);
            threads = strtol(argv[2], NULL, 0);

            if(terms == 0 || threads == 0) printf("At least one term and one thread are needed.\n");
            else
            {
                if(threads > terms)
                {
                    threads = terms;
                    #ifdef PRINT_GENERAL_INFO
                    printf("No need for excess threads, using only %lu instead.\n", threads);
                    #endif
                }

                #ifdef PRINT_GENERAL_INFO
                printf( "Calculating PI with %lu series terms and %lu threads.\n", 
                terms, threads);
                #endif

                helperArray = 
                    (struct threadHelper *) malloc(threads*sizeof(struct threadHelper));

                threadArray = (pthread_t *) malloc(threads*sizeof(pthread_t));

                if(helperArray == NULL || threadArray == NULL) 
                {
                    printf("Memory allocation failed.");
                    fail = EXIT_FAILURE;
                }
                else
                {

                    quota = terms/threads;
                    rest = terms%threads;

                    #ifdef PRINT_DEBUG_INFO
                    printf("quota per thread: %lu    excess work for last thread: %lu\n", 
                        quota, rest); //DEBUG
                    #endif

                    for(index = 0; index < threads; index++)
                    {
                        helperArray[index].start = index*quota;
                        helperArray[index].end = helperArray[index].start + quota;
                        if(index == (threads - 1)) helperArray[index].end += rest;
                        
                        #ifdef PRINT_DEBUG_INFO
                        printf("thread number: %lu    start: %lu    end: %lu\n", 
                            index, helperArray[index].start, helperArray[index].end); //DEBUG
                        #endif

                        //threadWork((void*) &helperArray[index]); //testar de forma sequencial

                        if( ( fail = pthread_create(&threadArray[index], NULL, 
                            threadWork, (void*) &helperArray[index]) ) != 0)
                        {
                            printf("Failed to create thread");
                            break;
                        }
                    }

                    if(fail == 0)
                    {

                        for(index = 0; index < threads; index++)
                        {
                            pthread_join(threadArray[index], NULL);
                            answer += helperArray[index].partialSum;
                        }

                        #ifdef PRINT_GENERAL_INFO
                        printf("PI = %.100lf\n", 4 * answer);
                        #endif

                    }

                }

                free(helperArray);
                free(threadArray);

            }

        }
        
    }
    

    return fail;
}