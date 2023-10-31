/***************************************************************************************************** 
*                           Author:  Abdelrahman Gamal Abdelwanies Mohamed                           *
*							Created: 16/10/2023                                                      *
*							Project: School Mangement System                                         *
*							File: SchoolMangementSystem.h                                            *
*							[NTI Embedded C Final Project] 		                                     *
*****************************************************************************************************/


#ifndef SCHOOL_MANGEMENT_SYSTEM_H_
#define SCHOOL_MANGEMENT_SYSTEM_H_

#include "STD_TYPES.h"

/* Base ID For ID Generator Function */
#define Base_ID  2023000


/* Error State Data Type */
typedef enum Error
{
	NOT_OK=0,
	OK=1,
	INVALID_DAY=2,
	INVALID_MONTH=3,

}Error_State;



/* Birth Date Data Type */
typedef struct Birth_Date
{
	u32 Day;
	u32 Month;
	u32 Year;

}Birth;



/* Student_t Data Type */
typedef struct MyNode
{
	u8     Name[50];
	u32    ID;
	Birth  Date_of_Birth;
	u8     Address[50];
	u8     Phone_Number[20];
	u32    Score;

	struct MyNode* Ptr_Next;

}Student_t;


/* __(0)__Main Function That Display All Options in The System */
Error_State Main_Menu (Student_t *Head,Student_t **Head_Address);

/* __(1)__Function That Create New Student */
void New_Student (Student_t *Head,Student_t **Head_Address);

/* __(2)__Function That Delete Exicting Student */
void Delete_Student (Student_t *Head,Student_t **Head_Address);

/* __(3)__Function That Update Student Record Data */
void Students_Edit (Student_t *Head);

/* __(4)__Function That Raniking The Students According To There Computer Science Score */
void Rank_Students (Student_t *Head);

/* __(5)__Function Used To Update Students Computer Science Score */
void Students_Score (Student_t *Head);

/* __(6)__Function Used To List Students According to [Name] Alphabetically Ascinding */
void Students_List (Student_t *Head);

/* __(7)__Function The Sawp Two Names in Linked-List */
void Swap_Names(Student_t *Str1,Student_t *Str2);

/* __(8)__Function That Count Number Of Student Registered */
u32 NumberOfNodes(Student_t *Head);

/* __(9)__Function That Check Validtion of Input Bith Date */
Error_State BirthDate_Validation(Student_t *Birth_Date);

/* __(10)__Function That Generate a Unique ID For Every Student */
u32 ID_Generator (Student_t *Head,u32 Nodes);

#endif
