# pi-threads
Parallel implementation of a value of Pi calculation using the Leibniz-Grégory Series. Can be used to compare performance between CPUs or different number of threads used.

# C code

The C code is the actual algorithm that creates the threads, instructs them to perform the calculation, frees everything and (optionally) prints the value of Pi calculated.

Note: You cannot achieve infinite precision with this code, it is limited by the hardware that you run this code on.

# Shell Script

The shell script included can be used in GNU/Linux based systems to run the code as a benchmark, it will save 5 measurements of the time needed to run the calculations for 10 billion terms of the series, using 6 different numbers of threads: 1, 2, 4, 8, 16, 32. By averaging these measurements and comparing with others you can have an idea how different thread numbers and processors influence the performance in this type of application.

# Graph

This graph shows the time taken by 4 different processors, 2 from Intel and 2 from AMD, to finish the calculation of 10 billion terms of the series using the 6 different numbers of threads:

![Bar graph showing the values for 4 different processors](https://github.com/gustavomotadev/pi-threads/blob/main/graph1.png?raw=true)

The CPUs are ordered based on their single core time, ascending from left to right. The processor i5-7500 has 4 cores with no multithreading, you can easily see how using more than 4 threads in this processor makes no difference at all. The i7-6700 and the Ryzen 5 2400G have 4 cores, but they are capable of multithreading, so they actually gain some performance when increasing from 4 to 8 threads. The Ryzen 5 3600, despite consuming more time than the Intel processors when using a single thread, ends up being the fastest when using 8 threads or more, and gains performance when increasing from 8 threads to 16. This happens because the Ryzen 5 3600 processor has 6 cores and is capable of multithreading.
