#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include<time.h>
#include"Car.h"

struct User
{
    char userid[20];
    char pwd[20];
    char name[20];
};
struct Car
{
    int car_id;
    int car_price;
    char car_name[20];
     int car_count;
    int capacity;

};
struct Customer_Car_Details
{
   int car_id;
    char pick[30];
    char drop[30];
    char cust_name[30];
    struct tm sd;
     struct tm ed;


};
struct Return_CAR_DETAILS
{
    int car_id;
    struct tm ed;
char cust_name[20];
struct tm sd;
struct tm endDate;
char car_name[20];
int pay;

};
typedef struct Return_CAR_DETAILS Return_CAR_DETAILS;

typedef struct User User;
typedef struct Car Car;
typedef struct Customer_Car_Details Customer_Car_Details;
int adminMenu();
void addEmployee();
void addCarDetails();
void showCarDetails();
void viewEmployee();
void addAdmin();
int  deleteEmp();
User* getInput();
User* getInput1();
int deleteCarModel();
int checkUserExist(struct User  ,char *);
int checkUserExist1(struct User ,char *);
char *getCarName(int);
int empMenu();
int  selectCarModel();
int isValidDate(struct tm);
void updateCarCount(int);
void bookedCarDetails(int);
int  rentCar();
void availableCarDetails();
void allCarDetails();
void bookCarDetails();
int returnCar();
void returnCarDetails();
int carPrice(int);
void updateCarCount1(int);
int price(struct tm,struct tm,int);
int isValidDate1(struct tm);
#endif // CAR_H_INCLUDED
