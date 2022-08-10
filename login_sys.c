#include<stdio.h>
#include<string.h>
#include<stdlib.h>
FILE *fp,*fp1;

struct user_data
{
	char username[20],first[10],last[10],email[30],ph_no[10],passwd[10];
	
};

void title()
{
	printf("---*******************************************************************************************************---\n");
	printf("---********************************||Registration & Login System||****************************************---\n");
	printf("---*******************************************************************************************************---\n");
	printf("1-Register\n2-Login\n3-Forgot Credentials\n4-Exit\n ");
}
void regi()
{
	struct user_data user;
	char un1[20],pass[10];
	fp=fopen("Data.txt","a+");
re:
	system("cls");
	printf("...............Enter Data..............\n");
	printf("Enter Username : ");
	scanf("%s",user.username);
	fp1=fopen("Data.txt","r+");
	if(fp1==NULL)
	{
		printf("Error....File not found.....\n");
		return;
	}
	while(!feof(fp1))
	{
		fscanf(fp1,"%s%*[^\n]",un1);
		if(!strcmp(user.username,un1))
		{
			printf("Username already present....Try Again with different username....\n");
			getch();
			goto re;
		}
	}
	fclose(fp1);
	printf("Enter First Name : ");
	scanf("%s",user.first);
	printf("Enter Last Name : ");
	scanf("%s",user.last);
	printf("Enter Phone no. (10 characters limit) : ");
	scanf("%s",user.ph_no);
	printf("Enter email id : ");
	scanf("%s",user.email);
	printf("Enter Password (10 characters limit) : ");
	scanf("%s",user.passwd);
	printf("Enter password again : ");
	scanf("%s",pass);
	if(strcmp(pass,user.passwd))
	{
		printf("Password does not match.....Try Again.....\n");
		getch();
		goto re;
		
	}
	if(fp==NULL)
	{
		printf("Error........\n");
	}
	else
	{
		fprintf(fp,"%s %s %s %s %s %s\n",user.username,user.first,user.last,user.ph_no,user.email,user.passwd);
		fclose(fp);
	}
}

void login()
{
	struct user_data user;
	int i,j;
	char un1[20],pass[10],ch;
	system("cls");	
	printf("Enter the username : ");
	scanf("%s",un1);
	printf("Enter Password : ");
	i=0;
	while(1)
	{
		ch=getch();
		if(ch==13||ch==9)
		{
			pass[i]='\0';
			break;
		}
		else if(ch==8)
		{
			if(i>0)
			{
				i--;
				printf("\b \b");
			}
		}
		else
		{
			pass[i++]=ch;
			printf("* \b");
		}
	}
	i=0;j=0;
	fp1=fopen("Data.txt","r+");
	if(fp1==NULL)
	{
		printf("Error....File not found.....\n");
	}
	while(!feof(fp1))
	{
		fscanf(fp1,"%s %s %s %s %s %s",user.username,user.first,user.last,user.ph_no,user.email,user.passwd);
		if(!strcmp(user.username,un1))
		{
			i++;	
		}
		if(!strcmp(user.passwd,pass))
		{
			j++;
		}
		if(i>0&&j>0)
		{
			break;
		}
		else
		{
			i=j=0;
		}
	}
	if(i==0 && j==0)
	{
		printf("\nUsername and password not matching....Try Again with correct username and password....\n");
		getch();
		return;	
	}
	fclose(fp1);
	system("cls");	
	printf("\n\n\t\tHello %s Welcome....\n\n\n",un1);
}

void forget()
{
	struct user_data user;
	int i;
	char un1[20];
	system("cls");	
	printf("Enter the username : ");
	scanf("%s",un1);
	i=0;
	fp1=fopen("Data.txt","r+");
	if(fp1==NULL)
	{
		printf("Error....File not found.....\n");
	}
	while(!feof(fp1))
	{
		fscanf(fp1,"%s %s %s %s %s %s",user.username,user.first,user.last,user.ph_no,user.email,user.passwd);
		if(!strcmp(user.username,un1))
		{
			i++;	
			break;
		}
	}
	if(i==0)
	{
		printf("\nUsername not matching....Try Again with correct username....\n");
		getch();
		return;	
	}
	fclose(fp1);
	system("cls");	
	printf("\n\t\tHello %s Welcome....\n\n",un1);
	printf("\tYour details are .... \n\n\t\tUsername : \t%s\n\t\tFirstName : \t%s\n\t\tLastName : \t%s\n\t\tPhone No. : \t%s\n\t\tEmail : \t%s\n\t\tPassword : \t%s\n\t\t",user.username,user.first,user.last,user.ph_no,user.email,user.passwd);
}

int main()
{
	int c,i;
	re :
	system("cls");
	title();
	printf("Enter your choice :");
	scanf("%d",&c);
	switch(c)
	{
		case 1 :
			regi();
			break;
		case 2 :
			login();
			break;
		case 3 :
			forget();
			break;
		case 4 :
			return 0;
		default :
		printf("Wrong option\n");
	}
	printf("Press Any Key to continue...");
	getch();
	goto re;
}
