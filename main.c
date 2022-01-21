#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include"Car.h"
int main()
{
    addAdmin();
    int i, role,k,ch;
    User *usr;
    for(;;)
        {
            clrscr();

    gotoxy(32,12);
    textcolor(GREEN);
    printf("WELCOME TO CAR RENTAL SYSTEM");
    textcolor(YELLOW);
    gotoxy(25,15);

    printf("* RENT A CAR AND GO WHEREVER YOU NEED *");
    getch();
    clrscr();
    gotoxy(32,1);
    textcolor(GREEN);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,8);
    textcolor(LIGHTCYAN);
    for(i=0;i<80;i++)
        printf("%c",247);
         gotoxy(1,17);
    textcolor(LIGHTCYAN);
    for(i=0;i<80;i++)
        {
            printf("%c",247);
        }
        textcolor(YELLOW);
        gotoxy(32,10);
        printf("1.Admin");
        gotoxy(32,12);
        printf("2.Employee");
        gotoxy(32,14);

    printf("3.Quit");

        for(;;)
        {

            gotoxy(32,16);
        textcolor(LIGHTCYAN);

        printf("Select your role:");
            textcolor(WHITE);
            scanf("%d",&role);
            if(role==1)
            {

                      do{


                usr=getInput();

                if(usr!=NULL)
                   k=checkUserExist(*usr,"admin");

                else
                    {
                        break;
                    }
                    if(k==1)
                    {

                        clrscr();
                        for(;;)
                            {
                                clrscr();
                        ch=adminMenu();
                        if(ch==7)
                        {

                            gotoxy(32,20);
                            textcolor(GREEN);
                            printf("Thank You !");
                            getch();
                            break;

                        }
                        switch(ch)
                        {
                        case 1:
                            addEmployee();
                            break;
                        case 2:
                            clrscr();
                            addCarDetails();
                            break;
                        case 3:
                            clrscr();
                            viewEmployee();
                            break;
                        case 4:
                            clrscr();
                            showCarDetails();
                            break;
                        case 5:

                            k=deleteEmp();
                            gotoxy(32,17);
                            textcolor(GREEN);
                            if(k==1)
                            {
                                printf("Successfully deleted the Employee");
                                getch();
                            }

                            else if(k==2)
                            {
                                printf("Sorry ! Error in deletion");
                                getch();
                            }
                            else if(k==0)
                            {
                                printf("Employee Id not found");
                                getch();
                            }
                            break;
                        case 6:
                            ch=deleteCarModel();
                            gotoxy(32,17);
                            textcolor(GREEN);

                            if(ch==1)
                            {
                                printf("Successfully deleted the CAR");
                                getch();
                            }

                            else if(ch==2)
                            {
                                printf("Sorry ! Error in deletion");
                                getch();
                            }
                            else if(ch==0)
                            {
                                printf("CAR Id not found");
                                getch();
                            }
                             break;
                        default:
                              gotoxy(32,22);
            textcolor(LIGHTRED);
            printf("Invalid Choice");
            getch();
            gotoxy(32,22);

            printf("\t\t\t\t\t\t");
            gotoxy(32,18);

             printf("\t\t\t\t\t\t");

                        }
                    }
                    }
                    if(ch==7)
                        break;

                   }while(k==0);
                   if(usr==NULL)
                    break;

          if(ch==7)
          break;
            if(k==-1)
                break;
           }
           else if(role==2)
           {
               do
                {
            usr=getInput1();

            if(usr!=NULL)
            {
            k=checkUserExist1(*usr,"emp");
            }
            else
                break;

                 if(k==1)


                      {
                          clrscr();
                         do{
                                clrscr();
                      ch=empMenu();


                      if(ch==7)
                        {
                            gotoxy(32,20);
                            textcolor(GREEN);
                            printf("Thank you!!");
                            getch();

                        break;
                        }
                      switch(ch)
                      {
                        case 1:
                            clrscr();

                            k =rentCar();
                              if(k==0)

                                 {
                                     textcolor(LIGHTRED);
                                 gotoxy(35,20);
                                 printf("Sorry!all cars booked..Try later...");
                                  getch();
                                 }
                                 else if (k==-2)
                                 {
                                     gotoxy(35,20);
                                     textcolor(LIGHTRED);
                                     printf("You did not choose any car!");
                                     gotoxy(1,21);
                                     textcolor(WHITE);
                                     printf("Press any key to go back!!");
                                     getch();
                                }

                             break;
                        case 2:
                            clrscr();
                            bookCarDetails();
                            break;
                        case 3:
                            clrscr();
                           availableCarDetails();
                                   break;
                         case 4:
                            clrscr();
                            allCarDetails();
                            break;


                        case 5:
                        k=returnCar();


                        if(k==1)
                            {
                   textcolor(GREEN);
                   gotoxy(32,23);
                   printf("Car return Successfully!");
                          getch();
                               }
                    else if(k==0)
                           {

                               gotoxy(12,23);
                               textcolor(RED);
                               printf("Invalid car Id/start date/end Date/pay......Please try later...");
                               getch();
                           }
                           else if(k==3)
                           {
                               gotoxy(32,23);
                               textcolor(LIGHTRED);
                               printf("You choose to Quit..");
                               getch();
                               break;
                           }


                        break;
                        case 6:
                            returnCarDetails();
                           break;
                        default:

                              gotoxy(32,22);
            textcolor(LIGHTRED);
            printf("Invalid Choice");
            getch();
            gotoxy(32,22);

            printf("\t\t\t\t\t\t");
            gotoxy(32,17);

             printf("\t\t\t\t\t\t");
             break;

                      }



                    }while(1);
                    if(ch==7)
                        break;
            }
                }while(1);
                if(usr==NULL)
                break;
                if(ch==7)
                    break;

                }




        else if(role==3)
        {
            gotoxy(32,22);
            textcolor(GREEN);
            printf("Thank you!");
            getch();
            exit(1);
        }
        else
        {
            gotoxy(32,22);
            textcolor(LIGHTRED);
            printf("Invalid Usertype");
            getch();
            gotoxy(32,22);

            printf("\t\t\t\t\t\t");
            gotoxy(32,16);

             printf("\t\t\t\t\t\t");

        }
if(ch==7)
    break;

        }

}
}
