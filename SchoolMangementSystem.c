/***************************************************************************************************** 
*                           Author:  Abdelrahman Gamal Abdelwanies Mohamed                           *
*			    Created: 16/10/2023                                                      *
*			    Project: School Mangement System                                         *
*			    File: SchoolMangementSystem.c                                            *
*			    [NTI Embedded C Final Project] 		                             *
*****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.h"
#include "Sort.h"
#include "SchoolMangementSystem.h"

/***************************************[Auxiliary Functions]****************************************/
u32 ID_Generator (Student_t *Head,u32 Nodes)
{
	u32 Local_Return=0;
	u32 Counter=1;


	if( (Head==NULL) && (Nodes==0) )
	{
		Local_Return=(Base_ID+1);
		return Local_Return;
	}
	while(Head!=NULL)
	{
		Counter++;
		Head =(Head->Ptr_Next);
	}
	Local_Return=(Base_ID+Counter);
    return Local_Return;
}

u32 NumberOfNodes(Student_t *Head)
{	
	u32 Local_Return=0;
	u32 count = 0;

	if(Head==NULL)
	{
		return Local_Return;
	}

    while(Head!=NULL)
	{
       count++;
       Head =(Head->Ptr_Next);
    }
	Local_Return=count;
    return Local_Return;
}

Error_State BirthDate_Validation(Student_t *Student)
{
	u32 Local_Return;
	if( ((((Student->Date_of_Birth).Day) > 0) && (((Student->Date_of_Birth).Day) < 31)) && ((((Student->Date_of_Birth).Month)>0) && (((Student->Date_of_Birth).Month) <= 12 )) )
	{
		Local_Return=OK;
		return Local_Return;
	}

	else if ( (((Student->Date_of_Birth).Day) < 0) || (((Student->Date_of_Birth).Day) > 31) )
	{
		Local_Return=INVALID_DAY;
		return Local_Return; 
	}

	else if (((((Student->Date_of_Birth).Month) < 0))  || (((Student->Date_of_Birth).Month) > 12))
	{
		Local_Return=INVALID_MONTH;
		return Local_Return; 
	}
}
/***********************************************************************************************/


/***************************************[Main Functions]****************************************/

Error_State Main_Menu(Student_t *Head,Student_t **Head_Address)
{
	u8  Main_Return=OK;
	u32 Your_Choise,Nodes;

	Nodes=NumberOfNodes(Head);
	printf(" [1] >> Create New Student Record \n");
	printf(" [2] >> Delete a Student Record \n");
	printf(" [3] >> Modify a Student Record \n");
	printf(" [4] >> Students Rank of CS Scores  \n");
	printf(" [5] >> Modify Students CS Scores \n");
	printf(" [6] >> List Current Students Data \n");
	printf(" [7] >> Terminate \n");
	printf(" ----------------[%u]------------------\n",Nodes);
	printf(" PLS Enter Your Option [1->7]: ");
	scanf("%d", &Your_Choise);
	switch (Your_Choise)
	{
		case 1:
			New_Student(Head,Head_Address);
			break;

		case 2:
			Delete_Student(Head,Head_Address);
			break;

		case 3:
			Students_Edit(Head);
			break;

		case 4:
			Rank_Students(Head);
			break;

		case 5:
			Students_Score(Head);
			break;

		case 6:
			Students_List(Head);
			break;

		case 7:
			Main_Return=NOT_OK;
			break;

		default:
			printf("\n ERROR!!: Invalid Option [Input Options: 1->6]\n");
			printf("\n ==================================[Process Finished]==================================\n\n");
			Main_Return=NOT_OK;
			return Main_Return;
			break;
	}
	return Main_Return;
}


void New_Student (Student_t *Head,Student_t **Head_Address)
{
	u32 Assigned_ID;
	u32 BirthDate_Flag=0;
	u32 Node=NumberOfNodes(Head);
	
	/*To Create The First Student Record at The Linked-List*/
	if (Head==NULL)
	{
		Student_t *New_Student;
		New_Student=(Student_t*)malloc(sizeof(Student_t));

		fflush(stdin);
		printf(" Name: ");
		gets(New_Student->Name);

		Assigned_ID=ID_Generator(Head,Node);
		(New_Student->ID)=Assigned_ID;

		printf(" Birth Date (D/M/Y): ");
		scanf("%d/%d/%d",&(New_Student->Date_of_Birth.Day),&(New_Student->Date_of_Birth.Month),&(New_Student->Date_of_Birth.Year));
		BirthDate_Flag=BirthDate_Validation(New_Student);
		while (BirthDate_Flag != OK)
		{
			if(BirthDate_Flag == INVALID_DAY)
			{
				printf("\n ERROR!!: Invalid Day Input must be: [1->31] PLS Enter Valid Day  \n");
				printf(" Birth Date (D/M/Y): ");
				scanf("%d/%d/%d",&(New_Student->Date_of_Birth.Day),&(New_Student->Date_of_Birth.Month),&(New_Student->Date_of_Birth.Year));
				BirthDate_Flag=BirthDate_Validation(New_Student);

			}

			else if(BirthDate_Flag == INVALID_MONTH)
			{
				printf("\n ERROR!!: Invalid Month Input must be: [1->12] PLS Enter Valid Month  \n");
				printf(" Birth Date (D/M/Y): ");
				scanf("%d/%d/%d",&(New_Student->Date_of_Birth.Day),&(New_Student->Date_of_Birth.Month),&(New_Student->Date_of_Birth.Year));
				BirthDate_Flag=BirthDate_Validation(New_Student);
			}
		}
		

		fflush(stdin);
		printf(" Address: ");
		gets(New_Student->Address);

		printf(" Phone Number: ");
		scanf("%s",&(New_Student->Phone_Number));

		printf(" Computer Scince Score: ");
		scanf("%u",&(New_Student->Score));

		printf("\n New Student Name[%s]-->ID[%u] Created Successfully..\n\n",(New_Student->Name),(New_Student->ID));
		printf("\n ==================================[Process Finished]==================================\n\n");

		/*Make List Adress Point to New Student */
		(New_Student->Ptr_Next)=*Head_Address;
		*Head_Address=New_Student;

	}

	/*To Add a New Student Record in The Linked-List*/
	else
	{
		Assigned_ID=ID_Generator(Head,Node);

		while ((Head->Ptr_Next)!=NULL)
		{
			Head=(Head->Ptr_Next);
		}

		(Head->Ptr_Next)=(Student_t*)malloc(sizeof(Student_t));

		fflush(stdin);
		printf(" Name: ");
		gets((Head->Ptr_Next)->Name);

		((Head->Ptr_Next)->ID)=Assigned_ID;

		printf(" Birth Date (D/M/Y): ");
		scanf("%d/%d/%d",&((Head->Ptr_Next)->Date_of_Birth.Day),&((Head->Ptr_Next)->Date_of_Birth.Month),&((Head->Ptr_Next)->Date_of_Birth.Year));
		BirthDate_Flag=BirthDate_Validation((Head->Ptr_Next));
		while (BirthDate_Flag != OK)
		{
			if(BirthDate_Flag == INVALID_DAY)
			{
				printf("\n ERROR!!: Invalid Day Input must be: [1->31] PLS Enter Valid Day  \n");
				printf(" Birth Date (D/M/Y): ");
				scanf("%d/%d/%d",&((Head->Ptr_Next)->Date_of_Birth.Day),&((Head->Ptr_Next)->Date_of_Birth.Month),&((Head->Ptr_Next)->Date_of_Birth.Year));
				BirthDate_Flag=BirthDate_Validation(Head->Ptr_Next);
			}

			else if(BirthDate_Flag == INVALID_MONTH)
			{
				printf("\n ERROR!!: Invalid Month Input must be: [1->12] PLS Enter Valid Month  \n");
				printf(" Birth Date (D/M/Y): ");
				scanf("%d/%d/%d",&((Head->Ptr_Next)->Date_of_Birth.Day),&((Head->Ptr_Next)->Date_of_Birth.Month),&((Head->Ptr_Next)->Date_of_Birth.Year));
				BirthDate_Flag=BirthDate_Validation(Head->Ptr_Next);
			}

			else 
			{
				free((Head->Ptr_Next));
				(Head->Ptr_Next)=NULL;
				return ;
			}
		}

		fflush(stdin);
		printf(" Address: ");
		gets((Head->Ptr_Next)->Address);

		printf(" Phone Number: ");
		scanf("%s",&((Head->Ptr_Next)->Phone_Number));

		printf(" Computer Scince Score: ");
		scanf("%u",&((Head->Ptr_Next)->Score));

		printf("\n New Student Name[%s]-->ID[%u] Added Successfully..\n\n",((Head->Ptr_Next)->Name),((Head->Ptr_Next)->ID));
		printf("\n ==================================[Process Finished]==================================\n\n");
        ((Head->Ptr_Next)->Ptr_Next) = NULL;
	}
}



void Delete_Student (Student_t *Head,Student_t **Head_Address)
{
	u32 ID;
	Student_t *Temp=NULL;

	printf("\n PLS Enter The ID: ");
	scanf("%u",&ID);

	/* Check If The List is Empty  */
	if (Head==NULL)
	{
		printf("\n WARNING!!: The Registration Data Base is Empty [NO Students to Delete]\n");
		printf("\n ==================================[Process Finished]==================================\n\n");
		return ;
	}

	/* If There is just one Student Registered */
	if (Head->Ptr_Next==NULL)
	{
		/* Changing The Head Pointer Before Deleting The Node */
		*Head_Address=(Head->Ptr_Next);

		/* Delete The Required Node To be Deleted */
		free(*Head_Address);

		printf("\n The Student Name[%s]->>ID[%u] Record has been Deleted Successfully.. \n",(Head->Name),ID);
		printf("\n The Registration Data Base becomes Empty [NO Students Registered] \n");
		printf("\n ==================================[Process Finished]==================================\n\n");
		return ;
	}
	
	/* Delete The Student Record Of That Particular ID --> (If The Head is already pointed to the ID) */
	else if((Head!=NULL) && ((Head->ID)==ID))
	{	
		*Head_Address=(Head->Ptr_Next);
		free(Head);

		printf("\n The Student Name[%s]->>ID[%u] Record has been Deleted Successfully..\n",(Head->Name),ID);
		printf("\n ==================================[Process Finished]==================================\n\n");
		return ;
	}

	/* Search of the ID */
	while((Head!=NULL) && ((Head->ID)!=ID))
	{
		Temp=Head;
		Head=(Head->Ptr_Next);
	}

	/* ID NOT Found in The Linked-List */
	if(Head==NULL)
	{
		printf("\n WARNING!!: The ID[%u] NOT Registered in The Registeration Data Base.. \n",ID);
		printf("\n ==================================[Process Finished]==================================\n\n");
		return ;
	}

	else
	{
		(Temp->Ptr_Next)=(Head->Ptr_Next);
		free(Head);

		printf("\n The Student of ID[%u] Record Has Been Deleted Successfully.. \n",ID);
		printf("\n ==================================[Process Finished]==================================\n\n");
	}
		
}


void Students_List (Student_t *Head)
{
	u32 Option;

	/* Check If The Linked-List is Empty */
	if (Head==NULL)
	{
		printf("\n WARNING!!: The Registration Data Base is Empty [NO Students to List]\n");
		printf("\n ==================================[Process Finished]==================================\n\n");
		return;
	}

	else
	{	
		printf("\n ==================================[Registeration Data Base]==================================\n\n");
		Students_Sort(Head,KEY_NAME);
		printf("\n ==================================[Process Finished]==================================\n\n");
	}
}


void Students_Edit (Student_t *Head)
{
	u32 ID;
	u32 Option;

	if (Head==NULL)
	{
		printf("\n WARNING!!: The Registration Data Base is Empty [NO Students to Modify]\n");
		printf("\n ==================================[Process Finished]==================================\n\n");
		return;
	}

	else
	{
		printf(" PLS Enter Student ID: ");
		scanf(" %u",&ID);
		printf(" ----------------------------------\n");
		printf(" 1 >> Modify Name \n");
		printf(" 2 >> Modify ID\n");
		printf(" 3 >> Modify Birth Date\n");
		printf(" 4 >> Modify Address\n");
		printf(" 5 >> Modify Phone Number\n");
		printf(" 6 >> Modify The Whole Student Record\n");
		printf(" ----------------------------------\n");
		printf(" PLS Enter Your Option: ");
		scanf("%u",&Option);
		while (Head !=NULL)
		{
			if ((Head->ID)==ID)
			{
				switch(Option)
				{
					case 1:
						fflush(stdin);
						printf(" Modified Name: ");
						gets(Head->Name);
						break;

					case 2:
						printf(" Modified ID: ");
						scanf("%u",&(Head->ID));
						break;

					case 3:
						printf(" Modified Birth Date (D/M/Y): ");
						scanf("%d/%d/%d",&(Head->Date_of_Birth.Day),&(Head->Date_of_Birth.Month),&(Head->Date_of_Birth.Year));
						break;

					case 4:
						fflush(stdin);
						printf(" Modified Address: ");
						gets(Head->Address);
						break;

					case 5:
						printf(" Modified Phone Number: ");
						scanf("%s",&(Head->Phone_Number));
						break;

					case 6:
						fflush(stdin);
						printf(" Modified Name: ");
						gets(Head->Name);

						printf(" Modified ID: ");
						scanf("%u",&(Head->ID));

						printf(" Modified Birth Date (D/M/Y): ");
						scanf("%d/%d/%d",&(Head->Date_of_Birth.Day),&(Head->Date_of_Birth.Month),&(Head->Date_of_Birth.Year));

						fflush(stdin);
						printf(" Modified Address: ");
						gets(Head->Address);

						printf(" Modified Phone Number: ");
						scanf("%s",&(Head->Phone_Number));
						break;

					default:
						printf("\n ERROR!!: Invalid Modifing Option [Input Options: 1->7]..\n\n");
						printf("\n ==================================[Process Finished]==================================\n\n");
						return;
						break;
				}
				break;
			}
			Head=(Head->Ptr_Next);
		}
		printf("\n Name[%s]-->ID[%u] Modified Successfully..\n\n",(Head->Name),(Head->ID));
		printf("\n ==================================[Process Finished]==================================\n\n");
		return;
	}
}



void Students_Score (Student_t *Head)
{
	u32 ID;
	printf(" PLS Enter Student ID: ");
	scanf(" %u",&ID);
	
	if(Head==NULL)
	{
		printf("\n WARNING!!: The Registration Data Base is Empty [NO Students to Update Score]\n");
		printf("\n ==================================[Process Finished]==================================\n\n");
		return;
	}
	else
	{
		while (Head!=NULL)
		{
			if((Head->ID)==ID)
			{
				printf("\nPLS Enter The Updated Score: ");
				scanf(" %d",&(Head->Score));
				printf("\n The Score Of The Student [%s]-->ID[%u] Updated Successfully..\n\n",(Head->Name),(Head->ID));
				printf("\n ==================================[Process Finished]==================================\n\n");
				return;
			}
			
			Head=(Head->Ptr_Next);
		}
		printf("\n WARNING!!: The ID[%u] NOT Registered in The Registeration Data Base.. \n",ID);
		printf("\n ==================================[Process Finished]==================================\n\n");
	}
}


void Rank_Students (Student_t *Head)
{
	printf("\n ==================================[Computer Scince Score Sheet]==================================\n");

	/* If The Registration Data Base is Empty */
	if(Head==NULL)
	{
		printf("\n WARNING!!: The Registration Data Base is Empty [NO Students to Rank Score]\n");
		printf("\n ==================================[Process Finished]==================================\n\n");
		return;
	}

	/* If There is Just One Student Registered in The Registration Data Base */
	else if ((Head->Ptr_Next)==NULL)
	{
		printf("\n Only ONE Student Registered: Name[%s]\tID[%d]\tComputer Scince Score[%d]\n",(Head->Name),(Head->ID),(Head->Score));
		printf("\n ==================================[Process Finished]==================================\n\n");
	}

	else if((Head->Ptr_Next)!=NULL)
	{
		Students_Sort(Head,KEY_SCORE);
		printf("\n ==================================[Process Finished]==================================\n\n");
	}
}
