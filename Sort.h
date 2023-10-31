/************************************************************************************************************************************** 
*                                           Author:  Abdelrahman Gamal Abdelwanies Mohamed                                            *
*											Created: 16/10/2023                                                                       *
*											Project: School Mangement System                                                          *
*											File: Sort.h                                                                              *
*											[NTI Embedded C Graduiation Project] 													  *
**************************************************************************************************************************************/

#ifndef SORT_H_
#define SORT_H_ 

#include"STD_TYPES.h"
#include "SchoolMangementSystem.h"

/* Macros To Chose The Control Key Of Sorting Operation */
#define KEY_NAME      2
#define KEY_SCORE     3

/* Functions That Swaps Two Students Records */
void Students_Swap(Student_t *Str1,Student_t *Str2);


/* Functions That Sort Students Records According To [Name] OR [Computer Scinece Score] */
void Students_Sort(Student_t *Head,u32 Key_Sort);

#endif 