#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void create();
void login();
void transfer();
void main()
{
int choice;
char ch='y';
clrscr();
while(ch=='y'||ch=='Y')
{
clrscr();
printf("                        \t   BANKING.C");
printf("\nCHOOSE YOUR REQUIRED SERVICE");
printf("\n\n1.Create a new account\n\n2.Login into my account\n\n3.Exit");
printf("\n\nI would like to(1/2/3):- ");
scanf("%d",&choice);
switch(choice)
{
case 1:create();break;
case 2:login();break;
case 3:exit(1);break;
}
printf("\n\nDO YOU WANT TO CONTINUE ?(Y/N):-");
fflush(stdin);
scanf("%c",&ch);
}
getch();
}


void create()
{
char name[80];
char acno[11];
char psswd[6];
FILE *f1,*f2,*f3,*f4;
static int x=0;
int k;
x++;
clrscr();
printf("                        \t   BANKING.C");
printf("              \n\n\n\n\t\t\t   CREATE YOUR ACCOUNT");
switch(x)
{
case 1:
{
f1=fopen("1.txt","w");
f2=fopen("2.txt","w");
printf("\n\nEnter your name:- ");
fflush(stdin);
gets(name);
fflush(stdin);
printf("\nEnter your mobile number(10 charecters only):- ");
scanf("%s",acno);
fputs(acno,f1);
fputc('#',f1);
fflush(stdin);
printf("\nEnter a password to secure your account(6 charecters only):- ");
gets(psswd);
fputs(psswd,f1);
puts(psswd);
fflush(stdin);
k=0;
putw(k,f2);
fclose(f1);
fclose(f2);
}
clrscr();
printf("                        \t   BANKING.C");
printf("\n\n\nALL SETT!! CONGRATULATIONS ON SUCCESSFUL CREATION OF YOUR ACCOUNT");
printf("\n\n\nYOUR ACCOUNT DETAILS ARE:-");
printf("\n\nName:- %s",name);
printf("\n\nAccount Number:- %s",acno);
printf("\n\nAccount Bal:- INR 0");
printf("\n\n\nLOGIN TO ADD BALANCE INTO YOUR ACCOUNT");
break;
case 2:
{
f3=fopen("3.txt","w");
f4=fopen("4.txt","w");
printf("\nEnter your name:- ");
fflush(stdin);
gets(name);
fflush(stdin);
printf("\nEnter your mobile number(10 charecters only):- ");
scanf("%s",&acno);
fputs(acno,f3);
fputc('#',f3);
printf("\nEnter a password to secure your account(6 charecters only):- ");
fflush(stdin);
gets(psswd);
fputs(psswd,f3);
puts(psswd);
k=0;
putw(k,f4);
fclose(f3);
fclose(f4);
}
clrscr();
printf("                        \t   BANKING.C");
printf("\n\n\nALL SETT!! CONGRATULATIONS ON SUCCESSFUL CREATION OF YOUR ACCOUNT");
printf("\n\n\nYOUR ACCOUNT DETAILS ARE:-");
printf("\n\nName:- %s",name);
printf("\n\nAccount Number:- %s",acno);
printf("\n\nAccount Bal:- INR 0");
printf("\n\n\nLOGIN TO ADD BALANCE INTO YOUR ACCOUNT");
break;
}
}


void login()
{
FILE *f1,*f2,*f3,*f4;
int p,q,i=0,h,b,option;
long int g,amt,l;
char c[11],c1[6],ch,c2[11];
char acnum[11],passwd[10];
tag:
clrscr();
printf("           	             \t   BANKING.C");
printf("              \n\n\n\n\t\t\t   LOGIN INTO YOUR ACCOUNT");
f1=fopen("1.txt","r");
f3=fopen("3.txt","r");
printf("\n\n\nEnter Your Account Number:- ");
fflush(stdin);
gets(acnum);
while((ch=fgetc(f1))!='#')
{
c[i]=ch;
i++;
}
fflush(stdin);
c[10]='\0';
p=strcmp(acnum,c);
rewind(f1);
i=0;

if(p==0)
{
if(p==0)
{
printf("Enter Your Password:- ");
fflush(stdin);
gets(passwd);
fseek(f1,11,0);
i=0;
while((ch=fgetc(f1))!=EOF)
{
c1[i]=ch;
i++;
}
c1[6]='\0';
q=strcmp(passwd,c1);
if(q==0)
{
f2=fopen("2.txt","r");
while((h=getw(f2))!=EOF)
{
printf("\n\nYour current AC Balance is:- %d",h);
g=h;
l=g;
}
fclose(f1);
fclose(f2);
here:
printf("\n\nChoose Your Required Service:-\n1.Deposit\n2.Withdrawl\n3.Transfer\n4.LogOut\n5.Exit");
printf("\n\nEnter Your Choice:- ");
fflush(stdin);
scanf("%d",&option);
switch(option)
{
case 1: {
	clrscr();
	printf("                        \t   BANKING.C");
	printf("\n\nYour current AC Balance is:- INR %ld",g);
	printf("\n\nAmount to be Deposited(in INR ONLY):- ");
	scanf("%ld",&amt);
	fcloseall();
	g=g+amt;
	l=g;
	printf("\n\n\nDEPOSIT SUCCESSFUL!!!");
	printf("\n\nYour Updated AC Balance is:- %ld",g);
	f2=fopen("2.txt","w");
	putw(g,f2);
	fflush(stdin);
	fcloseall();
	} goto here;

case 2: {
	clrscr();
	printf("                        \t   BANKING.C");
	printf("\n\nYour current AC Balance is:- INR %ld",g);
	printf("\n\nAmount to Withdraw(in INR ONLY):- ");
	scanf("%ld",&amt);
	fcloseall();
	l=l-amt;
	if(l>=5000)
	{
	g=g-amt;
	printf("\n\n\nWITHDRAWL SUCCESSFUL!!!");
	printf("\n\nYour Updated AC Balance is:- %ld",g);
	l=g;
	f2=fopen("2.txt","w");
	putw(g,f2);
	fflush(stdin);
	}
	else
	{
	printf("\n\nWITHDRAWL UNSUCCESSFUL DUE TO LOW BALANCE");
	printf("\n\nYour current AC balance is:- %ld",g);
	}
	fcloseall();
	} goto here;
case 3: transfer();break;
case 4:login();break;
default: exit(0);
}
}
}
}
while((ch=fgetc(f3))!='#')
{
c2[i]=ch;
i++;
}
fflush(stdin);
c2[10]='\0';
q=strcmp(acnum,c2);
rewind(f3);
if(q==0)
{
if(q==0)
{
printf("Enter Your Password:- ");
fflush(stdin);
gets(passwd);
fseek(f3,11,0);
i=0;
while((ch=fgetc(f3))!=EOF)
{
c1[i]=ch;
i++;
}
c1[6]='\0';
q=strcmp(passwd,c1);
if(q==0)
{
f3=fopen("4.txt","r");
while((h=getw(f3))!=EOF)
{
printf("\n\nYour current AC Balance is:- %d",h);
g=h;
l=g;
}
fclose(f3);
fclose(f4);
there:
printf("\n\nChoose Your Required Service:-\n1.Deposit\n2.Withdrawl\n3.Transfer\n4.LogOut\n5.exit");
printf("\n\nEnter Your Choice:- ");
fflush(stdin);
scanf("%d",&option);
switch(option)
{
case 1: {
	clrscr();
	printf("                        \t   BANKING.C");
	printf("\n\nYour current AC Balance is:- INR %ld",g);
	printf("\n\nAmount to be Deposited(in INR ONLY):- ");
	scanf("%ld",&amt);
	fcloseall();
	g=g+amt;
	l=g;
	printf("\n\n\nDEPOSIT SUCCESSFUL!!!");
	printf("\n\nYour Updated AC Balance is:- %ld",g);
	f4=fopen("4.txt","w");
	putw(g,f4);
	fflush(stdin);
	fcloseall();
	} goto there;

case 2: {
	clrscr();

	printf("\n\nYour current AC Balance is:- INR %ld",g);
	printf("\nAmount to Withdraw(in INR ONLY):- ");
	scanf("%ld",&amt);
	fcloseall();
	l=l-amt;
	if(l>=5000)
	{
	g=g-amt;
	printf("\n\n\nWITHDRAWL SUCCESSFUL!!!");
	printf("\n\nYour Updated AC Balance is:- %ld",g);
	l=g;
	f4=fopen("4.txt","w");
	putw(g,f4);
	fflush(stdin);
	}
	else
	{
	printf("\n\nWITHDRAWL UNSUCCESSFUL DUE TO LOW BALANCE");
	printf("\n\nYour current AC balance is:- %ld",g);
	}
	fcloseall();
	} goto here;
case 3: transfer();break;
case 4: goto tag;
default: exit(0);
}
}
}
}
}
void transfer()
{
FILE *f1,*f2,*f3,*f4;
int i=0,m,m1,n,n1,h1,g1,l1,k;
long int amnt,y,z,d1;
char acn[11],a[11],a1[11],ch,pswd[7],p1[7],p2[7];
clrscr();
printf("                        \t   BANKING.C");
printf("\n\nTo Account Number:- ");
fflush(stdin);
gets(acn);
f1=fopen("1.txt","r");
f3=fopen("3.txt","r");
while((ch=fgetc(f1))!='#')
{
a[i]=ch;
i++;
}
fflush(stdin);
a[10]='\0';
m=strcmp(a,acn);
rewind(f1);
i=0;
while((ch=fgetc(f3))!='#')
{
a1[i]=ch;
i++;
}
fflush(stdin);
a1[10]='\0';
n=strcmp(a1,acn);
rewind(f3);
fclose(f1);
fclose(f3);
if(m==0||n==0)
{
f1=fopen("1.txt","r");
f3=fopen("3.txt","r");
if(m==0)
{
f2=fopen("2.txt","r");
}
else if(n==0)
{
f4=fopen("4.txt","r");
}
printf("Transfer Amount:- ");
fflush(stdin);
scanf("%ld",&amnt);
clrscr();
printf("                        \t   BANKING.C");
printf("\n\nEnter Your Password to complete Transaction:- ");
fflush(stdin);
gets(pswd);
fseek(f1,11,0);
fflush(stdin);
i=0;
while((ch=fgetc(f1))!=EOF)
{
p2[i]=ch;
i++;
}
p2[6]='\0';
n1=strcmp(pswd,p2);
if(n1==0)
{
f2=fopen("2.txt","r");
while((h1=getw(f2))!=EOF)
{
g1=h1;
l1=g1;
}
fclose(f2);
d1=l1-amnt;
if(n1==0)
{
if(d1>=5000)
{
l1=l1-amnt;
f2=fopen("2.txt","w");
putw(l1,f2);
fclose(f2);
if(n==0)
{
f4=fopen("4.txt","r");
while((y=getw(f4))!=EOF)
{
z=y;
}
fclose(f4);
f4=fopen("4.txt","w");
z=z+amnt;
putw(z,f4);
fclose(f4);
printf("\n\nTRANSFER SUCCESSFUL!!!!!!");
}

}
else
{
printf("\n\nTransfer Unsuccessful Due To Low Balance! or WRONG PASSWORD :-(");
printf("\n\n\n\n PRESS ANY KEY AND THEN ENTER to exit!!!");
scanf("%d",&k);
exit(2);
}
}
}
fseek(f3,11,0);
fflush(stdin);
i=0;
while((ch=fgetc(f3))!=EOF)
{
p1[i]=ch;
i++;
}
p1[6]='\0';
m1=strcmp(pswd,p1);
if(m1==0)
{
f4=fopen("4.txt","r");
while((h1=getw(f4))!=EOF)
{
g1=h1;
l1=g1;
}
fclose(f4);
d1=l1-amnt;
if(m1==0)
{
if(d1>=5000)
{
f4=fopen("4.txt","w");
l1=l1-amnt;
putw(l1,f4);
fclose(f4);
if(m==0)
{
f2=fopen("2.txt","r");
while((y=getw(f2))!=EOF)
{
z=y;
}
fclose(f2);
f2=fopen("2.txt","w");
z=z+amnt;
putw(z,f2);
fclose(f2);
printf("\n\nTRANSFER SUCCESSFUL!!!!!!");
}
}
else
{
printf("\n\nTransfer Unsuccessful Due To Low Balance!! :-( or WRONG PASSWORD");
printf("\n\n\n\n PRESS ANY KEY AND THEN ENTER to exit!!!");
scanf("%d",&k);
}
}
}
}
}