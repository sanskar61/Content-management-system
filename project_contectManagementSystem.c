#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>
#include "pass.h"
#include<windows.h>
struct ContactManagement{
	char name[15];
	char phoneNumber[11];
	char gmail[30];
	char dob[11];
}c;
 void gotoxy(short x, short y);
 void addDetail();
 void showAllDetails();
 void searchDetail();
 void updateDetails();
 void deleteDetail();
 int main()
 {
 	system("color 74");
 	int r;
 	gotoxy(30,13);
 	printf("Welcome to the Contect Management System");
 	gotoxy(38,16);
 	printf("Please Wait");
 	gotoxy(49,16);
 	for(r=0;r<=4;r++)
 	{
 		printf("%c",46);
 		Sleep(1000);
	 }
	 system("cls");
 	system("color 4");
 	gotoxy(30,13);
 	printf("Enter your password : ");
 	gotoxy(52,13);
    int ich;
    r=0;
	char psw[20],ch;
	while(ch!=13 && r<20)
	{
		ch=getch();
		if(ch!=13 && ch!=32 && ch!=14 && ch!=15 )
		{
			psw[r++]=ch;
			printf("*");
		}
	}
	psw[r]='\0';
	
 	if(!strcmp(psw,name))
 	{
 	while(1)
 	{
 		system("color f1");
 		
 		system("cls");
 		gotoxy(30,2);
 		printf("--------------------------------------------------");
 		gotoxy(30,3);
		 printf("| 1. | Add Detail \t\t\t       |");
 		gotoxy(30,4);
 		printf("--------------------------------------------------");
		 gotoxy(30,5);
		 printf("| 2. | Show All Details  \t\t\t       |");
		 gotoxy(30,6);
 		printf("--------------------------------------------------");
 		gotoxy(30,7);
		 printf("| 3. | Search Detail    \t\t\t       |");
		 gotoxy(30,8);
 		printf("--------------------------------------------------");
 		gotoxy(30,9);
		 printf("| 4. | Update Detail    \t\t\t       |");
		 gotoxy(30,10);
 		printf("--------------------------------------------------");
 		gotoxy(30,11);
		 printf("| 5. | Delete Detail    \t\t\t       |");
		 gotoxy(30,12);
 		printf("--------------------------------------------------");
 		gotoxy(30,13);
		 printf("| 6. | Exit     \t\t\t\t       |");
		 gotoxy(30,14);
 		printf("--------------------------------------------------");
 		gotoxy(30,17);
		 printf("Enter your choice:");
 		gotoxy(49,17);
		 scanf("%d",&ich);
 		system("cls");
 		switch(ich)
 		{
 			case 1:
 				fflush(stdin);
 				addDetail();
 				break;
 			case 2:
 				showAllDetails();
 				break;
 			case 3:
 				searchDetail();
 				break;
 			case 4:
 				updateDetails();
 				break;
 			case 5:
 				deleteDetail();
 				break;
 			case 6:
 				exit(0);
 				default:
 					printf("wrong choice");			
 				
		}//switch closed
	}//while closed
}
}//main closed


void addDetail()
{
	
	FILE *fptr;
	fptr=fopen("D:\\contact.txt","a");
	//read data from console(keyboard) into memory of s(rno,name,marks)
	gotoxy(30,13);
	printf("Enter detail:");
	gotoxy(30,14);
	printf("Enter Name:");
	gotoxy(41,14);
//	fflush(stdin);
	gets(c.name);
	gotoxy(30,15);
	printf("Enter Phone Number:");
	gotoxy(49,15);
	gets(c.phoneNumber);
	gotoxy(30,16);
	printf("Enter gmail Id:");
	gotoxy(45,16);
	gets(c.gmail);
	gotoxy(30,17);
	printf("Enter Date of birth:");
	gotoxy(50,17);
	gets(c.dob);
	//fwrite((char*)&strucvar,1,sizeof(structvar),fptr);
	fwrite((char*)&c,1,sizeof(c),fptr);
	fclose(fptr);
}
 
void showAllDetails()
{
	
	FILE *fptr;
	fptr=fopen("D:\\contact.txt","r");
	//read data from console(keyboard) into memory of s(rno,name,marks)
	
	//fwrite((char*)&strucvar,1,sizeof(structvar),fptr);
	while(fread((char*)&c,1,sizeof(c),fptr))
	{
		printf("\nDetail of people:\n");
		printf("\nName=>%s",c.name);
		printf("\nPhone number=>%s",c.phoneNumber);
		printf("\ngmail id=>%s",c.gmail);
		printf("\nDate of birth=>%s",c.dob);
		
	}
	printf("\n");
	system("pause");
	fclose(fptr);
}

void searchDetail()
{
	FILE *fptr;
	fptr=fopen("D:\\contact.txt","r");
	char sname[15];
	printf("Enter name for search:");
	scanf("%s",&sname);
	int f=0;
	//read data from file to memory of c(name,id,gmail,dob,phone no)
	//fread((char*)&strucvar,1,sizeof(structvar),fptr);
	while(fread((char*)&c,1,sizeof(c),fptr)) //28byte while(28(nonzero(true))
	{
	    if(!strcmp(sname,c.name))
	    {
			printf("\nDetail of people:\n");
			printf("\nName=>%s",c.name);
		    printf("\nPhone number=>%s",c.phoneNumber);
		    printf("\ngmail id=>%s",c.gmail);
	     	printf("\nDate of birth=>%s",c.dob);
		
			f=1; //
			break;
		}
	}
	if(f==0) //f(1)==0 (false)
		printf("Detail not found");
	
	printf("\n");
	system("pause");
		fclose(fptr);

}
void updateDetails()
{FILE *fptr1,*fptr2;
	
	fptr1=fopen("D:\\contact.txt","r");
	fptr2=fopen("D:\\temp.txt","w");
	
	char sname[15];
	gotoxy(30,12);
	printf("Enter name for search:");
	gotoxy(52,12);
	scanf("%s",&sname);
	int f=0;
	//read data from file to memory of 
	//fread((char*)&strucvar,1,sizeof(structvar),fptr);
	while(fread((char*)&c,1,sizeof(c),fptr1)) //28byte while(28(nonzero(true))
	{
	    if(!strcmp(sname,c.name))
	    {
		
			//new input---new file write
			gotoxy(30,13);
	printf("Detail:");
	gotoxy(30,14);
	printf("Enter Name:");
	gotoxy(41,14);
	fflush(stdin);
	gets(c.name);
	gotoxy(30,15);
	printf("Enter Phone Number:");
	gotoxy(49,15);
	gets(c.phoneNumber);
	gotoxy(30,16);
	printf("Enter gmail Id:");
	gotoxy(45,16);
	gets(c.gmail);
	gotoxy(30,17);
	printf("Enter Date of birth:");
	gotoxy(50,17);
	gets(c.dob);
		
			//write data into new file (fptr2)
			fwrite((char*)&c,1,sizeof(c),fptr2);
			f=1; //
			
		}
		else
		{
			//these are correct without new input write into file
			
			fwrite((char*)&c,1,sizeof(c),fptr2);
		}
	}
	if(f==0) //f(1)==0 (false)
		printf("Detail not found");
		getch();
		fclose(fptr1);
		fclose(fptr2);
		remove("D:\\contact.txt");
		rename("D:\\temp.txt","D:\\contact.dat");
		

}
void deleteDetail()
{
	FILE *fptr1,*fptr2;
	fptr1=fopen("D:\\contact.txt","r");
	fptr2=fopen("D:\\temp.txt","w");
	
	char sname[15];
	gotoxy(30,13);
	printf("Enter name for search:");
	gotoxy(52,13);
	scanf("%s",sname);
	int f=0;
	//read data from file to memory of
	//fread((char*)&strucvar,1,sizeof(structvar),fptr);
	while(fread((char*)&c,1,sizeof(c),fptr1)) //28byte while(28(nonzero(true))
	{
	    if(!strcmp(sname,c.name))
	    {
		
			f=1; // except this write all into new file
			
		}
		else
		{
			//write all which you dont want to delete into new file
			
			fwrite((char*)&c,1,sizeof(c),fptr2);
		}
	}
	if(f==0) //f(1)==0 (false)
	{
		gotoxy(30,14);
		printf("Detail not found");
	}
		else
		{
			gotoxy(30,14);
		printf("Contect Deleted");
	    }
		getch();
		fclose(fptr1);
		fclose(fptr2);
		remove("D:\\contact.txt");
		rename("D:\\temp.txt","D:\\contact.txt");

}
void gotoxy(short x, short y)                                                          
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}