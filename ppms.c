#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>

void password();
void password_first();
void password_second();

void adminmainmenu();
void membermainmenu();
void addmember(void);
void deletemember(void);
void searchmember(void); 
void viewmember(void);
void editmember(void);


void msearchmember(void);
void mviewmember(void);
void addevent(void);
void vieweevent(void);
void deleteevent(void);

void passwordinfo();
void createpassword();
void deletepassword(); 
void viewpassword(); 
int t(void);

///list of global files
FILE *fp,*ft;
COORD coord = {0, 0}; //WIND 

int fm;

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //handle of console's standard output device,
}

void delay(int number_of_seconds)
{ // Converting time into milli_seconds
    int milli_seconds = 500 * number_of_seconds;
    // Storing start time
    clock_t start_time = clock();
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void returnfunc(void){{
    gotoxy(25,25);
printf("Press ENTER to return the main menu");
}
if(getch()==13)
adminmainmenu();
}

void mreturnfunc(void){{
    gotoxy(25,25);
printf("Press ENTER to return the main menu");
}
if(getch()==13)
membermainmenu();
}

int t(void){
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));

return 0 ;
}

struct member{
    int ID;
    char name[20];
    char add[20];
    char dept[20];
    long long int Phone_no;

    int no;
    char title[20];
    char z[100];
    char date[20];

    int userid;
    char code[20];

};

struct member stu;

int main(){
    password();
    getch();
    return 0;
}

void adminmainmenu(){
    int choice;
    system("cls");
    gotoxy(20,3);
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd MAIN MENU \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(20,5);printf("1. Add Members\n");
gotoxy(20,7);printf("2. Delete Members\n");
gotoxy(20,9);printf("3. Search Members\n");
gotoxy(20,11);printf("4. View Members\n");
gotoxy(20,13);printf("5. Edit Members Information\n");
gotoxy(20,15);printf("6. Register Password\n");
gotoxy(20,17);printf("7. Close Application\n");
gotoxy(20,19);printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(20,20);t();
gotoxy(20,25);
printf("Enter Your Choice: ");
switch(getch()){
case '1':
addmember();
break;
case '2':
deletemember();
break;
case '3':
searchmember();
break;
case '4':
viewmember();
break;
case '5':
editmember();
case '6':
passwordinfo();
case '7':{
main();
}
default:{
gotoxy(20,22);printf("Wrong!!Correct Option");
if (getch())
adminmainmenu();

}
}
}

void addmember(void){
    top:
system("cls");
int k =0;
      gotoxy(26,2);
     printf("\xcd\xcd\xcd\xcd Add MEMBER INFO \xcd\xcd\xcd");
    int print = 25;
    FILE *fp;
    fp = fopen("record_nxt.txt","ab+");
    if(fp == NULL){
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);

    }
    else

    {
        gotoxy(print,6);printf("Member ID: ");scanf("%d",&stu.ID);
        fflush(stdin);
        gotoxy(print,8);printf("Name: ");gets(stu.name);
        gotoxy(print,10);printf("Address: ");gets(stu.add);
        gotoxy(print,12);printf("dept. name: ");gets(stu.dept);
        
        gotoxy(print,14);printf("Phone Number: ");scanf("%lli",&stu.Phone_no);
        int o = stu.Phone_no;
        while (o > 0) {
            o = o /10;
            k++;
        }
        if (k == 10) {
            fwrite(&stu, sizeof(stu), 1, fp);
        }
        else {
            printf("phone number you entered is invalid number. it must be 10 digit try again");
        if(getch()==13)
        goto top;
        }
        }
    fclose(fp);
    gotoxy(40,17); printf("The record is sucessfully added");
     gotoxy(40,18);printf("Save any more Y/N");
    if(getch()=='n')
    adminmainmenu();
    else
    system("cls");
    addmember();
}

void deletemember( ){
system ("cls");
gotoxy(26,2);
     printf("\xcd\xcd\xcd\xcd Delete MEMBER  \xcd\xcd\xcd");

int d;
char another='y';
while(another=='y')
{
    system("cls");
    gotoxy(26,2);
     printf("\xcd\xcd\xcd\xcd Delete MEMBER  \xcd\xcd\xcd");
gotoxy(10,5);
printf("Enter the Member ID to  delete:");
scanf("%d",&d);
fp=fopen("record_nxt.txt","rb+");
rewind(fp);
while(fread(&stu,sizeof(stu),1,fp)==1)
{
if(stu.ID==d)
{
gotoxy(10,8);
printf("Member name is %s",stu.name);
gotoxy(10,9);
fm='Z';
}
}
if(fm!='Z')
{
gotoxy(10,10);
printf("No record is found in LIST");
if(getch())
adminmainmenu();
}
if(fm=='Z')
{
gotoxy(10,7);
printf("The Member is available");
gotoxy(10,10);
printf("Do you want to delete it?(Y/N):");
if(getch()=='y')
{
ft=fopen("test.txt","wb+");  //temporary file for delete
rewind(ft);
rewind(fp);
while(fread(&stu,sizeof(stu),1,fp)==1)
{
if(stu.ID!=d)
{

fwrite(&stu,sizeof(stu),1,ft); //write all in tempory file except that
}                              //we want to delete
}
fclose(ft);
fclose(fp);
remove("record_nxt.txt");
rename("test.txt", "record_nxt.txt"); //copy all item from temporary file to fp except that  //we want to delete
if(fm=='Z')
{
gotoxy(10,10);
printf("The record is sucessfully deleted");
gotoxy(10,11);
printf("Delete another record?(Y/N)");
}
}
else
adminmainmenu();
fflush(stdin);
another=getch();
}
}
gotoxy(10,15);
adminmainmenu();
}

void searchmember(void){
system("cls");
int s;
gotoxy(10,3);
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd SEARCH MEMBER \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(10,5);
printf("Enter the Member ID to  search:");
scanf("%d",&s);
fp=fopen("record_nxt.txt","rb+");
rewind(fp); ///reposition file pointer to sream's beggining
while(fread(&stu,sizeof(stu),1,fp)==1)
{
if(stu.ID==s)
{
gotoxy(10,7);
printf("The Member is available");

gotoxy(10,9);
printf("ID: %d",stu.ID);
gotoxy(10,10);
printf("Name: %s",stu.name);
gotoxy(10,11);
printf("ADress: %s",stu.add);
gotoxy(10,12);
printf("Dept. : %s",stu.dept);
gotoxy(10,13);
printf("Phone nO: %lli",stu.Phone_no);

fm='Z';
}
}
if(fm!='Z')
{
gotoxy(10,10);
printf("No record is found in LIST");
if(getch())
adminmainmenu();
}

{
gotoxy(10,9);
printf("");
fclose(fp);
returnfunc();
getch();
}}

void viewmember(void){

system("cls");

FILE *fp;
int i=0,j;
system("cls");
gotoxy(15,1);
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd Members List \xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(2,3);
printf(" MEM_ID    MEMBER NAME    ADDRESS     DEPT      PHONE_NO    ");
j=5;
fp=fopen("record_nxt.txt","rb");
while(fread(&stu,sizeof(stu),1,fp)==1)
{
gotoxy(3,j);
printf("%d",stu.ID);
gotoxy(14,j);
printf("%s",stu.name);
gotoxy(28,j);
printf("%s",stu.add);
gotoxy(40,j);
printf("%s",stu.dept);
gotoxy(50,j);
printf("%lli",stu.Phone_no);
gotoxy(69,j);
printf("\n\n");
j++;
i=i+1;
}
gotoxy(3,25);
printf("Total Members =%d\n",i);
fclose(fp);
gotoxy(35,25);
returnfunc();
getch();
}

void editmember(void){
system("cls");

int s,print=37;
gotoxy(15,3);
printf("\xcd\xcd\xcd\xcd\xcd\xcd Edit MEMBER info \xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(10,5);
printf("Enter the Member ID to edit:");
scanf("%d",&s);
fp=fopen("record_nxt.txt","rb+");
while(fread(&stu,sizeof(stu),1,fp)==1)
{
if(stu.ID==s)
{

gotoxy(10,7);
printf("The Member is available");
        fflush(stdin);
        gotoxy(print,12);printf("Name: ");gets(stu.name);
        gotoxy(print,14);printf("Address: ");gets(stu.add);
        gotoxy(print,16);printf("dept. name: ");gets(stu.dept);
        gotoxy(print,18);printf("Phone Number: ");scanf("%lli",&stu.Phone_no);
        fseek(fp, -sizeof(stu), SEEK_CUR);
        fwrite(&stu,sizeof(stu), 1, fp);
        gotoxy(print,22);printf("The record is modified");

fm=1;
break;
}
}
if(fm!=1)
{
gotoxy(10,10);
printf("No record is found in LIST");
if(getch())
adminmainmenu();
}

fclose(fp);

gotoxy(37,22);
returnfunc();
getch();
}

void passwordinfo(){
    int choice;
    system("cls");
    gotoxy(20,3);
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd MAIN MENU \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(20,5);printf("1. Create password\n");
gotoxy(20,7);printf("2. Delete password\n");
gotoxy(20,9);printf("3. View password\n");
gotoxy(20,11);printf("4. go to mainmenu\n");
gotoxy(20,13);printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(20,14);
gotoxy(20,19);
printf("Enter Your Choice: ");
switch(getch()){
case '1':
createpassword(); 
break;
case '2':
deletepassword(); 
break;
case '3':
viewpassword(); 
break;
case '4':{
system("cls");
gotoxy(16,3);
adminmainmenu();
exit(0);
}
default:{
gotoxy(20,22);printf("Wrong!!Correct Option");
if (getch())
passwordinfo();

}}}

void createpassword(void){
    system("cls");

      gotoxy(26,2);
     printf("\xcd\xcd\xcd\xcd ADD PASSWORD INFO \xcd\xcd\xcd");
    int print = 25;
    FILE *fp;
    fp = fopen("record_paa.txt","ab+");
    if(fp == NULL){
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);

    }
    else

    {
        gotoxy(print,6);printf("User ID: ");scanf("%d",&stu.userid);
        fflush(stdin);
        gotoxy(print,8);printf("Password: ");gets(stu.code);
        fwrite(&stu, sizeof(stu), 1, fp);
    }
    fclose(fp);
    gotoxy(40,17); printf("The record is sucessfully added");
     gotoxy(40,18);printf("Save any more Y/N");
    if(getch()=='n')
    passwordinfo();
    else
    system("cls");
    createpassword();
}

void viewpassword(){
    system("cls");

FILE *fp;
int i=0,j;
system("cls");
gotoxy(15,1);
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd PASSWORD LIST \xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(2,2);
printf(" USER ID   PASSWORD    ");
j=3;
fp=fopen("record_paa.txt","rb");
while(fread(&stu,sizeof(stu),1,fp)==1)
{
gotoxy(3,j);
printf("%d",stu.userid);
gotoxy(14,j);
printf("%s",stu.code);
gotoxy(69,j);
printf("\n\n");
j++;
i=i+1;
}
gotoxy(3,25);
printf("\nTotal Password =%d\n",i);
fclose(fp);
gotoxy(35,25);
if(getch()==13)
 passwordinfo();
getch();
    
}

void deletepassword( ){
system ("cls");
gotoxy(26,2);
     printf("\xcd\xcd\xcd\xcd Delete Password  \xcd\xcd\xcd");

int d;
char another='y';
while(another=='y')  //infinite loop
{
    system("cls");
    gotoxy(26,2);
     printf("\xcd\xcd\xcd\xcd Delete Password  \xcd\xcd\xcd");
gotoxy(10,5);
printf("Enter the Password ID to  delete:");
scanf("%d",&d);
fp=fopen("record_paa.txt","rb+");
rewind(fp); ///reposition file pointer to sream's beggining
while(fread(&stu,sizeof(stu),1,fp)==1)
{
if(stu.userid==d)
{
gotoxy(10,8);
printf("Member name is %s",stu.code);
gotoxy(10,9);
fm='Z';
}
}
if(fm!='Z')
{
gotoxy(10,10);
printf("No record is found in LIST");
if(getch())
 passwordinfo();
}
if(fm=='Z' )
{
gotoxy(10,7);
printf("The Member is available");
gotoxy(10,10);
printf("Do you want to delete it?(Y/N):");
if(getch()=='y')
{
ft=fopen("temppasscode.txt","wb+");  //temporary file for delete
rewind(fp);
while(fread(&stu,sizeof(stu),1,fp)==1)
{
if(stu.userid!=d)
{
fwrite(&stu,sizeof(stu),1,ft); //write all in tempory file except that
}                              //we want to delete
}
fclose(ft);
fclose(fp);
remove("record_paa.txt");
rename("temppasscode.txt","record_paa.txt"); //copy all item from temporary file to fp except that
fp=fopen("record_nxt.txt","rb+");    //we want to delete
if(fm=='Z')
{
gotoxy(10,10);
printf("The record is sucessfully deleted");
gotoxy(10,11);
printf("Delete another record?(Y/N)");
}
}
else
 passwordinfo();
fflush(stdin);
another=getch();
}
}
gotoxy(10,15);
 passwordinfo();
}

void membermainmenu(){
    int choice;
    system("cls");
    gotoxy(20,3);
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd MAIN MENU \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(20,5);printf("1. Add Event\n");
gotoxy(20,7);printf("2. Delete Event\n");
gotoxy(20,9);printf("3. View Event\n");
gotoxy(20,11);printf("4. View Members\n");
gotoxy(20,13);printf("5. Search Member\n");
gotoxy(20,15);printf("6. Close application\n");
gotoxy(20,16);printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(20,17);t();
gotoxy(20,21);
printf("Enter Your Choice: ");
switch(getch()){
case '1':
addevent();
break;
case '2':
deleteevent();
break;
case '3':
vieweevent();
break;
case '4':
mviewmember();
break;
case '5':
msearchmember();
case '6':{
main();
}
default:{
gotoxy(20,22);printf("Wrong!!Correct Option");
if (getch())
membermainmenu();
}
}
}

void addevent(){
    system("cls");
gotoxy(26,2);
     printf("\xcd\xcd\xcd\xcd Add Event \xcd\xcd\xcd");
    int print = 25;
    fp = fopen("record.dat","ab+");
    if(fp == NULL){
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);

    }else{
        fflush(stdin);
        gotoxy(print,5);printf("event date:");gets(stu.date);
        gotoxy(print,6);printf("Event name: ");gets(stu.title);
        gotoxy(print,7);printf("Details: ");gets(stu.z);
        fwrite(&stu, sizeof(stu), 1, fp);
        gotoxy(40,12); printf("The record is sucessfully added");
    }

    fclose(fp);
gotoxy(40,13);printf("Save any more Y/N");
    if (getch()=='n')
    membermainmenu();
    else
    system("cls");
    addevent();

gotoxy(25,20);
mreturnfunc();
getch();
}

void deleteevent()
{
    system("cls");
    char date[20];
   fflush(stdin);

    printf("\n\n\t..::DELETE event\n\t==========================\n\t..::Enterthe date to delete:");

    gets(date);
    fp=fopen("record.dat","r");
    ft=fopen("temp.dat","w");
    while(fread(&stu,sizeof(stu),1,fp)!=0)
    if (stricmp(date,stu.date)!=0)
    fwrite(&stu,sizeof(stu),1,ft);
    fclose(fp);
    fclose(ft);
    remove("record.dat");
    rename("temp.dat","record.dat");
    printf("\n\t\tRecord is delete");
gotoxy(25,25);
mreturnfunc();
getch();
}

void vieweevent()
{
    system("cls");
int j=5;
gotoxy(1,1);
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd view events \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(1,3);printf("Event date         event name               Details");
fp=fopen("record.dat","rb");
while(fread(&stu,sizeof(stu),1,fp)==1)
{
gotoxy(1,j);
printf("%s",stu.date);
gotoxy(18,j);
printf("%s",stu.title);
gotoxy(46,j);
printf("%s\n",stu.z);
j++;
}
fclose(fp);
gotoxy(25,25);
mreturnfunc();
getch();
}

void msearchmember(void){
system("cls");
int s;
gotoxy(10,3);
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd SEARCH MEMBER \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(10,5);
printf("Enter the Member ID to  search:");
scanf("%d",&s);
fp=fopen("record_nxt.txt","rb+");
rewind(fp);
while(fread(&stu,sizeof(stu),1,fp)==1)
{
if(stu.ID==s)
{
gotoxy(10,7);
printf("The Member is available");
gotoxy(10,9);
printf("ID: %d",stu.ID);
gotoxy(10,10);
printf("Name: %s",stu.name);
gotoxy(10,11);
printf("ADress: %s",stu.add);
gotoxy(10,12);
printf("Dept. : %s",stu.dept);
gotoxy(10,13);
printf("Phone nO: %lli",stu.Phone_no);
fm='Z';
}
}
if(fm!='Z')
{
gotoxy(10,10);
printf("No record is found in LIST");
if(getch())

membermainmenu();
}

{
gotoxy(10,9);
printf("");
fclose(fp);
mreturnfunc();
getch();
}}

void mviewmember(void){

system("cls");

FILE *fp;
int i=0,j;
system("cls");
gotoxy(15,1);
printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd Members List \xcd\xcd\xcd\xcd\xcd\xcd");
gotoxy(2,3);
printf(" MEM_ID    MEMBER NAME    ADDRESS     DEPT      PHONE_NO    ");
j=5;
fp=fopen("record_nxt.txt","rb");
while(fread(&stu,sizeof(stu),1,fp)==1)
{
gotoxy(3,j);
printf("%d",stu.ID);
gotoxy(14,j);
printf("%s",stu.name);
gotoxy(28,j);
printf("%s",stu.add);
gotoxy(40,j);
printf("%s",stu.dept);
gotoxy(50,j);
printf("%lli",stu.Phone_no);
gotoxy(69,j);

printf("\n\n");
j++;
i=i+1;
}
gotoxy(3,25);
printf("Total Members =%d\n",i);
fclose(fp);
gotoxy(35,25);
mreturnfunc();
getch();
}

void password(){
    system("cls");
    int co;
    gotoxy(25,2);
    printf("==== POLITICAL PARTY MANAGEMENT SYSTEM ====");
    gotoxy(25,3); printf("    =====welcome! choose your role=====");
     gotoxy(25,5); printf("1)admin");
      gotoxy(25,7); printf("2)Member");
      gotoxy(25,9); printf("3)Exit");
       gotoxy(25,11); printf("enter your role: ");
    scanf("%d",&co);
    if (co == 1){
        password_first();
    }
    else if(co == 2){
        password_second();
    }
    else if(co == 3){
            
    system("cls");
    gotoxy(16,3);
    printf("\t Political Party Management System\n");
    gotoxy(16,5);
    printf("\t THANK YOU FOR USING OUR PROGRAM");
    printf("\n\n*****************************************************************************");

    exit(0);
    }
    else{
        printf("option is invalid!!\a");
        printf("\tENTER correct option");
        getch();
        main();
    }
}

    void password_first(void){
system("cls");
char pass[10],ch,password[10]="admin";
int i=0;
gotoxy(25,2);
printf("==== POLITICAL PARTY MANAGEMENT SYSTEM ====");
gotoxy(20,5);
printf("Enter the password to Login:");
while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';


if(strcmp(pass,password)==0){
gotoxy(20,8);
    printf("Password Matched!!");
    gotoxy(21,9);
    printf("Loading ");
for(i=0;i<=6;i++)
        {
            delay(1);

            printf(".");
        }
                system("cls");
            adminmainmenu();
        }
        else
        gotoxy(15,13);
        printf("Password is invalid!!\n");
        printf("\tENTER correct password");
        getch();
        main();
}

void password_second(void){
system("cls");
char pass[10],ch,password[10]="member";
int i=0, ki;
gotoxy(25,2);
printf("==== POLITICAL PARTY MANAGEMENT SYSTEM ====");
gotoxy(23,3);
printf("enter the ID number: ");
scanf("%d",&ki);
gotoxy(20,5);
printf("Enter the password to Login:");
while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';

fp=fopen("record_paa.txt","rb+");
rewind(fp); ///reposition file pointer to sream's beggining
while(fread(&stu,sizeof(stu),1,fp)==1)
{

if(strcmp(pass,stu.code)==0 && ki==stu.userid){
gotoxy(23,8);
    printf("Password Matched!!");
    gotoxy(25,9);
    printf("Loading ");
for(i=0;i<=6;i++)
        {
            delay(1);

            printf(".");
        }
                system("cls");
           membermainmenu();
        }
        int fm = 'Z';
}
if (fm == 'Z'){

     gotoxy(15,13);
        printf("Password or USERID is invalid!!\n");
        getch();
        main();
}

{
gotoxy(10,9);
printf("");
fclose(fp);
gotoxy(15,13);
printf("Password or USERID is invalid!!\n");
if(getch()==13)
main();
getch();
}
}