#ifndef UTIL_H
#define UTIL_H

#include <constants.h>

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define testBit(value, bit) (value & (1 << bit))

char *byteToBinary(
        char *dest,
        const char *src,
        int n,
        size_t startPoint
        );

void isSizeCorrect(
        int size,
        int expectedSize,
        int errorCode
        );

void setTerminationHandler();

void resetCleanUpHook();

int getTopicPipe(
        char *topicPath,
        mode_t mode
        );

#endif
