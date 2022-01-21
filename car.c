#include"Car.h"
#include<stdio.h>
#include"conio2.h"

#include<string.h>


void addAdmin()
{
    FILE *fp;
    fp=fopen("admin.bin","rb");
    if(fp==NULL)
    {

        struct User usr,usr1;
      fp=fopen("admin.bin","wb");
      strcpy(usr.userid,"Admin");
      strcpy(usr.pwd,"123");
      strcpy(usr.name,"Jatin");
        strcpy(usr1.userid,"admin");
      strcpy(usr1.pwd,"123");
      strcpy(usr1.name,"Jatin");
      fwrite(&usr,sizeof(usr),1,fp);
      fwrite(&usr1,sizeof(usr1),1,fp);
    }
    fclose(fp);
}
User* getInput()
{
    int i;
   static  User usr;

    clrscr();
    textcolor(RED);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,2);
    textcolor(LIGHTCYAN);
    for(i=0;i<80;i++)
    printf("%c",247);
    gotoxy(30,5);
    textcolor(LIGHTCYAN);
    printf("* LOGIN PANEL *");
    textcolor(LIGHTCYAN);
    gotoxy(1,8);
    for(i=0;i<80;i++)
    printf("%c",247);
     textcolor(LIGHTCYAN);
    gotoxy(1,18);
    for(i=0;i<80;i++)
    printf("%c",247);
    gotoxy(60,9);
    printf("Press 0 to exit");
    gotoxy(32,11);
    textcolor(LIGHTCYAN);
    printf("Enter user id:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(usr.userid,20,stdin);
    char *pos1;
    pos1=strchr(usr.userid,'\n');
    if(pos1!=NULL)
    *pos1='\0';
      if(strcmp(usr.userid,"0")==0)
    {
        gotoxy(32,20);
        textcolor(RED);
        printf("Login Canceled!");
        getch();
        return NULL;

    }
    gotoxy(32,12);
    textcolor(LIGHTCYAN);
    printf("Enter Password:");
    i=0;
    textcolor(WHITE);
    for(;;)
    {
        usr.pwd[i]=getch();
        if(usr.pwd[i]==13)
            break;
        if(usr.pwd[i]==8)
        {
            printf("\b\b");
            i=i-2;
        }
        printf("*");
        i++;
    }
    usr.pwd[i]='\0';
    if(strcmp(usr.pwd,"0")==0)
    {
        gotoxy(32,20);
        textcolor(RED);
        printf("Login Cancelledd!");
        getch();
        return NULL;

    }



    return &usr;
}
User* getInput1()
{
    int i;
   static  User usr;

    clrscr();
    textcolor(RED);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,2);
    textcolor(LIGHTCYAN);
    for(i=0;i<80;i++)
    printf("%c",247);
    gotoxy(30,5);
    textcolor(LIGHTCYAN);
    printf("* LOGIN PANEL *");
    textcolor(LIGHTCYAN);
    gotoxy(1,8);
    for(i=0;i<80;i++)
    printf("%c",247);
     textcolor(LIGHTCYAN);
    gotoxy(1,18);
    for(i=0;i<80;i++)
    printf("%c",247);
    gotoxy(60,9);
    printf("Press 0 to exit");
    gotoxy(32,11);
    textcolor(LIGHTCYAN);
    printf("Enter Employee id:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(usr.userid,20,stdin);
    char *pos1;
    pos1=strchr(usr.userid,'\n');
    if(pos1!=NULL)
    *pos1='\0';
      if(strcmp(usr.userid,"0")==0)
    {
        gotoxy(32,20);
        textcolor(RED);
        printf("Login Canceled!");
        getch();
        return NULL;

    }
    gotoxy(32,12);
    textcolor(LIGHTCYAN);
    printf("Enter Password:");
    i=0;
    textcolor(WHITE);
    for(;;)
    {
        usr.pwd[i]=getch();
        if(usr.pwd[i]==13)
            break;
        if(usr.pwd[i]==8)
        {
            printf("\b\b");
            i=i-2;
        }
        printf("*");
        i++;
    }
    usr.pwd[i]='\0';
    if(strcmp(usr.pwd,"0")==0)
    {
        gotoxy(32,20);
        textcolor(RED);
        printf("Login Cancelledd!");
        getch();
        return NULL;

    }



    return &usr;
}
int checkUserExist(User usr,char *usertype)
{

    FILE *fp;

    if(strlen(usr.userid)==0||strlen(usr.pwd)==0)
    {
         gotoxy(32,20);
        textcolor(RED);
        printf("Both the fields are mandatory!");
        getch();
        return NULL;
    }
    if(strcmp(usertype,"admin")==0)
        fp=fopen("admin.bin","rb");
        else
            fp=fopen("emp.bin","wb");

        if(fp==NULL)
        {
               gotoxy(32,20);
        textcolor(RED);
        printf("Login Cancelled!");
        getch();
        return -1;

        }
        int found=0;
    User u;
        while(fread(&u,sizeof(u),1,fp)==1)
        {
            if(strcmp(u.userid,usr.userid)==0&&strcmp(usr.pwd,u.pwd)==0)
            {
                found=1;
                break;
            }
        }
        if(found==0)
        {
        gotoxy(32,20);
        textcolor(RED);
        printf("Invalid UserID/Password!");
        getch();
        }
        else
        {
            gotoxy(32,20);
        textcolor(GREEN);
        printf("Successfully Login !");
        getch();
        }
        return found;
}
int checkUserExist1(User usr,char *usertype)
{

    FILE *fp;

    if(strlen(usr.userid)==0||strlen(usr.pwd)==0)
    {
         gotoxy(32,20);
        textcolor(RED);
        printf("Both the fields are mandatory!");
        getch();
        return NULL;
    }
    if(strcmp(usertype,"emp")==0)
        fp=fopen("emp.bin","rb");


        if(fp==NULL)
        {
               gotoxy(32,20);
        textcolor(RED);
        printf("Login Cancelled!");
        getch();
        return -1;

        }
        int found=0;
    User u;
        while(fread(&u,sizeof(u),1,fp)==1)
        {
            if(strcmp(u.userid,usr.userid)==0&&strcmp(usr.pwd,u.pwd)==0)
            {
                found=1;
                break;
            }
        }
        if(found==0)
        {
        gotoxy(32,20);
        textcolor(RED);
        printf("Invalid Employee  ID/Password!");
        getch();
        }
        else
        {
            gotoxy(32,20);
        textcolor(GREEN);
        printf("Successfully Login !");
        getch();
        }
        return found;
}
int adminMenu()
{
    int i, ch;

        clrscr();
        gotoxy(32,1);
        textcolor(LIGHTRED);
        printf("CAR RENTAL SYSTEM");
        gotoxy(1,2);
        textcolor(WHITE);
        for(i=0;i<80;i++)
        printf("%c",247);
        gotoxy(32,5);
        textcolor(GREEN);
        printf("ADMIN MENU");
         gotoxy(1,7);
        textcolor(WHITE);
        for(i=0;i<80;i++)
        printf("%c",247);
        gotoxy(32,10);
        textcolor(YELLOW);
        printf("1.Add Employee");
         gotoxy(32,11);
        textcolor(YELLOW);
        printf("2.Add Car Details");
     gotoxy(32,12);
        textcolor(YELLOW);
        printf("3.Show Employee");
         gotoxy(32,13);
        textcolor(YELLOW);
        printf("4.Show Car Details");
         gotoxy(32,14);
        textcolor(YELLOW);
        printf("5.Delete Employee");
         gotoxy(32,15);
        textcolor(YELLOW);
        printf("6.Delete Car details");
         gotoxy(32,16);
        textcolor(YELLOW);
        printf("7.Exit");
         gotoxy(32,18);
        textcolor(LIGHTBLUE);
        printf("Select your choice:");
        textcolor(WHITE);
        scanf("%d",&ch);


    return ch;
}


void  addEmployee()
{
      clrscr();


    FILE *fp;

    User usr;char ch;
    fp=fopen("emp.bin","ab+");
    if(fp==NULL)
    {
        gotoxy(32,2);
        printf("Sorry!Can't create file");
        getch();
        return NULL;

    }
    int i,n;
    char temp[10];

    char choice;
    char *pos;
    User u;

   fseek(fp,0,SEEK_END);
   n=ftell(fp)/sizeof(u);
   if(n!=0)
   {
       fseek(fp,-60,SEEK_END);
       fread(temp,sizeof(temp),1,fp);


       pos=strchr(temp,'-');

       n=atoi(pos+1);


   }
    n++;//it will inrease that number by 1;
    sprintf(usr.userid,"Emp-%d",n);
    fseek(fp,0,SEEK_END);



    do
    {
        clrscr();
        gotoxy(32,2);
        textcolor(RED);
        printf("CAR RENTAL SYSTEM");
        gotoxy(1,3);
        for(i=0;i<80;i++)
            printf("~");
            textcolor(GREEN);
            gotoxy(27,5);
            printf("**** ADD EMPLOYEE DETAILS ****");
            textcolor(YELLOW);
            gotoxy(1,9);
            printf("Enter Employee Name:");
            textcolor(WHITE);
            scanf("%s",usr.name);
            gotoxy(1,10);
            textcolor(YELLOW);
            printf("Enter Password:");
            textcolor(WHITE);
            scanf("%s",usr.pwd);
            gotoxy(32,16);
            fseek(fp,0,SEEK_END);
            fwrite(&usr,sizeof(usr),1,fp);
             textcolor(LIGHTGREEN);
            printf("EMPLOYEE ADDED SUCESSFULLY");
            gotoxy(1,17);
            printf("Employee  Id is: %s",usr.userid);
            gotoxy(1,18);
            printf("Do you want to add more employee(Y or N):");
            textcolor(WHITE);
            scanf(" %c",&ch);
            if(ch=='N' ||ch=='n')
                break;
            n++;
            sprintf(usr.userid,"Emp-%d",n);

    }while(ch=='Y'||ch=='y');
    fclose(fp);
    }

void addCarDetails()
{
    FILE *fp;
    Car C;
    char ch;
    fp=fopen("car.bin","ab+");//open file for both reading and writting in append+ mode ;ab+
    if(fp==NULL)
    {
        printf("Sorry!can't open file");
        getch();
        return NULL;
    }
    int i;

fseek(fp,0,SEEK_END);
int   n=ftell(fp)/sizeof(C);
 if(n!=0)
   {
       int temp;
       fseek(fp,-sizeof(C),SEEK_END);
    fread(&temp,sizeof(temp),1,fp);


    n=temp;
}
n++;
C.car_id=n;
do{

    clrscr();
    gotoxy(32,1);
textcolor(LIGHTBLUE);;
printf("CAR RENTAL SYSTEM\n");
textcolor(WHITE);
for(i=0;i<80;i++)
    printf("%c",247);
gotoxy(30,5);
textcolor(LIGHTCYAN);
printf("* ADD CAR DETAILS *");
gotoxy(1,8);
textcolor(GREEN);


printf("Enter Car Name:");
textcolor(WHITE);
fflush(stdin);
fgets(C.car_name,20,stdin);
char *pos;
pos=strchr(C.car_name,'\n');
if(pos!=NULL)
    *pos='\0';

gotoxy(1,9);
textcolor(GREEN);
printf("Enter Car Capacity:");
textcolor(WHITE);
scanf("%d",&C.capacity);
textcolor(GREEN);
gotoxy(1,10);
printf("Enter Car Count:");
textcolor(WHITE);
scanf("%d",&C.car_count);
textcolor(GREEN);
gotoxy(1,11);
printf("Enter Car Price/day:");
textcolor(WHITE);
scanf("%d",&C.car_price);
    fseek(fp,0,SEEK_END);
    fwrite(&C,sizeof(C),1,fp);
    gotoxy(32,13);
    textcolor(GREEN);
    printf("CAR ADDED SUCCESFULLY");
    gotoxy(1,14);
    textcolor(WHITE);
    printf("CAR ID IS:%d",C.car_id);
    gotoxy(1,15);
    textcolor(RED);
    printf("Do you want to add more cars(Y or N):");
    textcolor(WHITE);
    scanf(" %c",&ch);
    if(ch=='N'||ch=='n')
        break;
        n++;
        C.car_id=n;
}while(ch=='Y'||ch=='y');
fclose(fp);
}

 void viewEmployee()
    {
        User usr;
     FILE *fp;
    fp=fopen("emp.bin","rb");
gotoxy(32,1);
if(fp==NULL)
    {
        printf("Sorry ! No file exist");
        getch();
        return NULL;
    }
int i;
textcolor(RED);
printf("CAR RENTAL SYSTEM");
gotoxy(1,2);
textcolor(WHITE);
for(i=0;i<80;i++)
    printf("%c",247);
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(usr);
                 if(n==0)
                    {
                        gotoxy(1,5);
                        textcolor(RED);
                        printf("Sorry!No User Exist");
                        getch();
                        return ;
                    }
                    rewind(fp);
    gotoxy(30,5);
    textcolor(YELLOW);
    printf("* SHOW  EMPLOYEE DETAILS *");
    gotoxy(1,8);
textcolor(WHITE);
for(i=0;i<80;i++)
    printf("%c",247);
     gotoxy(1,10);
textcolor(WHITE);
for(i=0;i<80;i++)
    printf("%c",247);
    gotoxy(1,9);
    textcolor(LIGHTBLUE);
    printf("EMPLOYEE ID");
    gotoxy(30,9);
    printf("NAME");
    gotoxy(50,9);
    printf("PASSWORD");
    gotoxy(32,9);


    int row=11;
    textcolor(YELLOW);

    while(fread(&usr,sizeof(usr),1,fp)==1)
    {
        gotoxy(1,row);
        printf("%s",usr.userid);
         gotoxy(30,row);
        printf("%s",usr.name);
         gotoxy(50,row);
        printf("%s",usr.pwd);
        row++;

        }
        getch();
        fclose(fp);
        }


   void showCarDetails()
        {
             FILE *fp1;
             int i;
                    fp1=fopen("car.bin","rb");
                    Car C;
                    if(fp1==NULL)
                    {
                        gotoxy(32,1);

                        textcolor(RED);

                        printf("No file exist!First add cars!!");
                        getch();
                        return NULL;
                    }
            gotoxy(32,1);
            textcolor(YELLOW);
            printf("CAR RENTAL SYSTEM");
            gotoxy(1,2);
             fseek(fp1,0,SEEK_END);
                    int n=ftell(fp1)/sizeof(C);
                    if(n==0)
                    {
                        gotoxy(1,5);
                        textcolor(RED);
                        printf("Sorry!No Car Exist");
                        getch();
                        return ;
                    }
                    rewind(fp1);
            textcolor(LIGHTGRAY);
            for(i=0;i<80;i++)
                printf("%c",247);
                gotoxy(30,5);
                textcolor(YELLOW);
                printf("CAR DETAILS");
                gotoxy(1,8);
                textcolor(LIGHTGRAY);
                for(i=0;i<80;i++)
                    printf("%c",247);
                gotoxy(1,10);
                for(i=0;i<80;i++)
                    printf("%c",247);
                    gotoxy(1,9);
                    textcolor(LIGHTBLUE);
                    printf("CAR ID");
                    gotoxy(15,9);
                    printf("CAR NAME");
                    gotoxy(30,9);
                    printf("Capacity");
                    gotoxy(45,9);
                    printf("CAR COUNT");
                    gotoxy(60,9);
                    printf("PRICE/DAY");

                    int row=11;
                    if(fp1==NULL)
                    {
                        printf("Sorry ! NO CAR Exist");
                        getch();
                        return NULL;
                    }

                    while(fread(&C,sizeof(C),1,fp1)==1)
                    {
                        gotoxy(1,row);
                        printf("%d",C.car_id);
                          gotoxy(15,row);
                        printf("%s",C.car_name);
                          gotoxy(30,row);
                        printf("%d",C.capacity);
                          gotoxy(45,row);
                        printf("%d",C.car_count);
                          gotoxy(60,row);
                        printf("%d",C.car_price);
                        row++;
                    }
                    fclose(fp1);
                    getch();
                    return ;
        }





       int deleteEmp()
    {
        int i;
        clrscr();
        char str[30];
        FILE *fp1,*fp2;
        fp1=fopen("emp.bin","rb");
        if(fp1==NULL)
        {
            printf("Sorry can't open the file");
            getch();
            return NULL;
        }
        gotoxy(32,1);
        textcolor(LIGHTRED);
        printf("CAR RENTAL SYSTEM");
        gotoxy(1,2);
        textcolor(YELLOW);
        for(i=0;i<80;i++)
        printf("%c",247);
        gotoxy(30,5);
        printf("* DELETE EMPLOYEE RECORD *");
        gotoxy(1,8);
        textcolor(YELLOW);
        for(i=0;i<80;i++)
            printf("%c",247);
             gotoxy(1,15);
             textcolor(YELLOW);
        for(i=0;i<80;i++)
            printf("%c",247);
        gotoxy(12,10);
        textcolor(LIGHTCYAN);
        printf("Enter Employee ID to delete the record:");
        textcolor(WHITE);
        scanf(" %s",str);
        User usr;
        int found=0;
        fp2=fopen("temp.bin","wb");
        while(fread(&usr,sizeof(usr),1,fp1)==1)
        {
            if(strcmp(usr.userid,str)!=0)

                fwrite(&usr,sizeof(usr),1,fp2);

                else
               found=1;

        }
        fclose(fp1);
        fclose(fp2);
        if(found==0)
        {
            remove("temp.bin");
        }
        else
        {
            int result=remove("emp.bin");
            if(result!=0)
                return 2;
            result=rename("temp.bin","emp.bin");
            if(result!=0)
                return 2;
        }

        return found;
}

int deleteCarModel()
{

    Car C;
    int found=0;
  clrscr();
    FILE *fp1=fopen("car.bin","rb");
    int id;
    int i,result;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    textcolor(BLUE);
    for(i=1; i<=80; i++)
        printf("%c",247);
    gotoxy(29,5);
    textcolor(YELLOW);
    printf("* DELETE CAR RECORD *");
    gotoxy(1,7);
    textcolor(BLUE);
    for(i=1; i<80; i++)
        printf("%c",247);
    gotoxy(1,12);
    for(i=1; i<80; i++)
        printf("%c",247);
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo Car Added Yet!");
        getch();
        return -1;
    }

    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter Car  Id to delete the record:");
    textcolor(WHITE);
    scanf("%d",&id);

    gotoxy(1,10);
    textcolor(GREEN);
     FILE *fp2=fopen("temp.bin","wb");
     while(fread(&C,sizeof(C),1,fp1)==1)
     {
         if(C.car_id==id)
            found=1;
         else
            fwrite(&C,sizeof(C),1,fp2);
     }
     fclose(fp1);
     fclose(fp2);
     if(found==0)
        remove("temp.bin");
     else
     {
         int result;
         result=remove("car.bin");
         if(result!=0)
            {
                gotoxy(32,17);
                perror("");
                getch();
                return 2;
            }
         result=rename("temp.bin","car.bin");
         if(result!=0)
            {
                gotoxy(32,17);
                perror("");
                getch();
                return 2;
            }

     }
     return found;
}
//employee login

int empMenu()
{
    clrscr();
    int ch;
    gotoxy(32,2);
    textcolor(RED);
    printf("CAR RENTAL SYSTEM");
gotoxy(32,6);
textcolor(GREEN);
printf("EMPLOYEE MENU\n");
int i;
for(i=0;i<80;i++)
    printf("*");
    textcolor(YELLOW);
gotoxy(32,8);
printf("1. Rent a Car");
gotoxy(32,9);
printf("2. Booking Details");
gotoxy(32,10);
printf("3. Available Car Details");
gotoxy(32,11);
printf("4. Show all car details");
gotoxy(32,12);
printf("5. Return Car Model");
gotoxy(32,13);
printf("6. Return Car Details");
gotoxy(32,14);
printf("7. Exit");
gotoxy(32,17);
textcolor(LIGHTCYAN);
int x=printf("Enter choice:");
textcolor(WHITE);
scanf("%d",&ch);

return ch;
}
int selectCarModel()
{
    clrscr();
    FILE *fp=fopen("car.bin","rb");
    Car C;
    if(fp==NULL)
    {
        gotoxy(32,2);
        printf("Sorry!FILE CAN NOT BE OPENED!");
        getch();
        return -1;
    }
        gotoxy(32,2);
    textcolor(RED);
    printf("CAR RENTAL SYSTEM");
    int i;
    gotoxy(32,5);
    textcolor(GREEN);
    printf("EMPLOYEE MENU");
    gotoxy(1,6);
    for(i=0;i<80;i++)
        printf("%c",247);
gotoxy(60,7);
textcolor(WHITE);
printf("Press 0 to exit");


    int flag=0;

    int choice,x=9;

    gotoxy(34,x);int carcount=0;
    textcolor(YELLOW);
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_count>0)
        {
            printf("%d . %s",C.car_id,C.car_name);
            gotoxy(34,++x);
            carcount++;
        }
    }
    if(carcount==0)
    {
        fclose(fp);
        return -2;
    }
    textcolor(LIGHTCYAN);
    gotoxy(34,x+2);
    printf("Enter your choice:");
    textcolor(WHITE);
    while(1)
    {
        flag=0;
        scanf("%d",&choice);
        if(choice==0)
            {


                return 0;
            }
        rewind(fp);
        while(fread(&C,sizeof(C),1,fp)==1)
        {
            if(C.car_id==choice&&C.car_count>0)
            {
                flag=1;
                break;

            }
        }
        if(flag==1)
        {
            fclose(fp);
            return choice;
        }
        else
        {
            gotoxy(37,x+4);
            textcolor(LIGHTRED);
            printf("Wrong Input");
            getch();
            gotoxy(35,x+4);
            printf("\t\t");
            gotoxy(52,x+2);
            printf("\t\t\t");
            gotoxy(52,x+2);
            textcolor(WHITE);

 }
}



}
    int  rentCar()

    {

        int k;
        clrscr();
        Customer_Car_Details C;
            FILE *fp=fopen("customer.bin","ab");
            if(fp==NULL)
            {
                printf("Sorry!Can't create file");
                getch();
                return -1;

            }
            int c_id;
            c_id=selectCarModel();
            if(c_id==0)
            {
                return -2;
            }
            if(c_id==-1)
            {
                printf("Sorry! File cannot open ");
                getch();
                return ;
            }
            if(c_id==-2)
            {
                return -2;
            }
         if(c_id>0)
           {
               C.car_id=c_id;
           }
           clrscr();

        gotoxy(32,2);
    textcolor(RED);
    printf("CAR RENTAL SYSTEM");
    int i;
    gotoxy(32,5);
    textcolor(GREEN);
    printf("EMPLOYEE MENU");
    gotoxy(1,6);
    for(i=0;i<80;i++)
        printf("%c",247);
        gotoxy(1,17);

    for(i=0;i<80;i++)
        printf("%c",247);
        gotoxy(27,9);
        textcolor(YELLOW);
        printf("Enter Customer name:");
        textcolor(WHITE);
         fflush(stdin);
        fgets(C.cust_name,30,stdin);
        char *pos;
        pos=strchr(C.cust_name,'\n');
        if(pos!=NULL)
            *pos='\0';
    textcolor(YELLOW);
    gotoxy(27,10);
        printf("Enter pickup point:");
        textcolor(WHITE);
        fflush(stdin);
        fgets(C.pick,30,stdin);
 pos=strchr(C.pick,'\n');
        if(pos!=NULL)
            *pos='\0';
         textcolor(YELLOW);
         gotoxy(27,11);
        printf("Enter drop point:");
        textcolor(WHITE);
         fflush(stdin);
        fgets(C.drop,30,stdin);
     pos=strchr(C.drop,'\n');
        if(pos!=NULL)
            *pos='\0';
        gotoxy(27,12);
        textcolor(YELLOW);
        int c=printf("Enter start date(dd/mm/yy):");
        textcolor(WHITE);



           while(1)
            {
        scanf("%d/%d/%d",&C.sd.tm_mday,&C.sd.tm_mon,&C.sd.tm_year);

        k=isValidDate(C.sd);
        if(k==1)
            break;

            gotoxy(32,19);
            textcolor(RED);
            printf("Wrong date");
            getch();
            gotoxy(32,19);
            printf("\t\t\t\t");
            gotoxy(27+c,12);
            printf("\t\t\t\t\t\t\t\t\t");
            gotoxy(27+c,12);
            textcolor(WHITE);
          }

             gotoxy(27,13);
        textcolor(YELLOW);
        c=printf("Enter end date (dd/mm/yy):");


          while(1)
            {
                textcolor(WHITE);
        scanf("%d/%d/%d",&C.ed.tm_mday,&C.ed.tm_mon,&C.ed.tm_year);
        k=isValidDate(C.ed);

             if(k==0)
            {gotoxy(32,19);
            textcolor(RED);
            printf("Wrong date");
            getch();
            gotoxy(32,19);
            printf("\t\t\t\t");
            gotoxy(27+c,13);
            printf("\t\t\t\t\t\t\t\t\t");
            gotoxy(27+c,13);
            textcolor(WHITE);
            continue;
            }
          if(C.sd.tm_mday>C.ed.tm_mday &&C.ed.tm_mon==C.sd.tm_mon)
          {
              gotoxy(27,19);
            textcolor(RED);
            printf("Wrong date!End date is less then Start date!!!");
            getch();
            gotoxy(27,19);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(27+c,13);
            printf("\t\t\t");
            gotoxy(27+c,13);
            textcolor(WHITE);
            continue;

          }
          if(C.ed.tm_mon<C.sd.tm_mon)
           {
                gotoxy(27,19);
            textcolor(RED);
            printf("Wrong date!End date is less then Start date!!!");
            getch();
            gotoxy(27,19);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(27+c,13);
            printf("\t\t\t");
            gotoxy(27+c,13);
            textcolor(WHITE);
            continue;
           }
           if(k==1)
            break;

            }


if(fp==NULL)
    {
        gotoxy(27,18);
        textcolor(LIGHTRED);
        printf("Sorry ! File cannot be opened");
        getch();
        gotoxy(27,18);
        printf("\t\t");
        return -1;
    }


        fwrite(&C,sizeof(C),1,fp);
        textcolor(WHITE);

gotoxy(1,14);
textcolor(WHITE);
printf("Booking Done:%d",C.car_id);
gotoxy(1,15);
textcolor(WHITE);
    printf("\nPress any key to continue...");
getch();
fclose(fp);

updateCarCount(C.car_id);
bookedCarDetails(C.car_id);
return 1;

    }




int isValidDate(struct tm dt)
{
    time_t now=time(0);
    struct tm *sd=localtime(&now);
    sd->tm_mon=sd->tm_mon+1;
    sd->tm_year=1900+sd->tm_year;

    if(dt.tm_mon<sd->tm_mon)
        {

            return 0;
       }
       else if(dt.tm_mon==sd->tm_mon&&dt.tm_mday<sd->tm_mday)
       {
           return 0;

       }
            if(dt.tm_year>=2021 && dt.tm_year<=2022)
             {
        //check month
        if(dt.tm_mon>=1 && dt.tm_mon<=12)
           {
            //check days
            if((dt.tm_mday>=1 && dt.tm_mday<=31) && (dt.tm_mon==1 || dt.tm_mon==3 || dt.tm_mon==5 || dt.tm_mon==7 || dt.tm_mon==8 || dt.tm_mon==10 || dt.tm_mon==12))
               return 1;
            else if((dt.tm_mday>=1 && dt.tm_mday<=30) && (dt.tm_mon==4 || dt.tm_mon==6 || dt.tm_mon==9 || dt.tm_mon==11))
               return 1;
            else if((dt.tm_mday>=1 && dt.tm_mday<=28) && (dt.tm_mon==2))
                return 1;
            else if(dt.tm_mday==29 && dt.tm_mon==2 && (dt.tm_year%400==0 ||(dt.tm_year%4==0 && dt.tm_year%100!=0)))
               return 1;
            else
               return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

}




void updateCarCount(int c)
{

    FILE *fp=fopen("car.bin","rb+");
    Car C;
    while(fread(&C,sizeof(Car),1,fp)==1)
    {


        if(C.car_id==c)
        {

            fseek(fp,-8,SEEK_CUR);


            int cc_new=C.car_count-1;

            fwrite(&cc_new,sizeof(cc_new),1,fp);
            fseek(fp,-4,SEEK_CUR);



        }

    }
    fclose(fp);
}

void bookedCarDetails(C_id)
{
    clrscr();
    FILE *fp=fopen("customer.bin","rb");
    Customer_Car_Details CC;
    int i;
    gotoxy(32,2);

    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1; i<=80; i++)
        printf("%c",247);
    gotoxy(31,5);
    textcolor(YELLOW);
    printf("* BOOKED CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1; i<80; i++)
        printf("%c",247);
    gotoxy(1,8);
    printf("Model\t    Cust Name\t  Pick Up\t   Drop\t\t S_Date\t     E_Date");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=1; i<80; i++)
        printf("%c",247);
    int x=10;
    textcolor(YELLOW);
char ch;
    while(fread(&CC,sizeof(Customer_Car_Details),1,fp)==1)
    {
        if(CC.car_id==C_id)
        {
            gotoxy(1,x);
        printf("%s",getCarName(CC.car_id));
        gotoxy(13,x);
        printf("%s",CC.cust_name);
        gotoxy(27,x);

        printf("%s",CC.pick);
        gotoxy(44,x);
        printf("%s",CC.drop);
        gotoxy(58,x);
        printf("%d-%d-%d",CC.sd.tm_mday,CC.sd.tm_mon,CC.sd.tm_year);
        gotoxy(70,x);
        printf("%d-%d-%d",CC.ed.tm_mday,CC.ed.tm_mon,CC.ed.tm_year);
        x++;

        }
    }
    fclose(fp);
    _getch();

}
char *getCarName(int C_id)
{
    FILE *fp;
    fp=fopen("car.bin","rb");
    if(fp==NULL)
    {
        printf("Sorry!could not open the file");
        getch();
        return NULL;
    }
   static Car  CC;
    while(fread(&CC,sizeof(CC),1,fp)==1)
    {
        if(C_id==CC.car_id)
            break;
    }
    fclose(fp);
    return CC.car_name;
}
void bookCarDetails()
{
    clrscr();
    Customer_Car_Details CC;
    FILE *fp=fopen("customer.bin","rb");
    if(fp==NULL)
    {
        gotoxy(32,2);
        textcolor(RED);
        printf("NO!CAR EXIST");
        getch();
        return -1;
    }
    fseek(fp,0,SEEK_END);
    int n=ftell(fp)/sizeof(CC);


    if(n==0)
    {
        gotoxy(32,2);
        textcolor(RED);
        printf("NO CAR BOOKED!!");
        getch();
        return 0;
    }
    rewind(fp);

    int i;
    gotoxy(32,2);

    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1; i<=80; i++)
        printf("%c",247);
    gotoxy(31,5);
    textcolor(YELLOW);
    printf("* ALL BOOKED CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1; i<=80; i++)
        printf("%c",247);
    gotoxy(1,8);
    printf("C_ID");
    gotoxy(6,8);
    printf("Model");
    gotoxy(15,8);
    printf("Cust Name");
    gotoxy(30,8);
    printf("Pick Up");
     gotoxy(45,8);
    printf("Drop");
     gotoxy(58,8);
    printf(" S_Date");
    gotoxy(70,8);
    printf("E_Date");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=1; i<=80; i++)
        printf("%c",247);
    int x=10;
    textcolor(YELLOW);
textcolor(YELLOW);
    while(fread(&CC,sizeof(Customer_Car_Details),1,fp)==1)
    {


            gotoxy(1,x);
            printf("%d",CC.car_id);
            gotoxy(6,x);
        printf("%s",getCarName(CC.car_id));
        gotoxy(15,x);
        printf("%s",CC.cust_name);
        gotoxy(30,x);
        printf("%s",CC.pick);
        gotoxy(45,x);
        printf("%s",CC.drop);
        gotoxy(58,x);
        printf("%d-%d-%d",CC.sd.tm_mday,CC.sd.tm_mon,CC.sd.tm_year);
        gotoxy(70,x);
        printf("%d-%d-%d",CC.ed.tm_mday,CC.ed.tm_mon,CC.ed.tm_year);
        x++;

        }

    fclose(fp);
    _getch();

}
void availableCarDetails()
{

FILE *fp1;
             int i;
                    fp1=fopen("car.bin","rb");
                    Car C;
                    if(fp1==NULL)
                    {
                        gotoxy(32,1);

                        textcolor(RED);

                        printf("No file exist!First add cars!!");
                        getch();
                        return NULL;
                    }
            gotoxy(32,1);
            textcolor(YELLOW);
            printf("CAR RENTAL SYSTEM");
            gotoxy(1,2);
             fseek(fp1,0,SEEK_END);
                    int n=ftell(fp1)/sizeof(C);
                    if(n==0)
                    {
                        gotoxy(1,5);
                        textcolor(RED);
                        printf("Sorry!No Car Exist");
                        getch();
                        return ;
                    }
                    rewind(fp1);
            textcolor(LIGHTGRAY);
            for(i=0;i<80;i++)
                printf("%c",247);
                gotoxy(30,5);
                textcolor(YELLOW);
                printf("AVAILABLE CAR DETAILS");
                gotoxy(1,8);
                textcolor(LIGHTGRAY);
                for(i=0;i<80;i++)
                    printf("%c",247);
                gotoxy(1,10);
                for(i=0;i<80;i++)
                    printf("%c",247);
                    gotoxy(1,9);
                    int row=11;
                    if(fp1==NULL)
                    {
                        printf("Sorry ! NO CAR Exist");
                        getch();
                        return NULL;
                    }
                    textcolor(YELLOW);
                    textcolor(LIGHTBLUE);
                    printf("CAR ID");
                    gotoxy(15,9);
                    printf("CAR NAME");
                    gotoxy(40,9);
                    printf("Capacity");
                    gotoxy(50,9);
                    printf("Available");
                    gotoxy(60,9);
                    printf("PRICE/DAY");



                    while(fread(&C,sizeof(C),1,fp1)==1)
                    {
                        if(C.car_count>0)
                        {
                            gotoxy(1,row);
                        printf("%d",C.car_id);
                          gotoxy(15,row);
                        printf("%s",C.car_name);
                          gotoxy(40,row);
                        printf("%d",C.capacity);
                          gotoxy(50,row);
                        printf("%d",C.car_count);
                          gotoxy(60,row);
                        printf("%d",C.car_price);

                        row++;
                    }
                    }
                    fclose(fp1);
                    getch();
                    return ;

        }
        void allCarDetails()
        {
            FILE *fp1;
             int i;
                    fp1=fopen("car.bin","rb");
                    Car C;
                    if(fp1==NULL)
                    {
                        gotoxy(32,1);

                        textcolor(RED);

                        printf("No file exist!First add cars!!");
                        getch();
                        return NULL;
                    }
            gotoxy(32,1);
            textcolor(YELLOW);
            printf("CAR RENTAL SYSTEM");
            gotoxy(1,2);
             fseek(fp1,0,SEEK_END);
                    int n=ftell(fp1)/sizeof(C);
                    if(n==0)
                    {
                        gotoxy(1,5);
                        textcolor(RED);
                        printf("Sorry!No Car Exist");
                        getch();
                        return ;
                    }
                    rewind(fp1);
                      int row=11;
                    if(fp1==NULL)
                    {
                        printf("Sorry ! NO CAR Exist");
                        getch();
                        return NULL;
                    }
            textcolor(LIGHTGRAY);
            for(i=0;i<80;i++)
                printf("%c",247);
                gotoxy(30,5);
                textcolor(YELLOW);
                printf("* ALL CAR DETAILS *");
                gotoxy(1,8);
                textcolor(LIGHTGRAY);
                for(i=0;i<80;i++)
                    printf("%c",247);
                gotoxy(1,10);
                for(i=0;i<80;i++)
                    printf("%c",247);
                    gotoxy(1,9);
                    textcolor(LIGHTBLUE);
                    printf("CAR ID");
                    gotoxy(15,9);
                    printf("CAR NAME");
                    gotoxy(45,9);
                    printf("Capacity");
                    gotoxy(55,9);
                    printf("AVAILABLE");
                    gotoxy(65,9);
                    printf("PRICE/DAY");


                    textcolor(YELLOW);

                    while(fread(&C,sizeof(C),1,fp1)==1)
                    {

                            gotoxy(1,row);
                        printf("%d",C.car_id);
                          gotoxy(15,row);
                        printf("%s",C.car_name);
                          gotoxy(45,row);
                        printf("%d",C.capacity);
                          gotoxy(55,row);
                        printf("%d",C.car_count);
                          gotoxy(65,row);
                        printf("%d",C.car_price);
                        row++;

                    }

                    fclose(fp1);
                    getch();

        }




int  carPrice(int id)
{
    static Car C;
    FILE *fp=fopen("car.bin","rb");
    if(fp==NULL)
    {
        printf("Sorry!no car present");
        getch();
        fclose(fp);
        return NULL;
    }
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_id==id)
        {
            fclose(fp);
            return C.car_price;
    }

  }
  fclose(fp);
}

int price(struct tm sd,struct tm ed,int pay)
{

int m,d;
if(sd.tm_mon==ed.tm_mon&&(ed.tm_mon==4 || ed.tm_mon==6 || ed.tm_mon==9 || ed.tm_mon==11))
    {
        m=ed.tm_mday-sd.tm_mday;
        m=m*pay;


    }
      if(sd.tm_mon==ed.tm_mon&&( ed.tm_mon==1 || ed.tm_mon==3 || ed.tm_mon==5 || ed.tm_mon==7 || ed.tm_mon==8 || ed.tm_mon==10 || ed.tm_mon==12))
    {
        m=ed.tm_mday-sd.tm_mday;

        m=m*pay;


        return m;

    }
 if(sd.tm_mday<ed.tm_mday&&sd.tm_mon<ed.tm_mon&&(ed.tm_mon==4 || ed.tm_mon==6 || ed.tm_mon==9 || ed.tm_mon==11))
    {

        m=ed.tm_mon-sd.tm_mon;
        m=m*30*pay;



            d=ed.tm_mday-sd.tm_mday;
            d=d*pay;
            m=(m+d);



            }
    if(sd.tm_mday<ed.tm_mday&&sd.tm_mon<ed.tm_mon&&(ed.tm_mon==1 || ed.tm_mon==3 || ed.tm_mon==5 || ed.tm_mon==7 || ed.tm_mon==8 || ed.tm_mon==10 || ed.tm_mon==12))
    {

        m=ed.tm_mon-sd.tm_mon;
        m=m*31*pay;

            d=ed.tm_mday-sd.tm_mday;
            d=d*pay;

            m=(m+d);
        return m;

    }
     if(sd.tm_mday>ed.tm_mday&&sd.tm_mon<ed.tm_mon&&(ed.tm_mon==4 || ed.tm_mon==6 || ed.tm_mon==9 || ed.tm_mon==11))
    {
        m=ed.tm_mon-sd.tm_mon;

        m=m*30*pay;

        d=sd.tm_mday-ed.tm_mday;
        d=d*pay;
        m=m+d;

        return m;

    }
    if(sd.tm_mday>ed.tm_mday&&sd.tm_mon<ed.tm_mon&&(ed.tm_mon==1 || ed.tm_mon==3 || ed.tm_mon==5 || ed.tm_mon==7 || ed.tm_mon==8 || ed.tm_mon==10 || ed.tm_mon==12))
    {
        m=ed.tm_mon-sd.tm_mon;
        m=m*30*pay;

        d=sd.tm_mday-ed.tm_mday;
        d=d*pay;
        m=m+d;

        return m;

    }

    if(ed.tm_mon==2&&sd.tm_mon==2&&(ed.tm_year%400==0 ||(ed.tm_year%4==0 && ed.tm_year%100!=0)))
    {
        m=ed.tm_mday-sd.tm_mday;
        m=m*29*pay;
    }


     if(sd.tm_mday==ed.tm_mday&&sd.tm_mon<ed.tm_mon&&(ed.tm_mon==1 || ed.tm_mon==3 || ed.tm_mon==5 || ed.tm_mon==7 || ed.tm_mon==8 || ed.tm_mon==10 || ed.tm_mon==12))
    {
        m=ed.tm_mon-sd.tm_mon;
        m=m*31*pay;


    }
 if(sd.tm_mday==ed.tm_mday&&sd.tm_mon<ed.tm_mon&& (ed.tm_mon==4 || ed.tm_mon==6 || ed.tm_mon==9 || ed.tm_mon==11))
    {
        m=ed.tm_mon-sd.tm_mon;
        m=m*31*pay;

 return m;

    }


    return m;
}
int isValidDate1(struct tm dt)
 {
     if(dt.tm_year>=2021 && dt.tm_year<=2022)
             {
        //check month
        if(dt.tm_mon>=1 && dt.tm_mon<=12)
           {
            //check days
            if((dt.tm_mday>=1 && dt.tm_mday<=31) && (dt.tm_mon==1 || dt.tm_mon==3 || dt.tm_mon==5 || dt.tm_mon==7 || dt.tm_mon==8 || dt.tm_mon==10 || dt.tm_mon==12))
               return 1;
            else if((dt.tm_mday>=1 && dt.tm_mday<=30) && (dt.tm_mon==4 || dt.tm_mon==6 || dt.tm_mon==9 || dt.tm_mon==11))
               return 1;
            else if((dt.tm_mday>=1 && dt.tm_mday<=28) && (dt.tm_mon==2))
                return 1;
            else if(dt.tm_mday==29 && dt.tm_mon==2 && (dt.tm_year%400==0 ||(dt.tm_year%4==0 && dt.tm_year%100!=0)))
               return 1;
            else
               return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

}
void updateCarCount1(int c)

 {

     FILE *fp=fopen("car.bin","rb+");
    Car C;
    while(fread(&C,sizeof(Car),1,fp)==1)
    {


        if(C.car_id==c)
        {

            fseek(fp,-8,SEEK_CUR);


            int cc_new=C.car_count+1;


            fwrite(&cc_new,sizeof(cc_new),1,fp);
            fseek(fp,-4,SEEK_CUR);



        }

    }
    fclose(fp);
}
int returnCar()

        {
            FILE *fp1;
            fp1=fopen("returncar.bin","ab+");
            if(fp1==NULL)
            {
                textcolor(RED);
                printf("Sorry!can't create file");
                getch();
                return -1;
            }
            Return_CAR_DETAILS R;
            clrscr();
            Customer_Car_Details CC;
            int i;
            textcolor(RED);
            gotoxy(32,2);
            textcolor(RED);
            printf("CAR RENTAL SYSTEM");
            gotoxy(1,3);
            textcolor(YELLOW);

            for(i=0;i<80;i++)
            printf("%c",247);
            gotoxy(30,5);
            textcolor(GREEN);
            printf("* RETURN CAR MODEL *");
              gotoxy(1,7);
            textcolor(YELLOW);

            for(i=0;i<80;i++)
            printf("%c",247);
       FILE *fp2;
            fp2=fopen("customer.bin","rb");
            if(fp2==NULL)
            {
                gotoxy(32,16);
                printf("Sorry! No car booked");
                getch();
                return -1;
            }
            gotoxy(60,9);
            textcolor(WHITE);
            printf("Press 0 to exit");
              gotoxy(1,10);
            textcolor(LIGHTCYAN);
            int c=printf("ENTER CAR ID WHICH YOU WANT TO RETURN:");
            while(1)
                {


           int count=0;

                        textcolor(WHITE);
              scanf("%d",&R.car_id);
              if(R.car_id==0)
                return 3;
              //rewind fp compilosry! we match the id again and if we do not do rewind the it start reading form last;
              rewind(fp2);
            while(fread(&CC,sizeof(CC),1,fp2)==1)
            {
                if(CC.car_id==R.car_id)
                    {
                        count=1;
                    break;
                    }
                    }
               if(count==1)
                break;

               if(count==0)
               {
                textcolor(RED);
                gotoxy(32,20);
                printf("Wrong Car Id!");
            getch();
            gotoxy(32,20);
            printf("\t\t\t\t\t");
            gotoxy(1+c,10);
            printf("\t\t\t");
            gotoxy(1+c,10);
            textcolor(WHITE);



              }
                }



                  gotoxy(1,12);
                    for(i=0;i<=80;i++)
                        printf("%c",247);
            textcolor(RED);
             gotoxy(1,11);
                    printf("Car_id");
                    gotoxy(15,11);
                    printf("S_Date");
                    gotoxy(30,11);
                    printf("E_Date");
                    textcolor(RED);
                  gotoxy(45,11);
                  printf("Car Price");
                  gotoxy(60,11);
                  printf("Car Name");
                rewind(fp2);
                    int row=13;
                    textcolor(YELLOW);
            while(fread(&CC,sizeof(CC),1,fp2)==1)
            {
                if(R.car_id==CC.car_id)
                {
                   gotoxy(1,row);
                   printf("%d",CC.car_id);
                   gotoxy(15,row);
                   printf("%d/%d/%d",CC.sd.tm_mday,CC.sd.tm_mon,CC.sd.tm_year);
                   gotoxy(30,row);
                   printf("%d/%d/%d",CC.ed.tm_mday,CC.ed.tm_mon,CC.ed.tm_year);
                   gotoxy(45,row);
                   printf("%d",carPrice(R.car_id));
                   gotoxy(60,row);
                   printf("%s",getCarName(R.car_id));
                   row++;
                }


                }






            gotoxy(1,row+1);
            textcolor(LIGHTCYAN);

            c=printf("Enter start date:");


     while(1)
            {
                textcolor(WHITE);
        scanf("%d/%d/%d",&R.sd.tm_mday,&R.sd.tm_mon,&R.sd.tm_year);

       int  k=isValidDate1(R.sd);
        if(k==1)
            break;
else if(k==0)
    {
            gotoxy(32,25);
            textcolor(RED);
            printf("Wrong date");
            getch();
            gotoxy(32,25);
            printf("\t\t\t\t");
            gotoxy(1+c,row+1);
            printf("\t\t\t\t\t\t\t\t\t");
            gotoxy(1+c,row+1);
            textcolor(WHITE);
          }
            }



            gotoxy(1,row+2);
            textcolor(LIGHTCYAN);
         c=printf("Enter end date:");

                 while(1)
            {
                textcolor(WHITE);
        scanf("%d/%d/%d",&R.ed.tm_mday,&R.ed.tm_mon,&R.ed.tm_year);

       int         k=isValidDate1(R.ed);
        if(k==1)
            break;

            gotoxy(32,25);
            textcolor(RED);
            printf("Wrong date");
            getch();
            gotoxy(32,25);
            printf("\t\t\t\t");
            gotoxy(1+c,row+2);
            printf("\t\t\t\t\t\t\t\t\t");
            gotoxy(1+c,row+2);
            textcolor(WHITE);
          }




            textcolor(LIGHTCYAN);
            int pay;
            gotoxy(1,row+3);
            printf("Enter Price/day:");
            textcolor(WHITE);
            scanf("%d",&pay);
            gotoxy(1,row+4);
            textcolor(LIGHTCYAN);
            c=printf("Return Date:");

            while(1)
            {
                textcolor(WHITE);
        scanf("%d/%d/%d",&R.endDate.tm_mday,&R.endDate.tm_mon,&R.endDate.tm_year);


               if(R.sd.tm_mday>R.endDate.tm_mday &&R.endDate.tm_mon==CC.sd.tm_mon)
          {
              gotoxy(27,19);
            textcolor(RED);
            printf("Wrong date!End date is less then Start date!!!");
            getch();
            gotoxy(27,19);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(27+c,row+4);
            printf("\t\t\t");
            gotoxy(27+c,row+4);
            textcolor(WHITE);
            continue;

          }
          if(R.endDate.tm_mon<CC.sd.tm_mon)
           {
                gotoxy(27,19);
            textcolor(RED);
            printf("Wrong date!Return  date is less then Start date...!!!");
            getch();
            gotoxy(27,19);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(27+c,13);
            printf("\t\t\t");
            gotoxy(27+c,13);
            textcolor(WHITE);
            continue;
           }
            int  k=isValidDate1(R.endDate);
        if(k==1)
            break;
           else if(k==0)
            {
            gotoxy(32,25);
            textcolor(RED);
            printf("Wrong date");
            getch();
            gotoxy(32,25);
            printf("\t\t\t\t");
            gotoxy(1+c,row+3);
            printf("\t\t\t\t\t\t\t\t\t");
            gotoxy(1+c,row+3);
            textcolor(WHITE);
          }
            }



rewind(fp2);

int found=0;
while(fread(&CC,sizeof(CC),1,fp2)==1)
{
    if(CC.sd.tm_mday==R.sd.tm_mday&&CC.sd.tm_mon==R.sd.tm_mon&&CC.sd.tm_year==R.sd.tm_year&&pay==carPrice( R.car_id)&&CC.ed.tm_mday==R.ed.tm_mday&&CC.ed.tm_mon==R.ed.tm_mon)
        {
            strcpy(R.cust_name,CC.cust_name);
            strcpy(R.car_name,getCarName(R.car_id));
             found=1;

            break;
        }
        else
            found=0;

}

gotoxy(1,row+6);
textcolor(GREEN);

gotoxy(1,row+7);
textcolor(WHITE);

textcolor(GREEN);

if(found==1)
  {
      //you have to pass endDate not ed;
       R.pay=price(R.sd,R.endDate,pay);
        printf("You have to pay : %d",R.pay);
        getch();
      fwrite(&R,sizeof(R),1,fp1);
       fclose(fp2);
         fclose(fp1);
         textcolor(LIGHTBLUE);




          updateCarCount1(R.car_id);
     int ch= modifyCarRecord(R.sd,R.ed,R.car_id);

        gotoxy(1,row+10);
        if(ch==1)

                            {
                                textcolor(GREEN);

                                printf("Successfully returned  the CAR");
                                getch();
                            }

                            else if(ch==2)
                            {
                                textcolor(RED);
                                printf("Sorry ! Error in deletion");
                                getch();
                            }
                            else if(ch==0)
                            {
                                textcolor(RED);
                                printf("CAR Id not found");
                                getch();
                            }
                          }

fclose(fp1);
fclose(fp2);
return found;



        }
void returnCarDetails()
{
clrscr();
gotoxy(32,2);
textcolor(RED);
printf("CAR RENTAL SYSTEM");
gotoxy(1,3);
int i;
FILE *fp=fopen("returncar.bin","rb");
if(fp==NULL)
{
    gotoxy(30,20);
    textcolor(RED);
    printf("No!Car Rent till now!!");
    getch();
    return NULL;
}
textcolor(YELLOW);
for(i=0;i<80;i++)
    printf("%c",247);
gotoxy(30,5);
printf("* RETURN CAR DETAILS *");
textcolor(YELLOW);
gotoxy(1,7);
for(i=0;i<80;i++)
    printf("%c",247);
    textcolor(YELLOW);
gotoxy(1,9);
for(i=0;i<80;i++)
    printf("%c",247);
    textcolor(LIGHTCYAN);
    gotoxy(1,8);
printf("C_id");
gotoxy(7,8);
printf("Return date");
gotoxy(20,8);
printf("Start date");
gotoxy(32,8);
printf("Excepted E_Date");
gotoxy(45,8);
printf("Car Name");
gotoxy(60,8);
printf("Cus_Name");
gotoxy(70,8);
printf("Amount");
int row=10;

Return_CAR_DETAILS R;
while(fread(&R,sizeof(R),1,fp)==1)
{
    gotoxy(1,row);
    printf("%d",R.car_id);
    gotoxy(7,row);
    printf("%d/%d/%d",R.endDate.tm_mday,R.endDate.tm_mon,R.endDate.tm_year);
    gotoxy(20,row);
    printf("%d/%d/%d",R.sd.tm_mday,R.sd.tm_mon,R.sd.tm_year);
    gotoxy(32,row);
    printf("%d/%d/%d",R.ed.tm_mday,R.ed.tm_mon,R.ed.tm_year);
    gotoxy(45,row);
    printf("%s",R.car_name);
    gotoxy(60,row);
    printf("%s",R.cust_name);
       gotoxy(70,row);
     printf("%d",R.pay);

    row++;

}


getch();
fclose(fp);
return ;

}
int modifyCarRecord(struct tm sdd,struct tm edd,int c)
{


    FILE *fp1,*fp2;
    fp1=fopen("customer.bin","rb");
    if(fp1==NULL)
    {
        printf("Sorry!No car exist");
        getch();
        return NULL;
    }
    fp2=fopen("temp.bin","wb+");
    if(fp2==NULL)
    {
        printf("Sorry!can't create file");
        getch();
        return NULL;
    }
    int found=0;
    Customer_Car_Details C;


    while(fread(&C,sizeof(C),1,fp1)==1)
    {
        if(C.car_id!=c)
        {

            fwrite(&C,sizeof(C),1,fp2);
        }
    else if(C.car_id==c&&(C.sd.tm_mday!=sdd.tm_mday||C.ed.tm_mday!=edd.tm_mday))
            {

                fwrite(&C,sizeof(C),1,fp2);

            }


        else if(C.car_id==c &&C.sd.tm_mon==sdd.tm_mon&&C.sd.tm_mday==sdd.tm_mday&&C.ed.tm_mday==edd.tm_mday)
            {

                found=1;
            }



     }
    fclose(fp1);
    fclose(fp2);
     if(found==0)
        {

            remove("temp.bin");
        }
     else if (found==1)
     {
         int result;
         result=remove("customer.bin");
         if(result!=0)
            {
                gotoxy(32,17);
                perror("");
                getch();
            return 2;
            }
         result=rename("temp.bin","customer.bin");
         if(result!=0)
            {
                gotoxy(32,17);
                perror("");
                getch();
    return 2;
            }

     }
     return found;
  getch();
}






