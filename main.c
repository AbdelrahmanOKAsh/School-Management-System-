/************************************************************************************************************************************** 
*                                           Author:  Abdelrahman Gamal Abdelwanies Mohamed                                            *
*											Created: 16/10/2023                                                                       *
*											Project: School Mangement System                                                          *
*											File: main.c                                                                              *
*											[NTI Embedded C Graduiation Project] 													  *
**************************************************************************************************************************************/

#include <stdio.h>
#include "STD_TYPES.h"
#include "SchoolMangementSystem.h"


int main()
{
	
	u16 Main_Return=0;
	Student_t *Registration=NULL;
	printf("\n***************************************************************( School Management System )*******************************************************************\n\n");
	
	while (1)
	{
		Main_Return=Main_Menu(Registration,&Registration);

		if (Main_Return==NOT_OK)
		{
			break;
		}
		
	}
	
	return OK;
}