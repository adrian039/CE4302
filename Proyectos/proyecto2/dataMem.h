
#ifndef DATAMEM_H
#define DATAMEM_H

#include <string>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <pthread.h>
#include "clock.h"
#include "config.h"

class DataMem
{
  public:
    DataMem(Clock *clk);
    int write=0;
    int data=0;
    int index=0;
    int *dataMemory=(int*)calloc(262144, sizeof(int)); //1MB
    pthread_cond_t dataMemCondMutex = PTHREAD_COND_INITIALIZER;
    pthread_cond_t dataMemReadMutex = PTHREAD_COND_INITIALIZER;

  private:
    Clock *clk;
    int readData(int index);
    void writeData(int data, int index);
    pthread_t threadDataMem;
    static void *start(void *ptr);
};

#endif