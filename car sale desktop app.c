#include<stdio.h>

void sellCar();
void mainMenu();
void getBuyersDetails();
void getBuyCarDetails();
void carBrandSelect();
void viewCars();
void customerRecord();
void vehiclesTable();
void tablehead();
//void webView();
void viewSolds();
void pager();
void soldVehicles();
void testOne();
void accountHeader();
void viewProfitTable();
void statusReading();
void errorFile();
void msgInvalid();
void profitGraph();
void startup();
void readMe();


int globalProfitGenerator(int,int);



int globalBoughtPrice;
int globalSoldPrice;
int globalProfit;

struct soldVehicles{

    char vehicleBrand[10];
    char buyerName[15];
    char regNum[10];
    int buyerID;
    int soldPrice;
    char invoiceNum[10];
    int boughtPrice;



};

struct BuyersDetails{

    //int buyerIndex;
    char buyerName[100];
    int buyerID;
    int buyerMobile;
    char buyerChoice[10];
    char yesOrno[4];
    int carPrice;
    char invoiceNum[10];

};

struct BuyCar{

    char mode[10];
    char brand[10];
    char condition[10];
    int YOM;
    int vehiclePrice;
    char bodyType[10];
    char regNum[10];

};

int main(){

    startup();
    //viewSolds();
    //webView();
    //errorFile();
    //profitGraph();
    //statusReading();
    mainMenu();

    return 0;

}

void mainMenu(){

        int selectList;

    printf("Enter the following numbers to get service.\n\n");

    printf("[1]- Sell Cars\n");
    printf("[2]- Buy Cars\n");
    printf("[3]- Car Details\n");
    printf("[4]- Financial Details\n");
    printf("[5]- View Customer Details\n\n\n");
    printf("[99]- Help\t");
    printf("[0]- Exit\n\n");

    //list items

    for(int count = 0; count >= 0; count++){

        printf("Enter following number here : ");
        scanf("%d",&selectList);

        switch (selectList){

    case 1:
        printf("Sell Cars\n");

        sellCar();

        break;
    case 2:
        printf("Buy Cars\n");
        getBuyCarDetails();
        break;
    case 3:
        viewCars();
        pager();
        break;
    case 4:
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t---CUSTOMER RECORD---\n");

        customerRecord();
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t---ACCOUNT RECORDS---\n");
        viewProfitTable();
        //viewCars();
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t---SOLD CAR RECORDS---\n");
        viewSolds();
        pager();
        break;
    case 5:
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t---CUSTOMER RECORD---\n");
        customerRecord();

        pager();
        break;
    case 0:
        exit(1);
        break;
    case 99:

        readMe();

        pager();
        break;
    default:
        //printf("invalid input! try again.\n");
        msgInvalid();
        break;

        } //main-menu

        if(selectList == 1 || selectList == 2 || selectList == 3 || selectList == 4 || selectList == 5 || selectList == 0 || selectList == 99)
            break;
        else{

            continue;

        }






    }

}

void sellCar(){

    int selectList;
    int pageviewer;

    printf("\n\n---Sell A Car---\n\n");

    printf("[1]- View Details\n");
    printf("[2]- Get Buyer\'s Details\n\n");
    printf("[0]- Back to the main menu\t");
    printf("[99]- Help\n\n");

    for(int count = 0; count >= 0; count++){

        printf("Enter following number here : ");
        scanf("%d",&selectList);

        switch(selectList){

    case 1:

        printf("\n\n\n");
        viewCars();
        printf("\n\n\n[0]- [Back]\t[1]-[Main menu]\t\t[99]- [Exit]\n\n\n");


        for(int count = 0; count >= 0; count++){

        printf("Enter following number here : ");
        scanf("%d",&pageviewer);

        switch(pageviewer){

        case 0:
            sellCar();
            break;

        case 1:
            mainMenu();
            break;

        case 99:

            exit(1);
        }

        }//pager

        break;
    case 2:
        getBuyersDetails();
        printf("\n\n\n");
        customerRecord();
        printf("\n\n\n");
        viewCars();
        printf("\n\n\n");
        soldVehicles();
        printf("\n\n\n");

        profitGraph();

        //testOne();
        //printf("\n\n\n");
        //printf("Profit : %d",globalProfitGenerator(globalSoldPrice,globalBoughtPrice));
        //printf("\n\n\n");
        pager();
        break;
    case 0:
        printf("0\n");
        mainMenu();
        break;
    case 99:
        readMe();
        pager();
        break;
    default:

        msgInvalid();

        } //menu - sell a car

        //break;

        if(selectList == 1 || selectList == 2 || selectList == 0 || selectList == 99){

            break;

        }
        else{

            continue;

        }



    }

}

void getBuyersDetails(){


    int yesNo;
    char name[100];
    char service[10];

    struct BuyersDetails buyerDummy;

    FILE * buyerDetails = fopen("customer details.txt","a");

    if(buyerDetails==NULL)
        errorFile();
        //printf("Error : file cant open!\nproblem exists here\n");

    // invoice Num | name | id | mobile | vehicle | car price | after service |

    printf("\nEnter the invoice number here : ");
    scanf("%s",buyerDummy.invoiceNum);



    printf("Enter buyer\'s first name here : ");
    scanf("%s",buyerDummy.buyerName);

    //strcpy(buyerDummy.buyerName,name);

    printf("Enter buyer\'s ID number here : ");
    scanf("%d",&buyerDummy.buyerID);

    printf("Enter buyer\'s mobile number here : ");
    scanf("%9d",&buyerDummy.buyerMobile);

    printf("Enter buyer\'s choice here : ");
    scanf("%s",buyerDummy.buyerChoice);

    printf("Enter the vehicle selling price here : ");
    scanf("%d",&buyerDummy.carPrice);

    printf("\n---After Service---\n");
    printf("[1]- Yes\t");
    printf("[0]- No\n\n\n");



    for(int count = 0; count >= 0; count++){

    printf("Enter following number here : ");
    scanf("%d",&yesNo);

    switch(yesNo){

    case 0:
        printf("\nstatus : No After Service!\n");
        strcpy(buyerDummy.yesOrno,"No");
        //service[10] = "No";
        break;

    case 1:
        printf("\nstatus : After Service is exist!\n");
        strcpy(buyerDummy.yesOrno,"Yes");
        //service[10] = "Yes";
        break;

    default:
        //printf("Invalid input! Try again\n");
        msgInvalid();
        break;

    }

    if(yesNo == 1 || yesNo == 0){

        break;

    }
    else{

        continue;

    }


    }// get status - yes/no



    // invoice num | name | id | mobile | vehicle | car price | after service |

    fprintf(buyerDetails,"%s\t",buyerDummy.invoiceNum);
    fprintf(buyerDetails,"%dV\t",buyerDummy.buyerID);
    fprintf(buyerDetails,"+94%d\t\t",buyerDummy.buyerMobile);
    fprintf(buyerDetails,"%s\t\t\t",buyerDummy.buyerChoice);
    fprintf(buyerDetails,"$%d\t\t",buyerDummy.carPrice);
    fprintf(buyerDetails,"%s\t",buyerDummy.yesOrno);
    fprintf(buyerDetails,"%s\n",buyerDummy.buyerName);

    fclose(buyerDetails);



}

void getBuyCarDetails(){

    int selectList;

    struct BuyCar buyCarDummy;

    FILE * ownVehicles = fopen("own Vehicles.txt","a");
    // brand | car mode | condition | yom | vehicle price

    printf("\nChoose a vehicle brand--\n\n\n");
    printf("[1]- MAZDA\n");
    printf("[2]- HONDA\n");
    printf("[3]- TOYOTA\n");
    printf("[4]- KIA\n");
    printf("[5]- NISSAN\n");
    printf("[6]- AUDI\n");
    printf("[7]- SUZUKI\n");
    printf("[8]- BENZ\n");
    printf("[9]- MG\n\n");

    printf("[0]- [Back]\t");
    printf("[1]- [Add]\n\n\n");



    for(int count = 0; count >= 0; count++){

    printf("Enter [0] or [1] for make process here : ");
    scanf("%d",&selectList);

    switch(selectList){

    case 0:
        mainMenu();
        break;

    case 1:
        carBrandSelect();

        //start

        int myList;

    for(int count = 0; count >= 0; count++){

        printf("\nEnter following number ([1]-[9]) from the list here : ");
        scanf("%d",&myList);

        switch(myList){

        case 1:
            printf("Vehicle Brand - MAZDA\n");
            strcpy(buyCarDummy.brand,"MAZDA");
            break;

        case 2:
            printf("Vehicle Brand - HONDA\n");
            strcpy(buyCarDummy.brand,"HONDA");
            break;

        case 3:
            printf("Vehicle Brand - TOYOTA\n");
            strcpy(buyCarDummy.brand,"TOYOTA");
            break;

        case 4:
            printf("Vehicle Brand - KIA");
            strcpy(buyCarDummy.brand,"KIA");
            break;

        case 5:
            printf("Vehicle Brand - NISSAN\n");
            strcpy(buyCarDummy.brand,"NISSAN");
            break;

        case 6:
            printf("Vehicle Brand - AUDI\n");
            strcpy(buyCarDummy.brand,"AUDI");
            break;

        case 7:
            printf("Vehicle Brand - SUZUKI");
            strcpy(buyCarDummy.brand,"SUZUKI");
            break;

        case 8:
            printf("Vehicle Brand - BENZ\n");
            strcpy(buyCarDummy.brand,"BENZ");
            break;

        case 9:
            printf("Vehicle Brand - MG\n");
            strcpy(buyCarDummy.brand,"MG");
            break;

        default:
            //printf("Invalid input! Try again\n\n\n");
            msgInvalid();
            break;

        }//switch

        if(myList == 1 || myList == 2 || myList == 3 || myList == 4 || myList == 5 || myList == 6 || myList == 7 || myList == 8 || myList == 9)
            break;

    }

        //end


        break;

    default:
        //printf("Invalid input! Try again\n\n\n");
        msgInvalid();
        break;


    }

    if(selectList == 0 || selectList == 1){

        break;


    }

    }

    printf("\n\t--- Select a Car Body Type ---\n\n\n");

    printf("[1]- Hatchback\n");
    printf("[2]- Sedan\n");
    printf("[3]- SUV\n");
    printf("[4]- Coupe\n");
    printf("[5]- Wagon\n");
    printf("[6]- Van\n");
    printf("[7]- jeep\n");

    for(int count = 0; count >= 0; count++){

        printf("\n\n\nEnter following number here : ");
        scanf("%d",&selectList);

        switch(selectList){

    case 1:
        printf("Body Type : Hatchback\n");
        strcpy(buyCarDummy.bodyType,"Hatch-B");
        break;

    case 2:
        printf("Body Type : Sedan\n");
        strcpy(buyCarDummy.bodyType,"Sedan");
        break;

    case 3:
        printf("Body Type : SUV\n");
        strcpy(buyCarDummy.bodyType,"SUV");
        break;

    case 4:
        printf("Body Type : Coupe\n");
        strcpy(buyCarDummy.bodyType,"Coupe");
        break;

    case 5:
        printf("Body Type : Wagon\n");
        strcpy(buyCarDummy.bodyType,"Wagon");
        break;

    case 6:
        printf("Body Type : Van\n");
        strcpy(buyCarDummy.bodyType,"Van");
        break;

    case 7:
        printf("Body Type : Jeep\n");
        strcpy(buyCarDummy.bodyType,"Jeep");
        break;

    default:
        //printf("Invalid input! Try again\n\n\n");
        msgInvalid();
        break;
        }

        if(selectList == 1 || selectList == 2 || selectList == 3 || selectList == 4 || selectList == 5 || selectList == 6 || selectList == 7 )
            break;
        else
            continue;

    }// select body type


    printf("Enter vehicle\'s registration number here : ");
    scanf("%s",buyCarDummy.regNum);


    printf("\n---Select car condition---\n\n\n");
    printf("[1]- Brand-New\t");
    printf("[0]- Recondition\n");

    for(int count = 0; count >= 0; count++){

        printf("Enter following number here : ");
        scanf("%d",&selectList);

        switch(selectList){

    case 0:
        printf("Condition : Recondition\n");
        strcpy(buyCarDummy.condition,"Recondition");
        break;

    case 1:
        printf("Condition : Brand-New\n");
        strcpy(buyCarDummy.condition,"Brand-New");
        break;

    default:
        msgInvalid();
        //printf("Invalid input! Try again\n");
        }

        if(selectList == 0 || selectList ==1)
            break;
    }// get condition via list

    printf("Enter YOM here : ");
    scanf("%d",&buyCarDummy.YOM);

    printf("Enter vehicle model here : ");
    scanf("%s",buyCarDummy.mode);



    printf("Enter the vehicle bought price here : ");
    scanf("%d",&buyCarDummy.vehiclePrice);

    // brand | Body Type | reg-num | condition | yom | vehicle price | model

    fprintf(ownVehicles,"%s\t",buyCarDummy.brand);
    fprintf(ownVehicles,"%s\t\t",buyCarDummy.bodyType);
    fprintf(ownVehicles,"%s\t\t",buyCarDummy.regNum);
    fprintf(ownVehicles,"%s\t",buyCarDummy.condition);
    fprintf(ownVehicles,"%d\t",buyCarDummy.YOM);
    fprintf(ownVehicles,"$%d\t\t",buyCarDummy.vehiclePrice);
    fprintf(ownVehicles,"%s\n",buyCarDummy.mode);



    fclose(ownVehicles);

    pager();

}

void viewCars(){

    char readFile[500];

    FILE * viewcar = fopen("own Vehicles.txt","r");

    if(viewcar == NULL){


        errorFile();


    }
    else{



        statusReading();



        vehiclesTable();

    }

    while(!feof(viewcar)){

        fgets(readFile,500,viewcar);
        printf("\t\t\t%s\n",readFile);

    }

    vehiclesTable();

    fclose(viewcar);

}

void carBrandSelect(){







}

void pager(){

    int pageviewer;

    printf("\n\n\n[1]-Main menu\t[99]- [Exit]\n\n\n");


    for(int count = 0; count >= 0; count++){

        printf("Enter following number here : ");
        scanf("%d",&pageviewer);

        switch(pageviewer){

            case 1:
                printf("\n");
                mainMenu();
                break;

            case 99:
                exit(1);

            default:

                msgInvalid();

                continue;
        }

    }//pager



}

void customerRecord(){

    char readFileCustomer[500];

    FILE * customer = fopen("customer details.txt","r");

    if(customer == NULL){

        errorFile();

    }
    else{

       statusReading();

    }


    tablehead();
    printf("INVOICE\tID\t\tTELEPHONE\t\tREG-NUM\t\t\tCASH\t\tSERVICE\tCUSTOMER\n");
    tablehead();


    while(!feof(customer)){

        fgets(readFileCustomer,500,customer);
        printf("%s\n",readFileCustomer);

    }


    tablehead();
    printf("INVOICE\tID\t\tTELEPHONE\t\tREG-NUM\t\t\tCASH\t\tSERVICE\tCUSTOMER\n");
    tablehead();



    fclose(customer);


}

void vehiclesTable(){


    printf("\t\t\t");

    for(int count = 1; count <= 87; count++){

        printf("_");

    }
    printf("\n");

    printf("\t\t\tBRAND\tB-TYPE\t\tREG-NUM\t\tCONDITION\tYOM\tB-PRICE\t\tMODEL\n");


    printf("\t\t\t");

    for(int count = 1; count <= 87; count++){

        printf("_");

    }
    printf("\n");

}

void tablehead(){

    for(int count = 1; count <= 107; count++){

        printf("_");

    }


    printf("\n");


}


/*
void webView(){

    char valueFile;

    FILE * sourceFile = fopen("own Vehicles.txt","r");
    FILE * generateFile = fopen("vehicles.html","a");

    if(sourceFile == NULL){

        printf("Error : File cant read!\n");

    }



    fprintf(sourceFile,"<html><head><meta http-equiv=\"refresh\" content=\"1\"><head><body><p>");
    while(1){

        valueFile = fgetc(sourceFile);
        if(valueFile == EOF)
            break;
        fputc(valueFile,generateFile);

        if(valueFile == 10)
            fprintf(generateFile,"<br>");



    }


    printf(sourceFile,"</p></body></head>");

    fclose(sourceFile);
    fclose(generateFile);

}

*/


void soldVehicles(){


    struct soldVehicles soldDummy;

    FILE * soldCar = fopen("sold vehicles.txt","a");


    printf("Enter the sold vehicle details\n\n\n");

    printf("Enter the invoice number here : ");
    scanf("%s",soldDummy.invoiceNum);



    printf("Enter the vehicle number here : ");
    scanf("%s",soldDummy.regNum);

    printf("Enter the vehicle brand\n\n\n");


    printf("\nChoose a vehicle brand--\n\n\n");
    printf("[1]- MAZDA\n");
    printf("[2]- HONDA\n");
    printf("[3]- TOYOTA\n");
    printf("[4]- KIA\n");
    printf("[5]- NISSAN\n");
    printf("[6]- AUDI\n");
    printf("[7]- SUZUKI\n");
    printf("[8]- BENZ\n");
    printf("[9]- MG\n\n");

    printf("[0]- [Back]\t");
    printf("[99]- [Main Menu]\n\n\n");


    int selectList;

    for(int count = 0; count >= 0; count++){


        printf("Enter following number here : ");
        scanf("%d",&selectList);

        switch(selectList){

        case 0:
            //to do ;
            break;

        case 99:
            mainMenu();
            break;

        case 1:
            printf("\nVehicle Brand - MAZDA\n");
            strcpy(soldDummy.vehicleBrand,"MAZDA");
            break;

        case 2:
            printf("\nVehicle Brand - HONDA\n");
            strcpy(soldDummy.vehicleBrand,"HONDA");
            break;

        case 3:
            printf("\nVehicle Brand - TOYOTA\n");
            strcpy(soldDummy.vehicleBrand,"TOYOTA");
            break;

        case 4:
            printf("\nVehicle Brand - KIA\n");
            strcpy(soldDummy.vehicleBrand,"KIA");
            break;

        case 5:
            printf("\nVehicle Brand - NISSAN\n");
            strcpy(soldDummy.vehicleBrand,"NISSAN");
            break;

        case 6:
            printf("\nVehicle Brand - AUDI\n");
            strcpy(soldDummy.vehicleBrand,"AUDI");
            break;

        case 7:
            printf("\nVehicle Brand - SUZUKI\n");
            strcpy(soldDummy.vehicleBrand,"SUZUKI");
            break;

        case 8:
            printf("\nVehicle Brand - BENZ\n");
            strcpy(soldDummy.vehicleBrand,"BENZ");
            break;

        case 9:
            printf("\nVehicle Brand - MG\n");
            strcpy(soldDummy.vehicleBrand,"MG");
            break;

        default:
            printf("\n\n\nInvalid input! Try again\n\n\n");
            break;

            }//switch


        if(selectList == 1 || selectList == 2 || selectList == 3 || selectList == 4 || selectList == 5 || selectList == 6 || selectList == 7 || selectList == 8 || selectList == 9){

            break;

        }
        else{
            continue;
        }

    }


        printf("Enter vehicle\'s bought price here : ");
        scanf("%d",&soldDummy.boughtPrice);
        globalBoughtPrice = soldDummy.boughtPrice;

        printf("Enter vehicle\'s selling price here : ");
        scanf("%d",&soldDummy.soldPrice);
        globalSoldPrice = soldDummy.soldPrice;

        printf("Enter customer\'s ID number here : ");
        scanf("%d",&soldDummy.buyerID);

        printf("Enter Customer\'s name here : ");
        scanf("%s",soldDummy.buyerName);

        // add a massage here

        printf("\n\n\nSelect a option to make a process\n\n\n");

        printf("[1]-[Add Records]\t\t\t[0]-[Cancel]\n\n\n");
        printf("Enter following number here  : ");
        scanf("%d",&selectList);

        switch(selectList){

        case 0:
            mainMenu();
            break;

        case 1:

            //INVOICE\t |ID \t | REG-NUM\t\t| BRAND\t b-Price\t S-PRICE\t CUSTOMER

            fprintf(soldCar,"%s\t",soldDummy.invoiceNum);
            fprintf(soldCar,"%dV\t",soldDummy.buyerID);
            fprintf(soldCar,"%s\t\t",soldDummy.regNum);
            fprintf(soldCar,"%s\t\t",soldDummy.vehicleBrand);
            fprintf(soldCar,"$%d\t\t",soldDummy.boughtPrice);
            fprintf(soldCar,"$%d\t\t",soldDummy.soldPrice);
            fprintf(soldCar,"%s\n",soldDummy.buyerName);


            printf("\n\n\nRecord has saved successfully!\n\n\n");

                //invoice | brand | REG-NUM | bought price | sold price | profit

                FILE * accountRecords = fopen("account records.txt","a");

                fprintf(accountRecords,"%s\t",soldDummy.invoiceNum);
                fprintf(accountRecords,"%s\t",soldDummy.vehicleBrand);
                fprintf(accountRecords,"%s\t\t",soldDummy.regNum);
                fprintf(accountRecords,"$%d\t\t",soldDummy.boughtPrice);
                fprintf(accountRecords,"$%d\t\t",soldDummy.soldPrice);
                fprintf(accountRecords,"$%d\n",globalProfitGenerator(globalSoldPrice,globalBoughtPrice));

                fclose(accountRecords);

                printf("Account has updated\n");


    }


    fclose(soldCar);

}

void testOne(){


    printf("bought price : %d\n",globalBoughtPrice);
    printf("sold price : %d\n",globalSoldPrice);


}

int globalProfitGenerator(int sold,int bought){

    int result = sold - bought;


    return result;

}

void accountHeader(){



    for(int count = 1; count <= 73; count++){

        printf("_");

    }
    printf("\n");

     //invoice | brand | REG-NUM bought price | sold price | profit
    printf("INVOICE\tBRAND\tREG-NUM\t\tBOUGHT-PRICE\tSOLD-PRICE\tPROFIT\n");


    for(int count = 1; count <= 73; count++){

        printf("_");

    }

    printf("\n");


}

void viewProfitTable(){

    char readFileConsol[500];

    FILE * viewProfitTabe = fopen("account records.txt","r");


    if(viewProfitTabe == NULL){

        //printf("Error : File can\'t found!");
        errorFile();

    }
    else{

        //printf("Status : Reading file\n\n\n");
        statusReading();

    }

    accountHeader();

    while(!feof(viewProfitTabe)){

        fgets(readFileConsol,500,viewProfitTabe);
        printf("%s\n",readFileConsol);

    }


    accountHeader();


    fclose(viewProfitTabe);

}

void statusReading(){

    printf("+");

    for(int count = 0; count <= 23; count++){

        printf("-");

    }

    printf("+\n");

    printf("| Status : Reading Files | >>\n");



        printf("+");

    for(int count = 0; count <= 23; count++){

        printf("-");

    }

    printf("+\n");


}

void errorFile(){



    printf("+");

    for(int count = 0; count <= 24; count++){

        printf("-");

    }

    printf("+\n");

    printf("| Error : File Not Found! |\n");



        printf("+");

    for(int count = 0; count <= 24; count++){

        printf("-");

    }

    printf("+\n");





}

void msgInvalid(){

    printf("\n");
    printf("+");
    for(int count = 1; count <= 26; count++){ printf("-"); }
    printf("+");
    printf("\n");
    printf("| Invalid input! Try again |\n");
    printf("+");
    for(int count = 1; count <= 26; count++){ printf("-"); }
    printf("+");
    printf("\n");
    printf("\n");



}

void profitGraph(){

    printf("+");
    for(int count = 1; count <= 38; count ++){ printf("-"); }
    printf("+");

    printf("\n| SOLD PRICE     | ");
    printf("$%d\n",globalSoldPrice);

    printf("+");
    for(int count = 1; count <= 38; count ++){ printf("-"); }
    printf("+");


    printf("\n| BOUGHT PRICE   | ");
    printf("$%d\n",globalBoughtPrice);


    printf("+");
    for(int count = 1; count <= 38; count ++){ printf("-"); }
    printf("+");

    printf("\n| NET PROFIT     | ");
    printf("$%d\n",globalProfitGenerator(globalSoldPrice,globalBoughtPrice));

    printf("+");
    for(int count = 1; count <= 38; count ++){ printf("-"); }
    printf("+");

}

void viewSolds(){

    char reads[500];

    FILE *viewSolds =  fopen("sold vehicles.txt","r");

    if(viewSolds == NULL){

        errorFile();

    }
    else{

        statusReading();

    }

    for(int count = 1; count <= 103; count++){ printf("-"); }
    printf("\n");
    printf("INVOICE\tID\t\tREG-NUM\t\tBRAND\t\tB-PRICE\t\tS-PRICE\t\tCUSTOMER\n");
    for(int count = 1; count <= 103; count++){ printf("-"); }
    printf("\n");


     while(!feof(viewSolds)){

        fgets(reads,500,viewSolds);
        printf("%s\n",reads);

    }

    for(int count = 1; count <= 103; count++){ printf("-"); }
    printf("\n");
    printf("INVOICE\tID\t\tREG-NUM\t\tBRAND\t\tB-PRICE\t\tS-PRICE\t\tCUSTOMER\n");
    for(int count = 1; count <= 103; count++){ printf("-"); }
    printf("\n");

    fclose(viewSolds);

}

void startup(){

    int loadFilse = 0;

    FILE *startCustomer = fopen("customer details.txt","r");


    if(startCustomer == NULL){

        printf("#Reading File : ERROR /not found!\t");

        FILE *customer = fopen("customer details.txt","a");

        if(customer == NULL){

            printf("RUNTIME ERROR!\n");
        }
        else{

            printf("#Reading File : Customer ~ OK\n");
            loadFilse++;

        }

        fclose(customer);

    }

    else{

        printf("#Reading File : Customer ~ OK\n");
        loadFilse++;
    }


    fclose(startCustomer);







    FILE *startVehicles = fopen("own Vehicles.txt","r");


    if(startCustomer == NULL){

        printf("#Reading File : ERROR /not found!\t");


        FILE *vehicles = fopen("own Vehicles.txt","a");

        if(vehicles == NULL){
            printf("RUNTIME ERROR!\n");
        }
        else{

            printf("#Reading File : Vehicles ~ OK\n");
            loadFilse++;

        }




        fclose(vehicles);



    }

    else{

        printf("#Reading File : Vehicles ~ OK\n");
        loadFilse++;

    }


    fclose(startVehicles);











    FILE *startSolds = fopen("sold vehicles.txt","r");


    if(startCustomer == NULL){

        printf("#Reading File : ERROR /not found!\t");


        FILE *Soldvehicles = fopen("sold vehicles.txt","a");


        if(Soldvehicles == NULL){
            printf("RUNTIME ERROR!\n");
        }
        else{


            printf("#Reading File : SoldCars ~ OK\n");
            loadFilse++;

        }





        fclose(Soldvehicles);


    }

    else{

        printf("#Reading File : SoldCars ~ OK\n");
        loadFilse++;
    }


    fclose(startSolds);















    FILE *startAccounts = fopen("account records.txt","r");


    if(startCustomer == NULL){

        printf("#Reading File : ERROR /not found!\t");

        FILE *acc = fopen("account records.txt","a");

        if(acc == NULL){
             printf("RUNTIME ERROR!\n");
        }
        else{
             printf("#Reading File : Accounts ~ OK\n");
             loadFilse++;
        }


        fclose(acc);


    }

    else{

        printf("#Reading File : Accounts ~ OK\n");
        loadFilse++;

    }


    fclose(startAccounts);



    printf("+");
    for(int count = 1; count <= 67; count++){ printf("-"); }
    printf("+");


    printf("\n|  #%d/4 Files were loaded    |",loadFilse);

    if(loadFilse == 4){
        printf("    Program has loaded successfully!  |\n");
    }
    printf("+");
    for(int count = 1; count <= 67; count++){ printf("-"); }
    printf("+");


    printf("\n\n\n");



}

void readMe(){


    for(int count = 1; count <=120; count++){ printf("-"); }

    printf("\n\n\n\tHELP :\n");
    printf("\t#List numbers will helpful for make process.\n");
    printf("\t#Page numbers like [0], [1], [99] will help to move back, mainmenu , add records something like that.\n");
    printf("\t(there are various options that you can hadle)\n");
    printf("\t#After enter a details of record user can see and check all records clearly\n");
    printf("\t#It there is a mistake with entered details, user supposed to delete the record manually\n\n\n");
    printf("\tNOTE :\n");
    printf("\t#After selling a car, it will automatically write in another different location (under \'sold car\')\n\tthen user supposed to delete those records from \'own Vehicles.txt\'\n");
    printf("\t#Add telephone number without \'0\' in first.\n");
    printf("\t#Add ID number without \'V\' in last.\n");
    printf("\t#Add all prices in dollars.(not need to add dollar mark. It will add automatically.)\n");
    printf("\t#Use backup yourself.\n");
    printf("\t#Use password to reach those files.\n\n\n");
    printf("\tall rights reserved | navodhosts@gmail.com\n");


    for(int count = 1; count <=120; count++){ printf("-"); }


}

