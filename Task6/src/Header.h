//
// Created by dice on 11/26/23.
//

#ifndef TASK6_HEADER_H
#define TASK6_HEADER_H
#define N 10
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
#define MOVE_NUMBERS_H(pArray, size) int temp; \
                                    for (int i = 0; i < size; i++) \
                                    { \
                                        if (pArray[i] < 1) \
                                        { \
                                            temp = pArray[i]; \
                                            for (int j = i; j > 0; j--) \
                                            { \
                                                pArray[j] = pArray[j - 1]; \
                                            } \
                                            pArray[0] = temp; \
                                            break; \
                                        } \
                                    }

#define PRINT_ARRAY_H(pArray, size) for (int i = 0; i < size; i++) \
                                   { \
                                       cout << pArray[i] << " "; \
                                   } \
                                   cout << endl;

#endif //TASK6_HEADER_H
