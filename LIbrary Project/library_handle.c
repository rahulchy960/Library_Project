#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>

#define MAX_BOOK 1000                    //Max book that can be added to library (Changeable)
#define MAX_MEM  100                     //Max members that can register in library (Changeable)


void registration();                     //This function is for taking members Registration in Library
void add_books();                        //Function for Adding book details in the library
void display_ids();                      //Function for display Registered student details
void display_all_books();                //function for display all book information in the library
void listbook_by_author();               //List all book available in library with a given author
void bookname_from_isbn();               //List the perticular book for a given ISBN
void bookcount();                        //display how many of a perticular book available right now
void issue_by_isbn();                    //Book issue by a given ISBN (Registration in Library Required).It will ask for enter roll no.
void issue_by_book();                    //Book issue by a given Book Name (Registration in Library Required).It will ask for enter roll no.
void sort_ISBN();                        //Sort all books available in library by ISBN number

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct{                          //Structure for Library Registration Information
    char name[30];
    char roll[15];
} idcard;


int id=0;                                              //Track the registration when a new student Register (no of ids = no of registrations)
idcard card[MAX_MEM];                                  //declaration of the structure array that holds student information
int ii=0;                                              // iterator , which to place the information in write place in the structure array


void registration(){
    printf("\nInformation required -> 1.NAME 2.RollNo");   
    id++;                                                                //Id increses with each registration
    for(ii;ii<id;ii++){                                                  //input the student details (Name and roll no)
        printf("\n\nEnter your name --> ");
        fflush(stdin);
        scanf("%[^\n]",card[ii].name);
        printf("\nEnter your roll no. --> ");
        fflush(stdin);
        scanf("%s",card[ii].roll);
    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)                                          //Packing the structure for avoid padding
typedef struct{                                          //structure for books information
    long isbn;
    char bname[50];                                      //bookname
    char aname[50];                                      //author name
    float price;
    int pages;
    int stock; 
    bool flag;                                           //flag indicates the book is available for issue or not
} library;
#pragma pack()


int count = 0;                                           //Track the registration when a new student Register (no of ids = no of registrations)
int i=0;                                                 // iterator , which to place the information in write place in the structure array
library book[MAX_BOOK];                                  //declaration of the structure array that holds book information


void add_books(){ 

    printf("\n");
    printf("\nEnter The book Details\n");
    char another2 = 'Y';                                 //another varible stores the while loop condition

    while(another2=='Y'){                                //The while loop continue to take book information when the input choise is Y
        count++;                                         //the count varible increses by one every time when a new book information entered
        for(i;i<count;i++){
            printf("\nEnter the ISBN no of the Book = ");
            fflush(stdin);
            scanf("%ld",&book[i].isbn);
            printf("\nEnter the Book name = ");
            fflush(stdin);
            scanf("%[^\n]",book[i].bname);
            printf("\nEnter the Author name  = ");
            fflush(stdin);
            scanf("%[^\n]",book[i].aname);
            printf("\nEnter price of the book = ");
            fflush(stdin);
            scanf("%f",&book[i].price);
            printf("\nEnter pages of the book = ");
            fflush(stdin);
            scanf("%d",&book[i].pages);
            printf("\nEnter Number of the books in stock = ");
            fflush(stdin);
            scanf("%d",&book[i].stock);
            printf("\nMark the book is available for issue or not by flag(0/1) = ");
            fflush(stdin);
            scanf("%d",&book[i].flag);
        
        }
        printf("\nAnother Book details ? Enter capital Y for Yes any other for No = ");
        fflush(stdin);                                  
        another2=getchar();                                                                 //If the choice is Y it will take another book information                

    }
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void display_ids(){                                                                        //function for displaying registered member's details
    

    printf("\nEnter Security Password for displaying registered member's details = ");
    char s[20];                                                                           //varible s stores the password entered
    scanf("%s",s);
    if(id==0)printf("0 member Registered");
    else if(strcmp(s,"knox1220")==0){                                                     //if the password matches it display the registered members information
        printf("\nRegistered id in the database :-> ");   
        for(int k=0;k<id;k++){                                                            //iterate through all the structure array card[id]
            printf("\nMember [%d] -> NAME = %s  RollNo. = %s",(k+1),card[k].name,card[k].roll);
        }
        printf("\n\n");
    }
    else{
        printf("\nWrong Password entered");
    }
    
}

void display_all_books(){                                                                   //function for displaying library stock
    
    if(count==0)printf("\nNo book Available in Library ^_^\n");                            //as declared erlier count stores the numbers of book information
    else{
        printf("\n\n#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#___Displaying All Books___#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#\n\n");
        for(int j=0;j<count;j++){                                                          //iterrate through all the structure araay book[count]
            printf("BOOK[%d] -> ISBN = %ld  Book Name = %-12s  Author name = %-12s  Price = %.2f  Pages = %d  In_Stock = %d\n",(j+1),book[j].isbn,book[j].bname,book[j].aname,book[j].price,book[j].pages,book[j].stock);
        }
    }
    
}

void listbook_by_author(){                                                                 //function for list all books by a given author

    char str[50];                                                                          // str is the varible to store the input author name
    printf("\nEnter the Author name = ");
    fflush(stdin);
    scanf("%[^\n]",str);
    printf("\nBooks written by %s are = ",str);                                           //iterate over the structure array book[count]
    for(int j=0;j<count;j++){                                                              
        if(strcmpi(str,book[j].aname)==0){
            printf("%s\t",book[j].bname);                                                 //if matches, it will display the book names of that author
        }
    }
    printf("- N/A\n");
}

void bookname_from_isbn(){                                                                //function for find bookname with isbn

    long isb;                                                                             //isb varible will store the isbn entered
    printf("\nEnter the ISBN (If ISBN Wrong it will take to the Library Handler)= ");
    scanf("%ld",&isb);
    for(int j=0;j<count;j++){                                                            //iterate over the structure array book[count]   
        if(isb==book[j].isbn){
            printf("\nAuthor = %s  Book Name = %s\n",book[j].aname,book[j].bname);       //if matches, it will display the book name and the author
        }
    }
}

void bookcount(){                                                                         //function for display how many books available in library

    int sum = 0;                                                                          //varible sum will store the total books available
    for(int j=0;j<count;j++){                                                             //iterate over the structure array book[count]
        if(book[j].stock > 0){
            sum+=book[j].stock;
        }
        printf("\nBook[%d] -> %-14s in Stock -> %d",(j+1),book[j].bname,book[j].stock);
    }
    printf("\nTotal Book available right now = %d\n",sum);

}

void issue_by_isbn(){                                                                     //function for issue book by isbn and roll no registered

    long isbnc;                                                                           //isbnc varible will stores the isbn entered
    char rolln[15];                                                                       //rolln varible will stores the roll no entered
    printf("\nEnter Roll No. = ");
    fflush(stdin);
    scanf("%s",rolln);
    
    bool fg=0;                                                                           //fg varible track if you are registerd in library or not
    if(count==0){
        printf("\nNo book Available in Library ^_^\n");
        fg=1;
    }
     
    for(int j=0;j<id;j++){                                                               //iterate over the structure array card[id]

        if(strcmp(rolln,card[j].roll)==0){                                               // check for roll no is registered or not
            fg=1;                        
            char another3='Y';

            issue_section:                                                               //lebel for book issue section

           
            while(another3=='Y'){                                                       //while loop issuing book upto you entered Y everytime 
               
                printf("\nEnter the ISBN Number = ");
                scanf("%ld",&isbnc); 
                bool flag=0;                                                            //varible flag track if you entered right isbn or not

                for(int k=0;k<count;k++){                                               
                    
                    if((isbnc==book[k].isbn) && (book[k].stock>0) && (book[k].flag==1)){    // if the book issue condition matched it issued the book and stock-=1
                        flag=1;
                        printf("\n--> %s book is issued for %s",book[k].bname,card[j].name);
                        time_t tm;   
                        time(&tm);
                        printf("\n\n\t\t\t\tYou issued a book at : %s", ctime(&tm));
                        printf("\n\t\t\t\t\tKindly Return it in 20 days");
                        getchar();
                        book[k].stock-=1;
                        break;
                    }

                    else if((isbnc==book[k].isbn) && ((book[k].stock==0) || (book[k].flag==0))){  //if the book is not in stock or it is not available for isssueing                        printf("Book is not available for issue");
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    printf("Wrong isbn number entered");
                    goto issue_section;                                                           //in case of wrong isbn it will take back to issue section 
                    break;                        
                }
                printf("\nissued one more book ? Enter capital Y for Yes any other for No = ");
                fflush(stdin);
                another3=getchar();
            }
        }
     
    }
    if(fg==0){                                                                                   //if you didnt registered in library (wrong roll no) it will take to the registration section
        printf("You are Not Registered in Library\t->\tkindly Registered");
        fflush(stdin);
        getchar();
        printf("\nTaking to Registration Section");
        fflush(stdin);
        getchar();
        registration();
    }

}


void issue_by_book(){                                                                            //function for issuing book by book name and roll no registered 
    
    char nm[50];                                                                                 //nm varible will store the book name
    char rolln[15];                                                                              //roll no vaible will stored the roll no entered
    printf("\nEnter Roll No. = ");
    fflush(stdin);
    scanf("%s",rolln);
    
    bool fg=0;                                                                                   //fg varible track if you are registerd in library or not
    if(count==0){
        printf("\nNo book Available in Library ^_^\n");
        fg=1;
    }
                 
    for(int j=0;j<id;j++){                                                                       //iterate over the structure array card[id]
                      
        if(strcmp(rolln,card[j].roll)==0){                                                       // check for roll no is registered or not
  
            fg=1;
            char another3='Y';

            issue_sectionb:                                                                     //lebel for book issue section

            printf("\nEnter the book Name = ");
            fflush(stdin);
            scanf("%[^\n]",nm);
            while(another3=='Y'){                                                              //while loop issuing book upto you entered Y everytime
                bool flag=0;                                                                   //varible flag track if you entered right isbn or not
                for(int k=0;k<count;k++){

                    if((strcmp(strupr(nm),strupr(book[k].bname)))==0 && (book[k].stock>0) && (book[k].flag==1)){  // if the book issue condition is matched it issued the book and stock-=1
                        flag=1;
                        printf("\n-->%s book issued for %s",book[k].bname,card[j].name);
                        time_t tm;   
                        time(&tm);
                        printf("\n\t\t\t\tYou issued a book at : %s\n", ctime(&tm));
                        printf("\n\t\t\t\t\tKindly Return it in 20 days\n");
                        getchar();
                        book[k].stock-=1;
                        break;
                    }

                    else if((strcmp(strupr(nm),strupr(book[k].bname)))==0 && ((book[k].stock==0) || (book[k].flag==0))){     //in case of wrong isbn it will take back to issue section
                        printf("Book is not available for issue");
                        flag=1;
                        break;

                    }
                }

                if(flag==0){
                    printf("Wrong isbn number entered");
                    goto issue_sectionb;                                                                          //in case of wrong isbn it will take back to issue section
                    break;                        
                }

                printf("\nissued one more book ? Enter capital Y for Yes any other for No = ");                   //if you didnt registered in library it will take to the registration section
                fflush(stdin);
                another3=getchar();
            }
        }
       
    }
    if(fg==0){                                                                                                    //if you didnt registered in library it will take to the registration section

        printf("You are Not Registered in Library\t->\tkindly Registered");
        fflush(stdin);
        getchar();
        printf("\nTaking to Registration Section");
        fflush(stdin);
        getchar();
        registration();

    }

}


void sort_ISBN(){                                                                    //this function sort the isbn number in the structure

    if(count==0)printf("\nNo book Available in Library ^_^\n");

    library temp = {};                                                               //sorting the structure array book[count] on basic of ISBN through selection sort
     for(int j=0;j<count-1;j++){
        for(int k=1+j;k<count;k++){
            if(book[j].isbn>book[k].isbn){
                temp=book[j];
                book[j]=book[k];
                book[k]=temp;
            }
        }
    }
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){

    int n;                                                               //varible for switch case choice
    char ch;                                                             //Varible for start the program
    char c;                                                              //Varible for registration Yes or No
    
    printf("\n\n\n");
    printf("#######################################################################################################");
    printf("\n###*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#___WelCome to Knox Library___#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*###\n");
    printf("#######################################################################################################");
    printf("\n\n\n");
    printf("\t\t\t\t\tPress Any Key To Continue  ");
    ch=getchar();
    printf("\n");
    
    registration_section :                                                //lebel for the registration section

    printf("\nAre You Registered in the Library ? Enter Y or N --> ");    //check if the member is new to library or not
    fflush(stdin);
    c=getchar();

    if(c=='N' || c=='n'){                                                //new member registraton start
        char another1 = 'Y';
        while(another1 == 'Y'){                                          //the loops continues to take new registration details when we press Y
            registration();
            printf("\nRegister one more student ? Enter capital Y for Yes any other for No = ");
            fflush(stdin);
            another1=getchar();                                          //another confirms if the user want to add another registration
        }
        goto library_section;                                            //after registration it will take to the library section

    }
    if(c=='Y' || c=='y'){                                                //already registered member directly go to library handler
        goto library_section;  
    }

    library_section :                                                    //lebel for library section

        printf("\n\n########################################################################################################");
        printf("\n##*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#___WelCome to Library Handler___#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*##\n");
        printf("########################################################################################################");
        //printf("Press Any Key To Continue  ");
        fflush(stdin);
        ch=getchar();

        while(1){                                                                     //Infinite while loop for library handler operations
        printf("\n\t\t\t\t#*#*#*#*#*#*Enter interger Key Accordingly#*#*#*#*#*#*#\n\n1 -> Add Book Information\n2 -> Display All Book Information\n3 -> List books of a given author\n4 -> The Title of a Book for Given ISBN\n5 -> List Total Count of books in library\n6 -> Issue Available Books\n7 -> sort ISBN in the database \n8 -> Display Library Student Registrations ------> "); 
        scanf("%d",&n);
        switch(n){                                                                    //switch case for library menu
            
            case 1:
                add_books();                                                         //add book to the library sccount
                break;

            case 2:
                display_all_books();                                                //display all books information available in library
                break;

            case 3:
                listbook_by_author();                                               //list all books by a given author
                break;

            case 4:
                bookname_from_isbn();                                              // search a book by its isbn number
                break;

            case 5:
                bookcount();                                                       //total book availabe in library
                break;

            case 6:                                                                //book issue  have two part -> 1.issue by isbn  2.issue by book name
                char chr='a';
                while(chr!='E'){
                    printf("\nEnter I for issue book by ISBN or Enter B for issue book by book name : ");
                    fflush(stdin);
                    chr=getchar();
                        if(chr=='I' || chr=='i'){                                  //by ISBN issue part
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
            
            case 7:                                                               //sort the structure array of books by ISBN
                sort_ISBN();
                break;

            default :
                time_t t;                                                         //non primitive datatype
                time(&t);                                                         //time() function returns the time zone
                printf("\n\t\t\t\tYou are logging out at : %s\n", ctime(&t));     //ctime() returns the current time in formatted string
                getchar();
                printf("\n\t\t\t\t\t\t  Thank You\n");
                printf("\n\n\t\t\t\t\t   copyright @rahulchy960\n\n\n\n");
                getchar();
                exit(0);
                
        }
    }
    
    
}
