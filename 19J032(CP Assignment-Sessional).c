/*******************************************************************************************************************
Created By: Upamanyu Dixit (Github ID - UpamanyuDixit)
Roll no   : 19J032. (J-Div)
Institute : Institute of Technology, Nirma University.
Program
Definition: Write a program to count the number of words, Alphabets, digits, spaces and special characters in a file.
            Program should take the name of file from user on which you want perform above operations.
            Write the above counts in table format in new file.

******************************************************************************************************************/



/******************************************************************************************************************
                                                HEADER FILES
******************************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<windows.h>

/******************************************************************************************************************
                                        FUNCTIONS AND GLOBAL VARIABLES
******************************************************************************************************************/

void enterdata(void);
void showdata(void);
void end(void);
void menu(void);
int calc(char file[50]);

FILE *fp1,*fp2;
int al=0,wo=0,sp=0,sc=0;

int main()
{
        system("CLS");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		char i[]={"\n\n\t\t\t   WELCOME TO SESSIONAL ASSIGNMENT"};
		for(int k=0;k<strlen(i);k++)
		{
			printf("%c",i[k]);
			Sleep(100);
		}
		printf("\n\n\n\n\n\t\t\t\t       Made By");
		Sleep(1000);
		char u[]="\n\n\n\n\n\t\t\t\tUPAMANYU DIXIT (19J032)";
		for(int k=0;k<strlen(u);k++)
		{
			printf("%c",u[k]);
			Sleep(100);
		}
		printf("\n\n\n\n\n\t\t\t\t   [ J - Division ]\n\n\n");
		int l=0;
		srand(time(0));
		while(l==0)
		{
			for(int b=0;b<15;b++)
			{
				int l=rand();
				Beep(l,200);
			}
			l++;
		}
		printf("________________________");
		printf("Please Press Any Key To Proceed_______________________");
		getch();
        menu();
}

/******************************************************************************************************************
                                            MENU( Contains menu)
*******************************************************************************************************************/

void menu()
{
        system("CLS");
        system("COLOR F0");
        int c;
        printf("*******************************************************************************");
        printf("                                       M E N U");
        printf("\n*******************************************************************************");
        printf("\n\n\t\t1. Entering data into the file.");
        printf("\n\t\t2. Viewing the data in a tabular format.");
        printf("\n\t\t3. Exit.");
        printf("\n\n\n\t\t\tENTER THE CHOICE: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: enterdata();
                    break;
            case 2: showdata();
                    break;
            case 3: end();
                    break;
            default:main();
                    break;
        }
}

/******************************************************************************************************************
                    Function : Enterdata() : Function used to append and enter data into file.
*******************************************************************************************************************/

void enterdata()
{
    char filename[50],ofname[50],str[100],ch;
    system("CLS");
    system("COLOR B5");
    printf("                     F I L E - M E N U ");
    printf("\n\n\tEnter the name of the file:");
    fflush(stdin);
    scanf("%[^\n]s", filename);

    fp2=fopen("fname.txt","w+");
    fscanf(fp2,"%s",ofname);
    rename(ofname,filename);
    fprintf(fp2,filename);
    fclose(fp2);

    fp1=fopen(filename,"a");
    printf("\n\tNow Enter the data into the file [100 characters]: ");
    fflush(stdin);
    scanf("%[^\n]",str);
    fprintf(fp1,str);
    fclose(fp1);
    calc(filename);
}

/******************************************************************************************************************
                    Function : showdata() : Function used to display the details in the file.
*******************************************************************************************************************/

void showdata()
{
    system("CLS");
    system("COLOR E1");
    printf("-------------------------------------------------------------------------------");
    printf("                        C A L C U L A T E D -- D E T A I L S");
    printf("\n-------------------------------------------------------------------------------");
    printf("\n\n\t____________________________________________________________");
    printf("\n\tNo. of words\t\t\t|\t%d",wo);
    printf("\n\t____________________________________________________________");
    printf("\n\tNo. of Alphabets\t\t|\t%d",al);
    printf("\n\t____________________________________________________________");
    printf("\n\tNo. of Spaces\t\t\t|\t%d",sp);
    printf("\n\t____________________________________________________________");
    printf("\n\tNo. of Special Characters\t|\t%d",sc);
    printf("\n\t____________________________________________________________");
    getch();
    menu();
}

/******************************************************************************************************************
                    Function : calc() : Function used to calculate various aspects in the file.
*******************************************************************************************************************/


int calc(char file[])
{
    system("CLS");
    char ch;
    fp1=fopen(file,"r");
    while((ch = fgetc(fp1)) != EOF)
	{
		if(ch==' ')
		{
			sp++;
		}
        else if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
		{
			al++;
 		}
 		else
        {
            sc++;
        }
        printf("%c",ch);
	}
	fclose(fp1);
	wo=sp+1;
	menu();
}

/******************************************************************************************************************
                    Function : End() : Function used to Make the Ending screen.
*******************************************************************************************************************/

void end()
{
    system("CLS");
    system("COLOR CF");
    printf("\n\n\n\n\n\t\t\t\tTHANX FOR VIEWING IT.");
    printf("\n\t\t\t\tUPAMANYU DIXIT (19J032)\n\n\n\n");

}
