#!/usr/bin/env bash

TERMS=10000000000

gcc -pthread -o pithreads pithreads.c

printf "Dados para $TERMS termos:\n" > dados.txt
printf "Benchmark iniciada para $TERMS termos.\n"

printf "\nPara 1 thread:\n" >> dados.txt
printf "Benchmark 1 thread iniciada.\n"
{ time ./pithreads $TERMS 1 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 1 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 1 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 1 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 1 ; } >> dados.txt 2>&1
printf "Benchmark 1 thread OK!\n"

printf "\nPara 2 threads:\n" >> dados.txt
printf "Benchmark 2 threads iniciada.\n"
{ time ./pithreads $TERMS 2 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 2 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 2 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 2 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 2 ; } >> dados.txt 2>&1
printf "Benchmark 2 threads OK!\n"

printf "\nPara 4 threads:\n" >> dados.txt
printf "Benchmark 4 threads iniciada.\n"
{ time ./pithreads $TERMS 4 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 4 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 4 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 4 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 4 ; } >> dados.txt 2>&1
printf "Benchmark 4 threads OK!\n"

printf "\nPara 8 threads:\n" >> dados.txt
printf "Benchmark 8 threads iniciada.\n"
{ time ./pithreads $TERMS 8 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 8 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 8 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 8 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 8 ; } >> dados.txt 2>&1
printf "Benchmark 8 threads OK!\n"

printf "\nPara 16 threads:\n" >> dados.txt
printf "Benchmark 16 threads iniciada.\n"
{ time ./pithreads $TERMS 16 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 16 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 16 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 16 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 16 ; } >> dados.txt 2>&1
printf "Benchmark 16 threads OK!\n"

printf "\nPara 32 threads:\n" >> dados.txt
printf "Benchmark 32 threads iniciada.\n"
{ time ./pithreads $TERMS 32 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 32 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 32 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 32 ; } >> dados.txt 2>&1
{ time ./pithreads $TERMS 32 ; } >> dados.txt 2>&1
printf "Benchmark 32 threads OK!\n"