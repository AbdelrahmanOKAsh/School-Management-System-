/***************************************************************************************************** 
*                           Author:  Abdelrahman Gamal Abdelwanies Mohamed                           *
*							Created: 16/10/2023                                                      *
*							Project: School Mangement System                                         *
*							File: Sort.c                                                             *
*							[NTI Embedded C Final Project] 		                                     *
*****************************************************************************************************/

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.h"
#include "Sort.h"
#include "SchoolMangementSystem.h"

void Students_Swap(Student_t *Str1,Student_t *Str2)
{
    Student_t *Temp;
    Temp=(Student_t*)malloc(sizeof(Student_t));

    /* Swap Students Names */
    strcpy((Temp->Name),(Str1->Name)); 
	strcpy((Str1->Name),(Str2->Name)); 
	strcpy((Str2->Name),(Temp->Name));

    /* Swap Students ID */
    (Temp->ID)=(Str1->ID); 
	(Str1->ID)=(Str2->ID); 
	(Str2->ID)=(Temp->ID); 
    
    /* Swap Students Birth Date [Day] */
    ((Temp->Date_of_Birth).Day)=((Str1->Date_of_Birth).Day); 
	((Str1->Date_of_Birth).Day)=((Str2->Date_of_Birth).Day); 
	((Str2->Date_of_Birth).Day)=((Temp->Date_of_Birth).Day);

    /* Swap Students Birth Date [Month] */
    ((Temp->Date_of_Birth).Month)=((Str1->Date_of_Birth).Month); 
	((Str1->Date_of_Birth).Month)=((Str2->Date_of_Birth).Month); 
	((Str2->Date_of_Birth).Month)=((Temp->Date_of_Birth).Month); 

    /* Swap Students Birth Date [Year] */
    ((Temp->Date_of_Birth).Year)=((Str1->Date_of_Birth).Year); 
	((Str1->Date_of_Birth).Year)=((Str2->Date_of_Birth).Year); 
	((Str2->Date_of_Birth).Year)=((Temp->Date_of_Birth).Year); 

    /* Swap Students Adresses */
    strcpy((Temp->Address),(Str1->Address)); 
	strcpy((Str1->Address),(Str2->Address)); 
	strcpy((Str2->Address),(Temp->Address));

    /* Swap Students Phone Numbers */
    strcpy((Temp->Phone_Number),(Str1->Phone_Number)); 
	strcpy((Str1->Phone_Number),(Str2->Phone_Number)); 
	strcpy((Str2->Phone_Number),(Temp->Phone_Number)); 

    /* Swap Students Scores */
    (Temp->Score)=(Str1->Score); 
	(Str1->Score)=(Str2->Score); 
	(Str2->Score)=(Temp->Score);

    free(Temp);        
}

void Students_Sort(Student_t *Head,u32 Key_Sort)
{
    Student_t *Current=Head;
    Student_t *Index=NULL;
    s32 StrCmp_Flag=0;

    switch (Key_Sort)
    {
        case KEY_NAME:
            printf("\n");
            while (Current!=NULL)
            {
                Index=(Current->Ptr_Next);

                while(Index!=NULL)
                {
                    StrCmp_Flag=strcmp((Current->Name),(Index->Name));
                    if ( StrCmp_Flag > 0 )
                    {
                        Students_Swap(Current,Index);
                    }

                    Index=(Index->Ptr_Next);
                }

                printf("\n %s\tID[%d]\tBirth Date: [%d/%d/%d]\tAddress: %s\tPhone Number: %s\tScore: [%d]\n",(Head->Name),(Head->ID),((Head->Date_of_Birth).Day),((Head->Date_of_Birth).Month),((Head->Date_of_Birth).Year),(Head->Address),(Head->Phone_Number),(Head->Score));
			    Head =(Head->Ptr_Next);
                Current=(Current->Ptr_Next);  
            }                 
            break;

        case KEY_SCORE:
            /* Loop on The Linked-List To Sort All Nodes */
            while (Current!=NULL)
            {
                /* Assign Pointer to The Next Node of Current */
                Index=(Current->Ptr_Next);

                while(Index!=NULL)
                {
                    if ( (Current->Score) < (Index->Score) )
                    {
                        Students_Swap(Current,Index);
                    }

                    /* Updating Index Point to The Next Node of Current [Index++] */
                    Index=(Index->Ptr_Next);
                }

                printf("\n Name: %s\tID[%d]\tComputer Scince Score[%d]\n",(Head->Name),(Head->ID),(Head->Score));
			    Head =(Head->Ptr_Next);

                /* Updating Current Postion to Point to The Next Node to be Sorted [Index++] */
                Current=(Current->Ptr_Next);
            }    
        break;

    default:
        return;
        break;
    }
}


