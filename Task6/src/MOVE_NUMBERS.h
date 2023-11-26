//
// Created by dice on 11/26/23.
//

#ifndef MOVE_NUMBERS_H
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

#endif //MOVE_NUMBERS_H
