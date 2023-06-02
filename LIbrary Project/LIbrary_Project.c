#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>

#define MAX_BOOK 1000                                  //Max book that can be added to library (Changeable)
#define MAX_MEM  100                                   //Max members that can register in library (Changeable)

void registration();                                   //This function is for taking members Registration in Library
void add_books();                                      //Function for Adding book details in the library
void display_ids();                                    //Function for display Registered student details
void display_all_books();                              //function for display all book information in the library
void listbook_by_author();                             //List all book available in library with a given author
void bookname_from_isbn();                             //List the perticular book for a given ISBN
void bookcount();                                      //display how many of a perticular book available right now
void issue_by_isbn();                                  //Book issue by a given ISBN (Registration in Library Required).It will ask for enter roll no.
void issue_by_book();                                  //Book issue by a given Book Name (Registration in Library Required).It will ask for enter roll no.
void sort_ISBN();                                      //Sort all books available in library by ISBN number

FILE *fptric ;                                         //file pointer to idcount.txt
FILE *fptrbc ;                                         //file pointer to bookcount.txt
FILE *fptr_b;                                          //file pointer to books information in file books.txt
FILE *fptr_i;                                          //file pointer to identity information in fle identity.txt

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct{                                        //Structure for Library Registration Information
    char name[30];
    char roll[15];
} idcard;

int id=0;                                              //Track the registration when a new student Register (no of ids = no of registrations)
idcard card[MAX_MEM];                                  //declaration of the structure array that holds student information

void registration(){
    
    fptric=fopen("idcount.txt","r");                                   //open the file idcount.txt in read mode where count of initial id information store
    if(fptric==NULL){
        printf("\nFailed to Open File (idcount)");
        exit(1);                                                       //abnormal termination of program if the file unable to open
    } 
    fscanf(fptric,"%d",&id);                                           //store the no of identity count in the varible id from the file
    fclose(fptric);

    id++;                                                              //the id varible increses by one when a new registration entered

    printf("\nInformation required -> 1.NAME 2.RollNo");   
        
        idcard card0;                                                 //card0 is a structure varible that takes the input of the new registration
        printf("\n\nEnter your name --> ");
        fflush(stdin);
        scanf("%[^\n]",card0.name);
        printf("\nEnter your roll no. --> ");
        fflush(stdin);
        scanf("%s",card0.roll);
    
    fptr_i=fopen("identity.txt","a");                                 //open the file identity.txt in append mode to store the new data
    if(fptr_i==NULL){
        printf("\nFailed to Open File (identity)");
        exit(2);                                                      //abnormal termination of program if the file unable to open
    }
    fwrite(&card0,sizeof(card0),1,fptr_i);                            //writre the new registration data in the database
    fclose(fptr_i);

    fptric=fopen("idcount.txt","w");                                  //again opn the idcount file in write mode to store the new identity count
    if(fptric==NULL){
        printf("\nFailed to Open File (idcount)");                    //abnormal termination of program if the file unable to open
        exit(1);                                                      
    }
    fprintf(fptric,"%d",id);                                          //write the new value of id in database
    fclose(fptric);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)                                                        //Packing the structure for avoid padding
typedef struct{                                                        //structure for books information
    long isbn;
    char bname[50];                                                    //book name
    char aname[50];                                                    //author name
    float price;
    int pages;
    int stock; 
    bool flag;                                                         //flag indicates the book is available for issue or not
} library;
#pragma pack()


int count = 0;                                                         //Track the registration when a new student Register (no of ids = no of registrations)
library book[MAX_BOOK];                                                //declaration of the structure array that holds book information


void add_books(){  

    printf("\n");
    printf("\nEnter The book Details\n");
    char another2 = 'Y';                                              //another varible stores the while loop condition
    
    fptrbc=fopen("bookcount.txt","r");                                //open the file bookcount.txt in read mode where count of initial book information store
    if(fptrbc==NULL){
        printf("\nFailed to Open File (bookcount)");
        exit(1);                                                      //abnormal termination of program if the file unable to open
    }
    fscanf(fptrbc,"%d",&count);                                       //store the no of no of book count in the varible count from the file
    fclose(fptrbc);

    while(another2=='Y'){                                             //The while loop continue to take book information when the input choise is Y
        count++;                                                      //the count varible increses by one every time when a new book information entered
        library book0;                                                //book0 is a structure varible that takes the input of the new book information
        
            printf("\nEnter the ISBN no of the Book = ");
            fflush(stdin);
            scanf("%ld",&book0.isbn);
            printf("\nEnter the Book name = ");
            fflush(stdin);
            scanf("%[^\n]",&book0.bname);
            printf("\nEnter the Author name  = ");
            fflush(stdin);
            scanf("%[^\n]",&book0.aname);
            printf("\nEnter price of the book = ");
            fflush(stdin);
            scanf("%f",&book0.price);
            printf("\nEnter pages of the book = ");
            fflush(stdin);
            scanf("%d",&book0.pages);
            printf("\nEnter Number of the books in stock = ");
            fflush(stdin);
            scanf("%d",&book0.stock);
            printf("\nMark the book is available for issue or not by flag(0/1) = ");
            fflush(stdin);
            scanf("%d",&book0.flag);
        
        printf("\nAnother Book details ? Enter capital Y for Yes any other for No = ");   
        fflush(stdin);
        another2=getchar();                                            //If the choice is Y it will take another book information

        fptr_b=fopen("books.txt","a");                                 //open the file books.txt in append mode to store the new data
        if(fptr_b==NULL){
            printf("\nFailed to Open File (books)");
            exit(2);                                                   //abnormal termination of program if the file unable to open
        }
        fwrite(&book0,sizeof(book0),1,fptr_b);                         //write the new book data in the database    
        fclose(fptr_b); 

    }
    fptric=fopen("bookcount.txt","w");                                 //again open the bookcount.txt file in write mode to store the new book count
    if(fptrbc==NULL){
        printf("\nFailed to Open File (bookcount)");
        exit(3);
    }
    fprintf(fptrbc,"%d",count);                                        //write the new value of id in database
    fclose(fptrbc);
    

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void display_ids(){                 
    
    int i;                                                            //varible n stores the id count 
    fptric=fopen("idcount.txt","r");                                  //open idcount.txt in read mode 
    if(fptric==NULL){
        printf("\nFailed to Open File (idcount)");
        exit(1);
    }
    fflush(stdin);
    fscanf(fptric,"%d",&i);                                          //import the value of id count from the file idcount.txt
    fclose(fptric);

    fptr_i=fopen("identity.txt","r");                                //open the file identity.txt in read mode
    if(fptr_i==NULL){
        printf("\nFailed to Open File (identity)");
        exit(2);
    }
    for(int j=0;j<i;j++){                                           //import the registered ids from database to the card structure
        fread(&card[j],sizeof(card),1,fptr_i);
    }
    fclose(fptr_i);
    

    printf("\nEnter Security Password for displaying registered member's details -> ");
    char s[20]; 
    fflush(stdin);                                                   //varible s stores the password entered
    scanf("%s",s);
    if(i==0)printf("\n0 member Registered\n");
    else if(strcmp(s,"knox1220")==0){                              //if the password matches it display the registered members information
        printf("\nRegistered id in the database :-> ");   
        for(int k=0;k<i;k++){
            printf("\nMember [%d] -> NAME = %-16s  RollNo. = %s",(k+1),card[k].name,card[k].roll);
            fflush(stdin);
        }
        printf("\n\n");
    }
    else{
        printf("\nWrong Password entered");
    }
    
    
}

void display_all_books(){                                          //function for displaying library stock
    
    int n;                                                        //n will store the value of book information available
    fptrbc=fopen("bookcount.txt","r");                            //open bookcount.txt in read mode
    if(fptrbc==NULL){
        printf("\nFailed to Open File (bookcount)");
        exit(1);
    }
    fscanf(fptrbc,"%d",&n);                                       //import thr value of no of book information from bookcount.txt to varible n
    fclose(fptrbc);

    fptr_b=fopen("books.txt","r");                                //open the file books.txt where the all book information stored
    if(fptr_b==NULL){
        printf("\nFailed to Open File (books)");
        exit(2);                                                  
    }
    for(int j=0;j<n;j++){
        fread(&book[j],sizeof(book),1,fptr_b);                   //import all the book information from database to the structure array book[n]
    }
    fclose(fptr_b);

    if(n==0)printf("\nNo book Available in Library ^_^\n");                    
    else{
        printf("\n\n#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#___Displaying All Books___#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#\n\n");
        for(int j=0;j<n;j++){                                  //iterate through all the structure array card[id]
            printf("BOOK[%d] -> ISBN = %d  Book Name = %-21s  Author name = %-14s  Price = %.2f  Pages = %d  In_Stock = %d\n",(j+1),book[j].isbn,book[j].bname,book[j].aname,book[j].price,book[j].pages,book[j].stock);
        }
    }
    
}

void listbook_by_author(){                                        //function for list all books by a given author

    int n;                                                        //n will store the value of book information available
    fptrbc=fopen("bookcount.txt","r");                            //open bookcount.txt in read mode
    if(fptrbc==NULL){
        printf("\nFailed to Open File (bookcount)");
        exit(1);
    }
    fscanf(fptrbc,"%d",&n);                                       //import the value of bookcount in n
    fclose(fptrbc);

    fptr_b=fopen("books.txt","r");                                //open the books.txt file in read mode
    if(fptr_b==NULL){
        printf("\nFailed to Open File (books)");
        exit(2);
    }
    for(int j=0;j<n;j++){                                         //import the registered book details from database to structure array book[n]
        //fscanf(fptr_i,"%[^,],%[^,]\n",card[j].name,card[j].roll);
        fread(&book[j],sizeof(book),1,fptr_b);
    }

    char str[50];                                                 //str will store the author name entered
    printf("\nEnter the Author name = ");                         //enter author name ignoring the case but space and spell must be accurate
    fflush(stdin);
    scanf("%[^\n]",str);
    printf("\nBooks written by [%s] are = ",str);
    for(int j=0;j<n;j++){                                         //iterrating throught book[n] to find the books written by given author
        if(strcmpi(str,book[j].aname)==0){
            printf("    %s    |",book[j].bname);
        }
    }
    printf("   - End of List\n");
}

void bookname_from_isbn(){                                        //function for find bookname with isbn

    int n;                                                        //n will store the value of book information available
    fptrbc=fopen("bookcount.txt","r");                            //open bookcount.txt in read mode
    if(fptrbc==NULL){
        printf("\nFailed to Open File (bookcount)");
        exit(1);
    }
    fscanf(fptrbc,"%d",&n);                                       //import the value of bookcount in n
    fclose(fptrbc);

    fptr_b=fopen("books.txt","r");                                //open the books.txt file in read mode
    if(fptr_b==NULL){
        printf("\nFailed to Open File (books)");
        exit(2);
    }
    for(int j=0;j<n;j++){                                         //import the registered book details from database to structure array book[n]
        fread(&book[j],sizeof(book),1,fptr_b);
    }

    long isb;                                                     // will store the ISBN entered
    printf("\nEnter the ISBN (If ISBN Wrong it will take to the Library Handler) -> ");
    scanf("%ld",&isb);
    if(n==0)printf("\nNo Book Available in Library\n");
    for(int j=0;j<n;j++){                                         //iterrating throught book[n] to find the book of that ISBN
        if(isb==book[j].isbn){
            printf("\nAuthor = %s  Book Name = %s\n",book[j].aname,book[j].bname);
        }
    }
}

void bookcount(){                                                   //function for display how many books available in library

    int n;                                                          //n will store the number of book information available
    fptrbc=fopen("bookcount.txt","r");                              //open bookcount.txt in read mode
    if(fptrbc==NULL){
        printf("\nFailed to Open File (bookcount)");
        exit(2);
    }
    fscanf(fptrbc,"%d",&n);                                         //import the value of bookcount in n
    fclose(fptrbc);

    fptr_b=fopen("books.txt","r");                                  //open the books.txt file in read mode
    if(fptr_b==NULL){
        printf("\nFailed to Open File (books)");
        exit(1);
    }
    for(int j=0;j<n;j++){                                           //import the registered book details from database to structure array book[n]
        //fscanf(fptr_i,"%[^,],%[^,]\n",card[j].name,card[j].roll);
        fread(&book[j],sizeof(book),1,fptr_b);
    }
    fclose(fptr_b);

    int sum = 0;                                                   //varible sum will store the total books available
    for(int j=0;j<n;j++){
        if(book[j].stock > 0){                                     //iterate over the structure array book[count]
            sum+=book[j].stock;
        }
        printf("\nBook[%d] -> %-22s in Stock -> %d",(j+1),book[j].bname,book[j].stock);
    }
    printf("\n\nTotal Book available right now = %d\n\n",sum);

}

void issue_by_isbn(){                                                    //Book issue by a given ISBN (Registration in Library Required).It will ask for enter roll no.

    int i;                                                               //i will store the number of book information available 
    fptric=fopen("idcount.txt","r");                                     //open idcount.txt in read mode
    if(fptric==NULL){
        printf("\nFailed to Open File (idcount)");
        exit(1);
    }
    fscanf(fptric,"%d",&i);                                              //import the value of idcount.txt in i
    fclose(fptric);

    fptr_i=fopen("identity.txt","r");                                    //open the identity.txt file in read mode
    if(fptr_i==NULL){
        printf("\nFailed to Open File (identity)");
        exit(2);
    }
    for(int j=0;j<i;j++){                                               //import the registered identity details from database to structure array card[i]
        //fscanf(fptr_i,"%[^,],%[^,]\n",card[j].name,card[j].roll);
        fread(&card[j],sizeof(card),1,fptr_i);
    }
    fclose(fptr_i);

    int n;                                                              //n will store the number of book information available
    fptrbc=fopen("bookcount.txt","r");                                  //open bookcount.txt in read mode
    if(fptrbc==NULL){
        printf("\nFailed to Open File (bookcount)");
        exit(2);
    }
    fscanf(fptrbc,"%d",&n);                                             //import the value of bookcount in n
    fclose(fptrbc);

    fptr_b=fopen("books.txt","r");                                      //open the books.txt file in read mode
    if(fptr_b==NULL){
        printf("\nFailed to Open File (books)");
        exit(1);
    }
    for(int j=0;j<n;j++){                                              //import the registered book details from database to structure array book[n]
        fread(&book[j],sizeof(book),1,fptr_b);
    }
    fclose(fptr_b);

    long isbnc;                                                        //isbnc varible will stores the isbn entered
    char rolln[15];                                                    //rolln varible will stores the roll no entered
    printf("\nEnter Roll No. = ");
    fflush(stdin);
    scanf("%s",rolln);
    bool flag=0;                                                       //flag varible track if you are registerd in library or not
    if(n==0){
        printf("\nNo book Available in Library ^_^\n");
        flag=1;
    }

    for(int j=0;j<i;j++){                                               //iterate over the structure array card[i] for match roll no

        if(strcmpi(rolln,card[j].roll)==0){                             // check for roll no is registered or not
            flag=1;
            char another3='Y';

            issue_section:                                              //lebel for book issue section

            while(another3=='Y'){

                printf("\nEnter the ISBN Number = ");
                scanf("%ld",&isbnc);
                bool fg=0;                                              //varible fg track if you entered right isbn or not

                for(int k=0;k<n;k++){                                   //iterate over the structure array book[n]                                 
                    if((isbnc==book[k].isbn) && (book[k].stock>0) && (book[k].flag==1)){    // if the book issue condition is matched it issued the book and stock-=1
                        fg=1;
                        printf("\n--> [%s] book is issued for @ -> %s",book[k].bname,card[j].name);
                        time_t tm;   
                        time(&tm);
                        printf("\n\n\t\t\t\tYou issued a book at : %s", ctime(&tm));
                        printf("\n\t\t\t\t\tKindly Return it in 20 days\n");
                        getchar();
                        book[k].stock-=1;
                        break;
                    }

                    else if((isbnc==book[k].isbn) && ((book[k].stock==0) || (book[k].flag==0))){                  //if the book is not in stock or it is not available for isssueing
                        fg=1;
                        printf("\nBook is not available for issue");
                        break;
                    }

                   
                }
                if(fg==0){
                        printf("\nWrong isbn number entered");
                        goto issue_section;                                                                      //in case of wrong isbn it will take back to issue section
                        break;                         
                }
                printf("\nissued one more book ? Enter capital Y for Yes any other for No -> ");
                fflush(stdin);
                another3=getchar();
            }
        }
        
    }
    if(flag==0){                                                                                                 //if you didnt registered in library(or wrong roll no) it will take to the registration section
        printf("\nYou are Not Registered in Library\t->\tkindly Registered");
        fflush(stdin);
        getchar();
        printf("\nTaking to Registration Section");
        fflush(stdin);
        getchar();
        registration();
    }

    fptr_b=fopen("books.txt","w");                                                                               //open the books.txt file in write mode (bcoz book stock change for issuing )
    if(fptr_b==NULL)printf("\nFailed to Open File (books)");
    for(int j=0;j<n;j++){
        //fscanf(fptr_i,"%[^,],%[^,]\n",card[j].name,card[j].roll);
        fwrite(&book[j],sizeof(book),1,fptr_b);                                                                 //write the updated structure array book[n] in the database
    }
    fclose(fptr_b);

}



void issue_by_book(){                                                           //function for issuing book by book name and roll no registered 

    int i;                                                                     //here all file handling operations are same as issue by isbn
    fptric=fopen("idcount.txt","r");
    if(fptric==NULL)printf("\nFailed to Open File (idcount)");
    fscanf(fptric,"%d",&i);
    fclose(fptric);

    fptr_i=fopen("identity.txt","r");
    if(fptr_i==NULL)printf("\nFailed to Open File (identity)");
    for(int j=0;j<i;j++){
        //fscanf(fptr_i,"%[^,],%[^,]\n",card[j].name,card[j].roll);
        fread(&card[j],sizeof(card),1,fptr_i);
    }
    fclose(fptr_i);

    int n;
    fptrbc=fopen("bookcount.txt","r");
    if(fptrbc==NULL){
        printf("\nFailed to Open File (bookcount)");
        exit(1);
    }
    fscanf(fptrbc,"%d",&n);
    fclose(fptrbc);

    fptr_b=fopen("books.txt","r");
    if(fptr_b==NULL){
        printf("\nFailed to Open File (books)");
        exit(2);
    }
    for(int j=0;j<n;j++){
        //fscanf(fptr_i,"%[^,],%[^,]\n",card[j].name,card[j].roll);
        fread(&book[j],sizeof(book),1,fptr_b);
    }
    fclose(fptr_b);

    char nm[30];                                                                 //nm varible will store the book name                             
    char rolln[15];                                                              //roll no vaible will stored the roll no entered
    printf("\nEnter Roll No. = ");
    fflush(stdin);
    scanf("%s",rolln);
    
    bool fg=0;                                                                   //fg varible track if you are registerd in library or not

    if(n==0){
        printf("\nNo book Available in Library ^_^\n");
        fg=1;
    }

    for(int j=0;j<i;j++){                                                         //iterate over the structure array card[i]
                      
        if(strcmp(rolln,card[j].roll)==0){

            fg=1;
            char another3='Y';

            issue_sectionb:                                                        //lebel for book issue section
            
            while(another3=='Y'){

                bool flag=0;                                                       //varible flag track if you entered right book name or not
                printf("\nEnter the book Name = ");                                //enter book name ignoring the case but space and spell must be accurate
                fflush(stdin);
                scanf("%[^\n]",nm);

                for(int k=0;k<n;k++){                                           //iterate over the structure array book[n]     

                    if((strcmpi(nm,book[k].bname))==0 && (book[k].stock>0) && (book[k].flag==1)){  // if the book issue condition is matched it issued the book and stock-=1
                        flag=1;
                        printf("\n-->%s book issued for %s",book[k].bname,card[j].name);
                        time_t tm;   
                        time(&tm);
                        printf("\n\n\t\t\t\tYou issued a book at : %s\n", ctime(&tm));
                        printf("\n\t\t\t\t\tKindly Return it in 20 days\n");
                        getchar();
                        book[k].stock-=1;
                        break;
                    }

                    else if((strcmpi(nm,book[k].bname))==0 && ((book[k].stock==0) || (book[k].flag==0))){    //if the book is not in stock or it is not available for isssueing
                        printf("\nBook is not available for issue");
                        flag=1;
                        break;

                    }
                }

                if(flag==0){
                    printf("\nWrong book name entered");
                    goto issue_sectionb;                                                                    //in case of wrong book name it will take back to issue section
                    break;                        
                }

                printf("\nissued one more book ? Enter capital Y for Yes any other for No = ");
                fflush(stdin);
                another3=getchar();
            }
        }
       
    }
    if(fg==0){                                                                                              //if you didnt registered in library(or wrong roll no) it will take to the registration section

        printf("You are Not Registered in Library\t->\tkindly Registered");
        fflush(stdin);
        getchar();
        printf("\nTaking to Registration Section");
        fflush(stdin);
        getchar();
        registration();
        
    }

    fptr_b=fopen("books.txt","w");                                                                         //open the books.txt file in write mode (bcoz book stock change for issuing )
    if(fptr_b==NULL){
        printf("\nFailed to Open File (books)");
        exit(2);
    }
    for(int j=0;j<n;j++){
        fwrite(&book[j],sizeof(book),1,fptr_b);                                                           //write the updated structure array book[n] in the database
    }
    fclose(fptr_b);

}


void sort_ISBN(){                                                            //this function sort the isbn number in the structure
    
    int n;                                                                   //n will store the value of book information available
    fptrbc=fopen("bookcount.txt","r");                                       //open bookcount.txt in read mode
    if(fptrbc==NULL){
        printf("\nFailed to Open File (bookcount)");
        exit(1);
    }
    fscanf(fptrbc,"%d",&n);                                                  //import thr value of no of book information from bookcount.txt to varible n
    fclose(fptrbc);

    fptr_b=fopen("books.txt","r");                                           //open the file books.txt in read mode
    if(fptr_b==NULL){
        printf("\nFailed to Open File (books)");
        exit(2);
    }
    for(int j=0;j<n;j++){
        fread(&book[j],sizeof(book),1,fptr_b);                               //import all the book information from database to the structure array book[n]
    }
    fclose(fptr_b);

    if(n==0)printf("\nNo book Available in Library ^_^\n");

    library temp = {};                                                       //sorting the structure array book[n] on basic of ISBN through selection sort
     for(int j=0;j<n-1;j++){
        for(int k=1+j;k<n;k++){
            if(book[j].isbn>book[k].isbn){
                temp=book[j];
                book[j]=book[k];
                book[k]=temp;
            }
        }
    }
    fptr_b=fopen("books.txt","w");                                          //open the file books.txt in write mode         
    if(fptr_b==NULL){
        printf("\nFailed to Open File (books)");
        exit(2);
    }
    for(int j=0;j<n;j++){
        //fscanf(fptr_i,"%[^,],%[^,]\n",card[j].name,card[j].roll);
        fwrite(&book[j],sizeof(book),1,fptr_b);                            //export the sorted structure array book[n] information in the database
    }
    fclose(fptr_b);
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){

    int n;                                                                          //varible for switch case choice
    char ch;                                                                        //Varible for start the program
    char c;                                                                         //Varible for registration Yes or No
    
    printf("\n\n\n");
    printf("#######################################################################################################");
    printf("\n###*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#___WelCome to Knox Library___#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*###\n");
    printf("#######################################################################################################");
    printf("\n\n\n");
    printf("\t\t\t\t\tPress Any Key To Continue  ");
    ch=getchar();
    printf("\n");
    
    registration_section :                                                          //lebel for the registration section

    printf("\nAre You Registered in the Library ? Enter Y or N --> ");              //check if the member is new to library or not
    fflush(stdin);
    c=getchar();

    if(c=='N' || c=='n'){                                                           //registration part for new member
        char another1 = 'Y';
        while(another1 == 'Y'){                                                     //the loops continues to take new registration details when we press Y
            registration();
            printf("\nRegister one more student ? Enter capital Y for Yes any other for No = ");
            fflush(stdin);
            another1=getchar();
        }
        goto library_section;                                                       //another confirms if the user want to add another registration

    }
    if(c=='Y' || c=='y'){                                                           //already registered member directly go to library handler
        goto library_section;  
    }

    library_section :                                                               //lebel for library section

        printf("\n\n########################################################################################################");
        printf("\n##*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#___WelCome to Library Handler___#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*##\n");
        printf("########################################################################################################");
        //printf("Press Any Key To Continue  ");
        fflush(stdin);
        ch=getchar();

        while(1){                                                                  //Infinite while loop for library handler operations
        printf("\n\t\t\t\t#*#*#*#*#*#*Enter interger Key Accordingly#*#*#*#*#*#*#\n\n1 -> Add Book Information\n2 -> Display All Book Information\n3 -> List books of a given author\n4 -> The Title of a Book for Given ISBN\n5 -> List Total Count of books in library\n6 -> Issue Available Books\n7 -> sort ISBN in the database \n8 -> Display Library Student Registrations ------> "); 
        scanf("%d",&n);
        switch(n){                                                                 //switch case for library menu
            
            case 1:
                add_books();                                                       //add book to the library sccount
                break;

            case 2:
                display_all_books();                                               //display all books information available in library
                break;

            case 3:
                listbook_by_author();                                             //list all books by a given author
                break;

            case 4:
                bookname_from_isbn();                                             // search a book by its isbn number
                break;

            case 5:
                bookcount();                                                      //total book availabe in library
                break;

            case 6:                                                               //book issue  have two part -> 1.issue by isbn  2.issue by book name
                char chr='a';
                while(chr!='E'){
                    printf("\nEnter I for issue book by ISBN or Enter B for issue book by book name : ");
                    fflush(stdin);
                    chr=getchar();
                        if(chr=='I' || chr=='i'){                                 //by ISBN issue part
                            issue_by_isbn();
                            break;
                        }
                        else if(chr=='b' || chr=='B'){                            //by book name issue pary
                            issue_by_book();
                            break;
                        }
                        else
                            printf("\nEnter Correct Key and or enter E for cancel");
                }
                break;

            case 8:
                display_ids();                                                    //Password for displaying registered members = knox1220
                break;
            
            case 7:
                sort_ISBN();                                                     //sort the structure array of books by ISBN
                break;

            default :
                time_t t;                                                       //non primitive datatype
                time(&t);                                                       //time() function returns the time zone
                printf("\n\t\t\t\tYou are logging out at : %s\n", ctime(&t));   //ctime() returns the current time in formatted string
                getchar();
                printf("\n\t\t\t\t\t\t    Thank You\n");
                printf("\n\n\t\t\t\t\tcopyright $rahulchy960@gmail.com\n\n\n\n");
                getchar();
                exit(0);
                
        }
    }
    
    
}
