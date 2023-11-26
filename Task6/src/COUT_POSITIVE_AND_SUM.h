//
// Created by dice on 11/26/23.
//

#ifndef COUNT_POSITIVE_AND_SUM_H
#define COUNT_POSITIVE_AND_SUM_H(pArray, size, positiveCount, sum) positiveCount = 0; \
                                                                    sum = 0; \
                                                                    int lastZeroIndex = -1; \
                                                                    for (int i = 0; i < size; i++) \
                                                                    { \
                                                                        if (pArray[i] > 0) \
                                                                        { \
                                                                            positiveCount++; \
                                                                        } \
                                                                        if (pArray[i] == 0) \
                                                                        { \
                                                                            lastZeroIndex = i; \
                                                                            sum = 0; \
                                                                        } \
                                                                        if (lastZeroIndex != -1 && i > lastZeroIndex) \
                                                                        { \
                                                                            sum += pArray[i]; \
                                                                        } \
                                                                    }
#endif //COUNT_POSITIVE_AND_SUM_H
