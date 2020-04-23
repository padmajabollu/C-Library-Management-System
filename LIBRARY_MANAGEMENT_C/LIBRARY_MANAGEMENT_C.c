#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<time.h>
#include<string.h>

struct Librarian
{
    int l_id; 
    char l_name[20];
    char l_password[20];
    struct Librarian *next;
};

struct Student
{
    int s_prn;
    char s_name[20];
    char s_password[20];
    struct Student *next;
};

struct Book
{
    int b_id;
    char b_name[50];
    char b_author[20];
    char b_publication[20];
    struct Book *next;
};

struct StudentBook
{
    int b_id;
    char b_name[50];
    char b_author[20];
    char b_publication[20];
    int s_prn;
    int day;
    int month;
    int year;
    struct StudentBook *next;
};

void L_insert_data_end(struct Librarian** head_ptr,int l_id1,char l_name1[20],char l_password1[20])
{
    int i;
    struct Librarian* new_node=(struct Librarian*) malloc(sizeof(struct Librarian));
    struct Librarian *tmp=*head_ptr;
    for(i=0;i<20;i++)
    {
        new_node->l_name[i]=l_name1[i];
        new_node->l_password[i]=l_password1[i];

    }
    new_node->l_id=l_id1;
        
    new_node->next=NULL;
    if(*head_ptr==NULL)
    {
        *head_ptr=new_node;
        return;
    }
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=new_node;
    return ;
}
void S_insert_data_end(struct Student** head_ptr,int s_prn1,char s_name1[20],char s_password1[20])
{
    int i=0;
    struct Student* new_node=(struct Student*) malloc(sizeof(struct Student));
    struct Student *tmp=*head_ptr;
    for(i=0;i<20;i++)
    {
        new_node->s_name[i]=s_name1[i];
        new_node->s_password[i]=s_password1[i];
    }
    new_node->s_prn=s_prn1;
        
    new_node->next=NULL;
    if(*head_ptr==NULL)
    {
        *head_ptr=new_node;
        return;
    }
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=new_node;
    return;
}

void B_insert_data_end(struct Book** head_ptr,int b_id1,char b_name1[50],char b_author1[20],char b_publication1[20])
{
    int i=0,f=0;
    struct Book* new_node=(struct Book*) malloc(sizeof(struct Book));
    struct Book *tmp=*head_ptr;
    struct Book *tmp1=*head_ptr;
    while(tmp1!=NULL)
    {
        if(tmp1->b_id==b_id1)
        {
            f=1;
        }
        tmp1=tmp1->next;
    }
    if(f==0)
    {
        for(i=0;i<20;i++)
        {
            new_node->b_author[i]=b_author1[i];
            new_node->b_publication[i]=b_publication1[i];

        }
        for(i=0;i<50;i++)
        {
            new_node->b_name[i]=b_name1[i];
            
        }
        new_node->b_id=b_id1;
            
        new_node->next=NULL;
        if(*head_ptr==NULL)
        {
            *head_ptr=new_node;
            return;
        }
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=new_node;
        
        printf("\nBook Added Successfully !! \n");
                                            
        return ;
    }
    else
    {
        printf("\nBook Id Already Exists !!\n");
    }
    
}
void SB_insert_data_end(struct StudentBook** head_ptr,int b_id1,char b_name1[50],char b_author1[20],char b_publication1[20],int s_prn1,int day1,int month1,int year1)
{
    int i=0;
    struct StudentBook* new_node=(struct StudentBook*) malloc(sizeof(struct StudentBook));
    struct StudentBook *tmp=*head_ptr;
    for(i=0;i<20;i++)
    {
        new_node->b_author[i]=b_author1[i];
        
        new_node->b_publication[i]=b_publication1[i];
        
    }
    for(i=0;i<50;i++)
    {
        new_node->b_name[i]=b_name1[i];
        
    }
    new_node->s_prn=s_prn1;
    new_node->day=day1;
    new_node->month=month1;
    new_node->year=year1;
    new_node->b_id=b_id1;
        
    new_node->next=NULL;
    if(*head_ptr==NULL)
    {
        *head_ptr=new_node;
        return;
    }
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=new_node;
    return ;
}

void L_printList(struct Librarian *tmp)
{
    int i;
    printf("\nLibrarian Data : \n\n");
    while(tmp!=NULL)
    {
            printf("%d\t",tmp->l_id);
            printf("%s\t",tmp->l_name);
            printf("%s\t",tmp->l_password);
        
        tmp=tmp->next;
        printf("\n");
    }
}

void S_printList(struct Student *tmp)
{

    printf("\nStudent Data : \n\n");
    while(tmp!=NULL)
    {
        printf("%d\t",tmp->s_prn);
        printf("%s\t",tmp->s_name);
        printf("%s\t",tmp->s_password);
        
        tmp=tmp->next;
        printf("\n");
    }
}
void B_printList(struct Book *tmp)
{
    int i;
    while(tmp!=NULL)
    {
        printf("%d\t%s\t%s\t%s",tmp->b_id,tmp->b_name,tmp->b_author,tmp->b_publication);
        tmp=tmp->next;
        printf("\n");
    }
}
void SB_printList(struct StudentBook *tmp)
{
    int i;
   while(tmp!=NULL)
    {
        printf("%d\t%s\t%s\t%s",tmp->b_id,tmp->b_name,tmp->b_author,tmp->b_publication);
        tmp=tmp->next;
        printf("\n");
    }
}

void SB_printList_all(struct StudentBook *tmp)
{
    int i;
    printf("\nIssued Book Data : \n\n");
    while(tmp!=NULL)
    {
        printf("%d\t%s\t%s\t%s\t%d\t%d-%d-%d",tmp->b_id,tmp->b_name,tmp->b_author,tmp->b_publication,tmp->s_prn,tmp->day,tmp->month,tmp->year);
        tmp=tmp->next;
        printf("\n");
    }
}

void Student_delete(struct Student** head_ptr,int s_prn1)
{
    struct Student *prev=*head_ptr;
    struct Student *tmp=*head_ptr;
    
    if(prev->s_prn==s_prn1)
    {
        *head_ptr=NULL;
        *head_ptr=prev->next;
        prev=NULL;
        printf("\nStudent Account Deleted Successfully !!!\n");
   
        return;
    }

    int f=0;
    while(tmp!=NULL)
    {
        if(tmp->s_prn==s_prn1)
        {
            printf("\nStudent Account Deleted Successfully !!!\n");
            f==1;
            break;
        }
        prev=tmp;
        tmp=tmp->next;
    }
    
    if(f==0)
    {
        printf("\nStudent Account Not Exist !!!\n");
    }
    else
    {
        prev->next=tmp->next;
        tmp=NULL;
    
    }
   
}
void Book_delete_only(struct Book** head_ptr,int b_id1)
{
    struct Book *prev=*head_ptr;
    struct Book *tmp=*head_ptr;
    
    if(prev->b_id==b_id1)
    {
        *head_ptr=NULL;
        *head_ptr=prev->next;
        prev=NULL;
        printf("\nBook Deleted Successfully !!!\n");

        return;
    }
    int f=0;

    while(tmp!=NULL)
    {
        if(tmp->b_id==b_id1)
        {
            printf("\nBook Deleted Successfully !!!\n");
            f=1;
            break;
        }
        prev=tmp;
        tmp=tmp->next;
    }
    if(f==0)
    {
        printf("\nBook Not Exist !!!\n");

    }
    else
    {
        prev->next=tmp->next;
        tmp=NULL;
    
    }
    
}
void Book_delete(struct Book** head_ptr,int b_id1)
{
    struct Book *prev=*head_ptr;
    struct Book *tmp=*head_ptr;
    
    if(prev->b_id==b_id1)
    {
        *head_ptr=NULL;
        *head_ptr=prev->next;
        prev=NULL;
        printf("\nBook Issue Successfully !!!\n");
        return;
    }

    int f=0;

    while(tmp!=NULL)
    {
        if(tmp->b_id==b_id1)
        {
            printf("\nBook Issue Successfully !!!\n");
            f=1;
            break;
        }
        prev=tmp;
        tmp=tmp->next;
    }
    
    if(f==0)
    {
        printf("\nBook Not Exist !!!\n");
    }
    else
    {
        prev->next=tmp->next;
        tmp=NULL;
    
    }
}

void StudentBook_delete(struct StudentBook** head_ptr,int s_prn1,int b_id1)
{
    struct StudentBook *prev=*head_ptr;
    struct StudentBook *tmp=*head_ptr;
    
    if(tmp->b_id==b_id1 && tmp->s_prn==s_prn1)
    {
        *head_ptr=NULL;
        *head_ptr=prev->next;
        prev=NULL;
        printf("\nBook Returned Successfully !!!\n");
        return;
    }

    int f=0;
    while(tmp!=NULL)
    {
        if(tmp->b_id==b_id1 && tmp->s_prn==s_prn1)
        {
            printf("\nBook Returned Successfully !!!\n");
            f=1;
            break;
        }
        prev=tmp;
        tmp=tmp->next;
    }
    if(f==0)
    {
        printf("\nBook Not Exist !!!\n");
    }
    else
    {
        prev->next=tmp->next;
        tmp=NULL;
    
    }
}


void main()
{
    int errnum=10;
    int l_id1,s_prn1,b_id1;
    char l_name1[20],l_password1[20];
    char s_name1[20],s_email1[20],s_password1[20];
    char b_name1[50],b_author1[20],b_publication1[20];
    int day1,month1,year1;

    struct Librarian* lhead=NULL;
    struct Student* shead=NULL;
    struct Book* bhead=NULL;
    struct StudentBook* sbhead=NULL;

    struct Librarian *ltmp=NULL;
    struct Student *stmp=NULL;
    struct Book *btmp=NULL;
    struct StudentBook *sbtmp=NULL;

    int l1,l2,l3,l4,index=0;
    //char final[100];

    time_t t=time(NULL);
    struct tm tm=*localtime(&t);
//    printf("now: %d\t%d\t%d",tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday);
    day1=tm.tm_mday;
    month1=tm.tm_mon+1;
    year1=tm.tm_year+1900;

    int output=0;
    char Id[10];
    int length=0;
    int i=0;
    char c;
    int special=0;
    int lower=0;
    int upper=0;
    int digit=0;

    FILE * lfptr, * sfptr, * bfptr, * sbfptr;
    ssize_t output1;
    char * line=NULL;
    size_t len=0;

    lfptr = fopen ("Librarian.txt", "r");  
    while ((output1=getline(&line,&len,lfptr)) != EOF)
    {
        char id[20]="",Name[20]="",Password[20]="";
        int id1=0;
        int j=0;
        char out1[strlen(line)-1];
        for(i=0;i<strlen(line)-1;i++)
        {
            out1[i]=line[i];
        }
        for(i=0;i<strlen(out1) && j<strlen(out1);i++)
        {
            if(out1[j]==';')
            {
                j++;
                break;
            }
            else{
                id[i]=out1[j];
                j++;
            }
        }
        sscanf(id,"%d",&id1);
        for(i=0;i<strlen(out1);i++)
        {
            if(out1[j]==';')
            {
                j++;
                break;
            }
            else
            {
                Name[i]=out1[j];
                j++;
            
            }

        }   
        for(i=0;i<strlen(out1);i++)
        {
            if(out1[j]==';')
            {
                j++;
                break;
            }
            else
            {
                Password[i]=out1[j];
                j++;
            
            }

        }   

        L_insert_data_end(&lhead,id1,Name,Password);
    }

    fclose (lfptr);
    L_printList(lhead);
    
    sfptr = fopen ("Student.txt", "r");  
    while ((output1=getline(&line,&len,sfptr)) != EOF)
    {
        char id[20]="",Name[20]="",Password[20]="";
        int id1=0;
        int j=0;
        char out1[strlen(line)-1];
        for(i=0;i<strlen(line)-1;i++)
        {
            out1[i]=line[i];
        }
        for(i=0;i<strlen(out1) && j<strlen(out1);i++)
        {
            if(out1[j]==';')
            {
                j++;
                break;
            }
            else{
                id[i]=out1[j];
                j++;
            }
        }
        sscanf(id,"%d",&id1);
        for(i=0;i<strlen(out1);i++)
        {
            if(out1[j]==';')
            {
                j++;
                break;
            }
            else
            {
                Name[i]=out1[j];
                j++;
            
            }

        }   
        for(i=0;i<strlen(out1);i++)
        {
            if(out1[j]==';')
            {
                j++;
                break;
            }
            else
            {
                Password[i]=out1[j];
                j++;
            
            }

        }   

        S_insert_data_end(&shead,id1,Name,Password);
    }

    fclose (sfptr);
    S_printList(shead);
    
    bfptr = fopen ("Book.txt", "r");  
    while ((output1=getline(&line,&len,bfptr)) != EOF)
    {
        char id[20]="",Name[50]="",Author[20]="",Publication[20]="";
        int id1=0;
        int j=0;
        char out1[strlen(line)-1];
        for(i=0;i<strlen(line)-1;i++)
        {
            out1[i]=line[i];
        }
        for(i=0;i<strlen(out1) && j<strlen(out1);i++)
        {
            if(out1[j]==';')
            {
                j++;
                break;
            }
            else{
                id[i]=out1[j];
                j++;
            }
        }
        sscanf(id,"%d",&id1);
        for(i=0;i<strlen(out1);i++)
        {
            if(out1[j]==';')
            {
                j++;
                break;
            }
            else
            {
                Name[i]=out1[j];
                j++;
            
            }

        }   
        for(i=0;i<strlen(out1);i++)
        {
            if(out1[j]==';')
            {
                j++;
                break;
            }
            else
            {
                Author[i]=out1[j];
                j++;
            
            }
		}

        for(i=0;i<strlen(out1);i++)
        {
            if(out1[j]==';')
            {
                j++;
                break;
            }
            else
            {
                Publication[i]=out1[j];
                j++;
            
            }

        }   

        B_insert_data_end(&bhead,id1,Name,Author,Publication);
    }

    fclose (bfptr);
    printf("\nAvailable Book Details :\n\n");
    B_printList(bhead);
    
    sbfptr = fopen ("StudentBook.txt", "r");  
    while ((output1=getline(&line,&len,sbfptr)) != EOF)
    {
        char id[20]="",Name[50]="",Author[20]="",Publication[20]="",prn[10],d[10],m[10],y[10];
        int id1=0;
        int j=0;
        char out1[strlen(line)-1];
        for(i=0;i<strlen(line)-1;i++)
        {
            out1[i]=line[i];
        }
        //printf("\n%s",out1);
        for(i=0;i<strlen(out1) && j<strlen(out1);i++)
        {
            if(out1[j]==';')
            {
                j++;
                break;
            }
            else{
                id[i]=out1[j];
                j++;
            }
        }
        sscanf(id,"%d",&id1);
        //printf("%d\t",id1);        
        
        for(i=0;i<strlen(out1);i++)
        {
            if(out1[j]==';')
            {
                j++;
                break;
            }
            else
            {
                Name[i]=out1[j];
                j++;
            
            }

        }   
        //printf("%s\t",Name);        
        
        for(i=0;i<strlen(out1);i++)
        {
            if(out1[j]==';')
            {
                j++;
                break;
            }
            else
            {
                Author[i]=out1[j];
                j++;
            
            }
		}
        //printf("%s\t",Author);        
        for(i=0;i<strlen(out1);i++)
        {
            if(out1[j]==';')
            {
                j++;
                break;
            }
            else
            {
                Publication[i]=out1[j];
                j++;
            
            }

        }  
        //printf("%s\t",Publication);        
        
        for(i=0;i<strlen(out1);i++)
        {
            if(out1[j]==';')
            {
                j++;
                break;
            }
            else
            {
                prn[i]=out1[j];
                j++;
            
            }

        } 
        sscanf(prn,"%d",&s_prn1);
        //printf("%d\t",s_prn1);
        for(i=0;i<strlen(out1);i++)
        {
            if(out1[j]==';')
            {
                j++;
                break;
            }
            else
            {
                d[i]=out1[j];
                j++;
            
            }

        } 
        sscanf(d,"%d",&day1);
        //printf("%d\t",day1);
        for(i=0;i<strlen(out1);i++)
        {
            if(out1[j]==';')
            {
                j++;
                break;
            }
            else
            {
                m[i]=out1[j];
                j++;
            
            }

        } 
        sscanf(m,"%d",&month1);
        //printf("%d\t",month1);
        for(i=0;i<strlen(out1);i++)
        {
            if(out1[j]==';')
            {
                j++;
                break;
            }
            else
            {
                y[i]=out1[j];
                j++;
            
            }

        } 
        sscanf(y,"%d",&year1);
        //printf("%d\t",year1);
        
        SB_insert_data_end(&sbhead,id1,Name,Author,Publication,s_prn1,day1,month1,year1);
    }

    fclose (sbfptr);
    SB_printList_all(sbhead);


    while(1)
    {
        printf("\nLibrary Management System");
        printf("\n\nSelect your Option\n");
        printf("1.Registration\n");
        printf("2.Login\n");
        printf("3.Exit\n");
        int choice;
        scanf("%d",&choice);
        if(choice==1)
        {
            while(1)
            {
                printf("\n\nSelect your Option\n");
                printf("1.Librarian Registration\n");
                printf("2.Student Registration\n");
                printf("3.Exit\n");
                int c1;
                scanf("%d",&c1);
                if(c1==1)
                {
                    
                    printf("\nLibrarian Details :\n");
                    printf("\nEnter Id : ");
                    output=scanf("%d",&l_id1);
                    while(1)
                    {
                        digit=0;
                        i=0;
                        itoa(l_id1,Id,10);
                        length=strlen(Id);
                        while(i<length)
                        {
                            c=Id[i];
                            i++;
                            if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9')
                            {
                                digit=digit+1;
                            }
                        }
                        if(strlen(Id)>=4 && output==1 && digit==length)
                        {
                            break;
                        }
                        else
                        {
                            printf("\nEnter Valid Id : ");
                            output=scanf("%d",&l_id1);
                            continue;
                        }
                    }
                    printf("\nEnter Name : ");
                    output= scanf("%s",&l_name1);
                    while(1)
                    {
                        lower=0;
                        upper=0;
                        length=strlen(l_name1);
                        i=0;
                        while(i<length)
                        {
                            c=l_name1[i];
                            i++;
                            if(c=='a' || c=='b' || c=='c' || c=='d' || c=='e' || c=='f' || c=='g' || c=='h' || c=='i' || c=='j' || c=='k' || c=='l' || c=='m' || c=='n' || c=='o' || c=='p' || c=='q' || c=='r' || c=='s' || c=='t' || c=='u' || c=='v' || c=='w' || c=='x' || c=='y' || c=='z')
                            {
                                lower=lower+1;
                            }
                            if(c=='A' || c=='B' || c=='C' || c=='D' || c=='E' || c=='F' || c=='G' || c=='H' || c=='I' || c=='J' || c=='K' || c=='L' || c=='M' || c=='N' || c=='O' || c=='P' || c=='Q' || c=='R' || c=='S' || c=='T' || c=='U' || c=='V' || c=='W' || c=='X' || c=='Y' || c=='Z')
                            {
                                upper=upper+1;
                            }

                        }
                        if(strlen(l_name1)>=4 && output==1  && (lower+upper)==length)
                        {
                            break;
                        }
                        else
                        {
                            printf("\nEnter Valid Name : ");
                            output=scanf("%s",&l_name1);
                            continue;
                        }
                    }
                    printf("\nEnter Password like Padmaja@04 : ");
                    output= scanf("%s",&l_password1);
                    while(1)
                    {
                        length=strlen(l_password1);
                        i=0;
                        special=0;
                        lower=0;
                        upper=0;
                        digit=0;
                        
                        while(i<length)
                        {
                            c=l_password1[i];
                            i++;
                            if(c=='@' || c=='!' || c=='#' || c=='$' )
                            {
                                special=1;
                            }
                            if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9')
                            {
                                digit=1;
                            }
                            if(c=='a' || c=='b' || c=='c' || c=='d' || c=='e' || c=='f' || c=='g' || c=='h' || c=='i' || c=='j' || c=='k' || c=='l' || c=='m' || c=='n' || c=='o' || c=='p' || c=='q' || c=='r' || c=='s' || c=='t' || c=='u' || c=='v' || c=='w' || c=='x' || c=='y' || c=='z')
                            {
                                lower=1;
                            }
                            if(c=='A' || c=='B' || c=='C' || c=='D' || c=='E' || c=='F' || c=='G' || c=='H' || c=='I' || c=='J' || c=='K' || c=='L' || c=='M' || c=='N' || c=='O' || c=='P' || c=='Q' || c=='R' || c=='S' || c=='T' || c=='U' || c=='V' || c=='W' || c=='X' || c=='Y' || c=='Z')
                            {
                                upper=1;
                            }
                            
                        }
                        if(length>=6 && upper==1 && lower==1 && digit==1 && special==1 && output==1)
                        {
                            break;
                        }
                        else
                        {
                            printf("\nEnter Valid Password : ");
                            output=scanf("%s",&l_password1);
                            continue;
                        }
                        
                    }
                    
                    L_insert_data_end(&lhead,l_id1,l_name1,l_password1);
                    printf("\nRegistration Successful !!\n");
                    L_printList(lhead);
                    
                    ltmp=lhead;
                    FILE *lwfptr;
                        
                    lwfptr=fopen("Librarian.txt","w");
                    while(ltmp!=NULL)
                    {
                        index=0;
                        char final[100];
                        itoa(ltmp->l_id,Id,10);
                        for(l1=0;Id[l1]!='\0';l1++);
                        for(l2=0;ltmp->l_name[l2]!='\0';l2++);
                        for(l3=0;ltmp->l_password[l3]!='\0';l3++);
                        //printf("\n%d\t%d\t%d",l1,l2,l3);
                        for(i=0;i<l1;i++)
                        {
                            final[index]=Id[i];
                            index++;

                        }
                        final[index]=';';
                        index++;
                        for(i=0;i<l2;i++)
                        {
                            final[index]=ltmp->l_name[i];
                            index++;
                        }
                        final[index]=';';
                        index++;
                        for(i=0;i<l3;i++)
                        {
                            final[index]=ltmp->l_password[i];
                            index++;
                        }
                        final[index]=';';
                        index++;

                        for(l4=0;final[l4]!='\0';l4++);
                        fputs(final,lwfptr);
                        fputs("\n",lwfptr);


                        ltmp=ltmp->next;
                        
                    }
                    fclose(lwfptr);
                        
                }
                else
                {
                    if(c1==2)
                    {
                        printf("\nStudent Details : \n");
                        printf("\nEnter PRN : ");
                        output= scanf("%d",&s_prn1);
                        while(1)
                        {
                            digit=0;
                            i=0;
                            itoa(s_prn1,Id,10);
                            length=strlen(Id);
                            while(i<length)
                            {
                                c=Id[i];
                                i++;
                                if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9')
                                {
                                    digit=digit+1;
                                }
                            }
                            if((strlen(Id)==10 ||strlen(Id)==9) && output==1 && digit==length)
                            {
                                break;
                            }
                            else
                            {
                                printf("\nEnter Valid PRN : ");
                                output=scanf("%d",&s_prn1);
                                continue;
                            }
                        }
                        printf("\nEnter Name :");
                        output= scanf("%s",&s_name1);
                        while(1)
                        {
                            lower=0;
                            upper=0;
                            length=strlen(s_name1);
                            i=0;
                            while(i<length)
                            {
                                c=s_name1[i];
                                i++;
                                if(c=='a' || c=='b' || c=='c' || c=='d' || c=='e' || c=='f' || c=='g' || c=='h' || c=='i' || c=='j' || c=='k' || c=='l' || c=='m' || c=='n' || c=='o' || c=='p' || c=='q' || c=='r' || c=='s' || c=='t' || c=='u' || c=='v' || c=='w' || c=='x' || c=='y' || c=='z')
                                {
                                    lower=lower+1;
                                }
                                if(c=='A' || c=='B' || c=='C' || c=='D' || c=='E' || c=='F' || c=='G' || c=='H' || c=='I' || c=='J' || c=='K' || c=='L' || c=='M' || c=='N' || c=='O' || c=='P' || c=='Q' || c=='R' || c=='S' || c=='T' || c=='U' || c=='V' || c=='W' || c=='X' || c=='Y' || c=='Z')
                                {
                                    upper=upper+1;
                                }

                            }
                            if(strlen(s_name1)>=4 && output==1 && (lower+upper)==length)
                            {
                                break;
                            }
                            else
                            {
                                printf("\nEnter Valid Name : ");
                                output=scanf("%s",&s_name1);
                                continue;
                            }
                        }
                        printf("\nEnter Password like Paddu@066 :");
                        output= scanf("%s",&s_password1);
                        while(1)
                        {
                            length=strlen(s_password1);
                            i=0;
                            special=0;
                            lower=0;
                            upper=0;
                            digit=0;
                            
                            while(i<length)
                            {
                                c=s_password1[i];
                                i++;
                                if(c=='@' || c=='!' || c=='#' || c=='$' )
                                {
                                    special=1;
                                }
                                if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9')
                                {
                                    digit=1;
                                }
                                if(c=='a' || c=='b' || c=='c' || c=='d' || c=='e' || c=='f' || c=='g' || c=='h' || c=='i' || c=='j' || c=='k' || c=='l' || c=='m' || c=='n' || c=='o' || c=='p' || c=='q' || c=='r' || c=='s' || c=='t' || c=='u' || c=='v' || c=='w' || c=='x' || c=='y' || c=='z')
                                {
                                    lower=1;
                                }
                                if(c=='A' || c=='B' || c=='C' || c=='D' || c=='E' || c=='F' || c=='G' || c=='H' || c=='I' || c=='J' || c=='K' || c=='L' || c=='M' || c=='N' || c=='O' || c=='P' || c=='Q' || c=='R' || c=='S' || c=='T' || c=='U' || c=='V' || c=='W' || c=='X' || c=='Y' || c=='Z')
                                {
                                    upper=1;
                                }
                                
                            }
                            if(length>=6 && upper==1 && lower==1 && digit==1 && special==1 && output==1)
                            {
                                break;
                            }
                            else
                            {
                                printf("\nEnter Valid Password : ");
                                output=scanf("%s",&s_password1);
                                continue;
                            }
                            
                        }
                        S_insert_data_end(&shead,s_prn1,s_name1,s_password1);
                        printf("\nRegistration Successful !!\n");
                        stmp=shead;
                        FILE *swfptr;
                            
                        swfptr=fopen("Student.txt","w");
                        while(stmp!=NULL)
                        {
                            index=0;
                            char final[100];
                            itoa(stmp->s_prn,Id,10);
                            for(l1=0;Id[l1]!='\0';l1++);
                            for(l2=0;stmp->s_name[l2]!='\0';l2++);
                            for(l3=0;stmp->s_password[l3]!='\0';l3++);
                            for(i=0;i<l1;i++)
                            {
                                final[index]=Id[i];
                                index++;

                            }
                            final[index]=';';
                            index++;
                            for(i=0;i<l2;i++)
                            {
                                final[index]=stmp->s_name[i];
                                index++;
                            }
                            final[index]=';';
                            index++;
                            for(i=0;i<l3;i++)
                            {
                                final[index]=stmp->s_password[i];
                                index++;
                            }
                            final[index]=';';
                            index++;

                            for(l4=0;final[l4]!='\0';l4++);
                            
                            fputs(final,swfptr);
                            fputs("\n",swfptr);


                            stmp=stmp->next;
                            
                        }
                        fclose(swfptr);
                        
                        S_printList(shead);
                        printf("\n");
                        
                    }
                    else
                    {
                        if(c1==3)                                              
                        {
                            break;
                        }
                        else
                        {
                            printf("\nWrong Choice !!\n");
                            continue;

                        }
                    }
                }
                
            }

                
        }
        else
        {
            if(choice==2)
            {
                while(1)
                {
                    printf("\n\nSelect your Option\n");
                    printf("1.Librarian Login\n");
                    printf("2.Student Login\n");
                    printf("3.Exit\n");
                    int c2;
                    scanf("%d",&c2);
                    if(c2==1)
                    {
                        printf("\nEnter Id & Password for Login : \n");
                        printf("\nEnter ID: ");
                        output= scanf("%d",&l_id1);
                        while(1)
                        {
                            digit=0;
                            i=0;
                            itoa(l_id1,Id,10);
                            length=strlen(Id);
                            while(i<length)
                            {
                                c=Id[i];
                                i++;
                                if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9')
                                {
                                    digit=digit+1;
                                }
                            }
                            if(strlen(Id)>=4 && output==1 && digit==length)
                            {
                                break;
                            }
                            else
                            {
                                printf("\nEnter Valid Id : ");
                                output=scanf("%d",&l_id1);
                                continue;
                            }
                        }
                        printf("\nEnter Valid Password like Pass.word@25 : ");
                        output= scanf("%s",&l_password1);
                        while(1)
                        {
                            length=strlen(l_password1);
                            i=0;
                            special=0;
                            lower=0;
                            upper=0;
                            digit=0;
                            
                            while(i<length)
                            {
                                c=l_password1[i];
                                i++;
                                if(c=='@' || c=='!' || c=='#' || c=='$' )
                                {
                                    special=1;
                                }
                                if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9')
                                {
                                    digit=1;
                                }
                                if(c=='a' || c=='b' || c=='c' || c=='d' || c=='e' || c=='f' || c=='g' || c=='h' || c=='i' || c=='j' || c=='k' || c=='l' || c=='m' || c=='n' || c=='o' || c=='p' || c=='q' || c=='r' || c=='s' || c=='t' || c=='u' || c=='v' || c=='w' || c=='x' || c=='y' || c=='z')
                                {
                                    lower=1;
                                }
                                if(c=='A' || c=='B' || c=='C' || c=='D' || c=='E' || c=='F' || c=='G' || c=='H' || c=='I' || c=='J' || c=='K' || c=='L' || c=='M' || c=='N' || c=='O' || c=='P' || c=='Q' || c=='R' || c=='S' || c=='T' || c=='U' || c=='V' || c=='W' || c=='X' || c=='Y' || c=='Z')
                                {
                                    upper=1;
                                }
                                
                            }
                            if(length>=6 && upper==1 && lower==1 && digit==1 && special==1 && output==1)
                            {
                                break;
                            }
                            else
                            {
                                printf("\nEnter Valid Password : ");
                                output=scanf("%s",&l_password1);
                                continue;
                            }
                            
                        }
                        int i,val=0,l1=0,l2=0;
                        struct Librarian *tmp=lhead;
                        while(tmp!=NULL)
                        {
                            for(l1=0;tmp->l_password[l1]!='\0';l1++);
                            for(l2=0;l_password1[l2]!='\0';l2++);
                            if(l1==l2)
                            {
                                for(i=0;i<l1;i++)
                                {
                                    if(tmp->l_password[i]==l_password1[i])
                                    {
                                        val=val+1;
                                        
                                    }
                                    else
                                    {
                                        val=0;
                                    }
                                    
                                }
                                //printf("\n%d",val);
                                if(val==l1 && tmp->l_id==l_id1)
                                {
                                    printf("\nLogin Successful !!\n");
                                    while(1)
                                    {
                                        printf("\n\nSelect your Option\n");
                                        printf("1.Add Book\n");
                                        printf("2.Delete Book\n");
                                        printf("3.Issue Book\n");
                                        printf("4.Return Book\n");
                                        printf("5.Available Books Details\n");
                                        printf("6.Issued Books Details\n");
                                        printf("7.Total Issued Books\n");
                                        printf("8.Total Available Books\n");
                                        printf("9.Delete Student\n");
                                        printf("10.Exit\n");
                                        int c3;
                                        scanf("%d",&c3);
                                        if(c3==1)
                                        {
                                            printf("\nBook Details :\n");
                                            printf("\nEnter Book Id :");
                                            output= scanf("%d",&b_id1);
                                            while(1)
                                            {
                                                digit=0;
                                                i=0;
                                                itoa(b_id1,Id,10);
                                                length=strlen(Id);
                                                while(i<length)
                                                {
                                                    c=Id[i];
                                                    i++;
                                                    if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9')
                                                    {
                                                        digit=digit+1;
                                                    }
                                                }
                                                if(strlen(Id)>=4 && output==1 && digit==length)
                                                {
                                                    break;
                                                }
                                                else
                                                {
                                                    printf("\nEnter Valid Book Id : ");
                                                    output=scanf("%d",&b_id1);
                                                    continue;
                                                }
                                            }
                                            printf("\nEnter Book Name :");
                                            output=scanf("%s",&b_name1);
                                            while(1)
                                            {
                                                //printf("\n%d",strlen(s_name1));
                                                special=0;
                                                lower=0;
                                                upper=0;
                                                length=strlen(b_name1);
                                                i=0;
                                                while(i<length)
                                                {
                                                    c=b_name1[i];
                                                    i++;
                                                    if(c=='_' || c=='@' || c=='!' || c=='#' || c=='$' )
                                                    {
                                                        special=special+1;
                                                    }
                                                    if(c=='a' || c=='b' || c=='c' || c=='d' || c=='e' || c=='f' || c=='g' || c=='h' || c=='i' || c=='j' || c=='k' || c=='l' || c=='m' || c=='n' || c=='o' || c=='p' || c=='q' || c=='r' || c=='s' || c=='t' || c=='u' || c=='v' || c=='w' || c=='x' || c=='y' || c=='z')
                                                    {
                                                        lower=lower+1;
                                                    }
                                                    if(c=='A' || c=='B' || c=='C' || c=='D' || c=='E' || c=='F' || c=='G' || c=='H' || c=='I' || c=='J' || c=='K' || c=='L' || c=='M' || c=='N' || c=='O' || c=='P' || c=='Q' || c=='R' || c=='S' || c=='T' || c=='U' || c=='V' || c=='W' || c=='X' || c=='Y' || c=='Z')
                                                    {
                                                        upper=upper+1;
                                                    }

                                                }
                                                if(strlen(b_name1)>=4 && output==1 && (special+lower+upper)==length)
                                                {
                                                    break;
                                                }
                                                else
                                                {
                                                    printf("\nEnter Valid Book Name : ");
                                                    output=scanf("%s",&b_name1);
                                                    continue;
                                                }
                                            }
                                            printf("\nEnter Book Author : ");
                                            output=scanf("%s",&b_author1);
                                            while(1)
                                            {
                                                special=0;
                                                lower=0;
                                                upper=0;
                                                length=strlen(b_author1);
                                                i=0;
                                                while(i<length)
                                                {
                                                    c=b_author1[i];
                                                    i++;
                                                    if(c=='_' || c=='@' || c=='!' || c=='#' || c=='$' )
                                                    {
                                                        special=special+1;
                                                    }
                                                    
                                                    if(c=='a' || c=='b' || c=='c' || c=='d' || c=='e' || c=='f' || c=='g' || c=='h' || c=='i' || c=='j' || c=='k' || c=='l' || c=='m' || c=='n' || c=='o' || c=='p' || c=='q' || c=='r' || c=='s' || c=='t' || c=='u' || c=='v' || c=='w' || c=='x' || c=='y' || c=='z')
                                                    {
                                                        lower=lower+1;
                                                    }
                                                    if(c=='A' || c=='B' || c=='C' || c=='D' || c=='E' || c=='F' || c=='G' || c=='H' || c=='I' || c=='J' || c=='K' || c=='L' || c=='M' || c=='N' || c=='O' || c=='P' || c=='Q' || c=='R' || c=='S' || c=='T' || c=='U' || c=='V' || c=='W' || c=='X' || c=='Y' || c=='Z')
                                                    {
                                                        upper=upper+1;
                                                    }

                                                }
                                                if(strlen(b_author1)>=4 && output==1 && (special+lower+upper)==length)
                                                {
                                                    break;
                                                }
                                                else
                                                {
                                                    printf("\nEnter Valid Book Author : ");
                                                    output=scanf("%s",&b_author1);
                                                    continue;
                                                }
                                            }
                                            printf("\nEnter Book Publication : ");
                                            output=scanf("%s",&b_publication1);
                                            while(1)
                                            {
                                                special=0;
                                                lower=0;
                                                upper=0;
                                                length=strlen(b_publication1);
                                                i=0;
                                                while(i<length)
                                                {
                                                    c=b_publication1[i];
                                                    i++;
                                                    if(c=='_' || c=='@' || c=='!' || c=='#' || c=='$' )
                                                    {
                                                        special=special+1;
                                                    }
                                                    
                                                    if(c=='a' || c=='b' || c=='c' || c=='d' || c=='e' || c=='f' || c=='g' || c=='h' || c=='i' || c=='j' || c=='k' || c=='l' || c=='m' || c=='n' || c=='o' || c=='p' || c=='q' || c=='r' || c=='s' || c=='t' || c=='u' || c=='v' || c=='w' || c=='x' || c=='y' || c=='z')
                                                    {
                                                        lower=lower+1;
                                                    }
                                                    if(c=='A' || c=='B' || c=='C' || c=='D' || c=='E' || c=='F' || c=='G' || c=='H' || c=='I' || c=='J' || c=='K' || c=='L' || c=='M' || c=='N' || c=='O' || c=='P' || c=='Q' || c=='R' || c=='S' || c=='T' || c=='U' || c=='V' || c=='W' || c=='X' || c=='Y' || c=='Z')
                                                    {
                                                        upper=upper+1;
                                                    }

                                                }
                                                if(strlen(b_publication1)>=4 && output==1 && (special+lower+upper)==length)
                                                {
                                                    break;
                                                }
                                                else
                                                {
                                                    printf("\nEnter Valid Book Publication : ");
                                                    output=scanf("%s",&b_publication1);
                                                    continue;
                                                }
                                            }
                                            B_insert_data_end(&bhead,b_id1,b_name1,b_author1,b_publication1);
                                            btmp=bhead;
                                            FILE *bwfptr;
                                                
                                            bwfptr=fopen("Book.txt","w");
                                            while(btmp!=NULL)
                                            {
                                                index=0;
                                                char final[100];
                                                itoa(btmp->b_id,Id,10);
                                                for(l1=0;Id[l1]!='\0';l1++);
                                                for(l2=0;btmp->b_name[l2]!='\0';l2++);
                                                for(l3=0;btmp->b_author[l3]!='\0';l3++);
                                                for(l4=0;btmp->b_publication[l4]!='\0';l4++);
                                                //printf("\n%d\t%d\t%d\t%d",l1,l2,l3,l4);
                                                for(i=0;i<l1;i++)
                                                {
                                                    final[index]=Id[i];
                                                    index++;

                                                }
                                                final[index]=';';
                                                index++;
                                                for(i=0;i<l2;i++)
                                                {
                                                    final[index]=btmp->b_name[i];
                                                    index++;
                                                }
                                                final[index]=';';
                                                index++;
                                                for(i=0;i<l3;i++)
                                                {
                                                    final[index]=btmp->b_author[i];
                                                    index++;
                                                }
                                                final[index]=';';
                                                index++;
                                                for(i=0;i<l4;i++)
                                                {
                                                    final[index]=btmp->b_publication[i];
                                                    index++;
                                                }
                                                final[index]=';';
                                                index++;
                                                
                                                fputs(final,bwfptr);
                                                fputs("\n",bwfptr);


                                                btmp=btmp->next;
                                                
                                            }
                                            fclose(bwfptr);
                                            
                                            printf("\nAvailable Book Details :\n");
                                            printf("\nBook Id\t\t\t Name\t\t\t\tAuthor\t\t   Publication \n\n");
    
                                            B_printList(bhead);
                                            
                                        }
                                        else
                                        {
                                            if(c3==2)
                                            {
                                                printf("\nBook Details :\n");
                                                printf("\nEnter Book Id :");
                                                output=scanf("%d",&b_id1);
                                                while(1)
                                                {
                                                    digit=0;
                                                    i=0;
                                                    itoa(b_id1,Id,10);
                                                    length=strlen(Id);
                                                    while(i<length)
                                                    {
                                                        c=Id[i];
                                                        i++;
                                                        if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9')
                                                        {
                                                            digit=digit+1;
                                                        }
                                                    }
                                                    if(strlen(Id)>=4 && output==1 && digit==length)
                                                    {
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        printf("\nEnter Valid Book Id : ");
                                                        output=scanf("%d",&b_id1);
                                                        continue;
                                                    }
                                                }
                                                Book_delete_only(&bhead,b_id1);
                                                                    
                                                btmp=bhead;
                                                FILE *bwfptr;
                                                    
                                                bwfptr=fopen("Book.txt","w");
                                                while(btmp!=NULL)
                                                {
                                                    index=0;
                                                    char final[100];
                                                    itoa(btmp->b_id,Id,10);
                                                    for(l1=0;Id[l1]!='\0';l1++);
                                                    for(l2=0;btmp->b_name[l2]!='\0';l2++);
                                                    for(l3=0;btmp->b_author[l3]!='\0';l3++);
                                                    for(l4=0;btmp->b_publication[l4]!='\0';l4++);
                                                    //printf("\n%d\t%d\t%d\t%d",l1,l2,l3,l4);
                                                    for(i=0;i<l1;i++)
                                                    {
                                                        final[index]=Id[i];
                                                        index++;

                                                    }
                                                    final[index]=';';
                                                    index++;
                                                    for(i=0;i<l2;i++)
                                                    {
                                                        final[index]=btmp->b_name[i];
                                                        index++;
                                                    }
                                                    final[index]=';';
                                                    index++;
                                                    for(i=0;i<l3;i++)
                                                    {
                                                        final[index]=btmp->b_author[i];
                                                        index++;
                                                    }
                                                    final[index]=';';
                                                    index++;
                                                    for(i=0;i<l4;i++)
                                                    {
                                                        final[index]=btmp->b_publication[i];
                                                        index++;
                                                    }
                                                    final[index]=';';
                                                    index++;
                                                    
                                                    fputs(final,bwfptr);
                                                    fputs("\n",bwfptr);


                                                    btmp=btmp->next;
                                                    
                                                }
                                                fclose(bwfptr);
                                                
                                                printf("\nAvailable Book Details :\n");
                                                printf("\nBook Id\t\t\t Name\t\t\t\tAuthor\t\t   Publication \n\n");
    
                                                B_printList(bhead);
                                            }
                                            else
                                            {
                                                if(c3==3)
                                                {
                                                    printf("\nEnter Details : \n");
                                                    printf("\nEnter the Book Id : ");
                                                    output= scanf("%d",&b_id1);
                                                    while(1)
                                                    {
                                                        digit=0;
                                                        i=0;
                                                        itoa(b_id1,Id,10);
                                                        length=strlen(Id);
                                                        while(i<length)
                                                        {
                                                            c=Id[i];
                                                            i++;
                                                            if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9')
                                                            {
                                                                digit=digit+1;
                                                            }
                                                        }
                                                        if(strlen(Id)>=4 && output==1 && digit==length)
                                                        {
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            printf("\nEnter Valid Book Id : ");
                                                            output=scanf("%d",&b_id1);
                                                            continue;
                                                        }
                                                    }
                                                    printf("\nEnter the PRN : ");
                                                    output= scanf("%d",&s_prn1);
                                                    while(1)
                                                    {
                                                        digit=0;
                                                        i=0;
                                                        itoa(s_prn1,Id,10);
                                                        length=strlen(Id);
                                                        while(i<length)
                                                        {
                                                            c=Id[i];
                                                            i++;
                                                            if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9')
                                                            {
                                                                digit=digit+1;
                                                            }
                                                        }
                                                        if((strlen(Id)==10 ||strlen(Id)==9) && output==1 && digit==length)
                                                        {
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            printf("\nEnter Valid PRN : ");
                                                            output=scanf("%d",&s_prn1);
                                                            continue;
                                                        }
                                                    }
                                                    struct Student *tmp=shead;
                                                    int val=0;
                                                    while(tmp!=NULL)
                                                    {
                                                        if(tmp->s_prn==s_prn1)
                                                        {
                                                            val=1;
                                                            break;
                                                        }
                                                        tmp=tmp->next;
                                                    }
                                                    struct Book *tmp1=bhead;
                                                    if(val==1)
                                                    {
                                                        while(tmp1!=NULL)
                                                        {
                                                            if(tmp1->b_id==b_id1)
                                                            {
                                                                SB_insert_data_end(&sbhead,tmp1->b_id,tmp1->b_name,tmp1->b_author,tmp1->b_publication,s_prn1,day1,month1,year1);
                                                                //printf("\nBook Issued Successfully !!!\n");
                                                                sbtmp=sbhead;
                                                                FILE *sbwfptr;
                                                                sbwfptr=fopen("StudentBook.txt","w");
                                                                while(sbtmp!=NULL)
                                                                {
                                                                    char prn[10],d[10],m[10],y[10];
                                                                    index=0;
                                                                    int l5,l6,l7,l8;
                                                                    char final[100];
                                                                    itoa(sbtmp->b_id,Id,10);
                                                                    itoa(sbtmp->s_prn,prn,10);
                                                                    itoa(sbtmp->day,d,10);
                                                                    itoa(sbtmp->month,m,10);
                                                                    itoa(sbtmp->year,y,10);
                                                                    for(l5=0;d[l5]!='\0';l5++);
                                                                    for(l6=0;m[l6]!='\0';l6++);
                                                                    for(l7=0;y[l7]!='\0';l7++);
                                                                    for(l8=0;prn[l8]!='\0';l8++);
                                                                    for(l1=0;Id[l1]!='\0';l1++);
                                                                    for(l2=0;sbtmp->b_name[l2]!='\0';l2++);
                                                                    for(l3=0;sbtmp->b_author[l3]!='\0';l3++);
                                                                    for(l4=0;sbtmp->b_publication[l4]!='\0';l4++);
                                                                    //printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",l1,l2,l3,l4,l8,l5,l6,l7);
                                                                    
                                                                    for(i=0;i<l1;i++)
                                                                    {
                                                                        final[index]=Id[i];
                                                                        index++;

                                                                    }
                                                                    final[index]=';';
                                                                    index++;
                                                                    for(i=0;i<l2;i++)
                                                                    {
                                                                        final[index]=sbtmp->b_name[i];
                                                                        index++;
                                                                    }
                                                                    final[index]=';';
                                                                    index++;
                                                                    for(i=0;i<l3;i++)
                                                                    {
                                                                        final[index]=sbtmp->b_author[i];
                                                                        index++;
                                                                    }
                                                                    final[index]=';';
                                                                    index++;
                                                                    for(i=0;i<l4;i++)
                                                                    {
                                                                        final[index]=sbtmp->b_publication[i];
                                                                        index++;
                                                                    }
                                                                    final[index]=';';
                                                                    index++;
                                                                    for(i=0;i<l8;i++)
                                                                    {
                                                                        final[index]=prn[i];
                                                                        index++;
                                                                    }
                                                                    final[index]=';';
                                                                    index++;
                                                                    for(i=0;i<l5;i++)
                                                                    {
                                                                        final[index]=d[i];
                                                                        index++;
                                                                    }
                                                                    final[index]=';';
                                                                    index++;
                                                                    for(i=0;i<l6;i++)
                                                                    {
                                                                        final[index]=m[i];
                                                                        index++;
                                                                    }
                                                                    final[index]=';';
                                                                    index++;
                                                                    for(i=0;i<l7;i++)
                                                                    {
                                                                        final[index]=y[i];
                                                                        index++;
                                                                    }
                                                                    final[index]=';';
                                                                    index++;
                                                                    
                                                                    fputs(final,sbwfptr);
                                                                    fputs("\n",sbwfptr);
                                                                    sbtmp=sbtmp->next;
                                                                    
                                                                }
                                                                fclose(sbwfptr);
                                                                
                                                                Book_delete(&bhead,b_id1);
                                                                btmp=bhead;
                                                                FILE *bwfptr;
                                                                    
                                                                bwfptr=fopen("Book.txt","w");
                                                                while(btmp!=NULL)
                                                                {
                                                                    index=0;
                                                                    char final[100];
                                                                    itoa(btmp->b_id,Id,10);
                                                                    for(l1=0;Id[l1]!='\0';l1++);
                                                                    for(l2=0;btmp->b_name[l2]!='\0';l2++);
                                                                    for(l3=0;btmp->b_author[l3]!='\0';l3++);
                                                                    for(l4=0;btmp->b_publication[l4]!='\0';l4++);
                                                                    //printf("\n%d\t%d\t%d\t%d",l1,l2,l3,l4);
                                                                    for(i=0;i<l1;i++)
                                                                    {
                                                                        final[index]=Id[i];
                                                                        index++;

                                                                    }
                                                                    final[index]=';';
                                                                    index++;
                                                                    for(i=0;i<l2;i++)
                                                                    {
                                                                        final[index]=btmp->b_name[i];
                                                                        index++;
                                                                    }
                                                                    final[index]=';';
                                                                    index++;
                                                                    for(i=0;i<l3;i++)
                                                                    {
                                                                        final[index]=btmp->b_author[i];
                                                                        index++;
                                                                    }
                                                                    final[index]=';';
                                                                    index++;
                                                                    for(i=0;i<l4;i++)
                                                                    {
                                                                        final[index]=btmp->b_publication[i];
                                                                        index++;
                                                                    }
                                                                    final[index]=';';
                                                                    index++;
                                                                    
                                                                    fputs(final,bwfptr);
                                                                    fputs("\n",bwfptr);


                                                                    btmp=btmp->next;
                                                                    
                                                                }
                                                                fclose(bwfptr);
                                                                
                                                                printf("\nIssued Book Details :\n");
                                                                printf("\nBook Id\t\t\t Name\t\t\t\tAuthor\t\t   Publication \n\n");
                                                                SB_printList_all(sbhead);
                                                                printf("\nAvailable Book Details :\n");
                                                                printf("\nBook Id\t\t\t Name\t\t\t\tAuthor\t\t   Publication \n\n");
                                                                B_printList(bhead);
                                                                break;
                                                            }
                                                            tmp1=tmp1->next;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        printf("\nStudent Account Not Exist !!!");
                                                    }
                                                    
                                                }
                                                else
                                                {
                                                    if(c3==4)
                                                    {
                                                        printf("\nEnter Details : \n");
                                                        printf("\nEnter the Book Id : ");
                                                        output= scanf("%d",&b_id1);
                                                        while(1)
                                                        {
                                                            digit=0;
                                                            i=0;
                                                            itoa(b_id1,Id,10);
                                                            length=strlen(Id);
                                                            while(i<length)
                                                            {
                                                                c=Id[i];
                                                                i++;
                                                                if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9')
                                                                {
                                                                    digit=digit+1;
                                                                }
                                                            }
                                                            if(strlen(Id)>=4 && output==1 && digit==length)
                                                            {
                                                                break;
                                                            }
                                                            else
                                                            {
                                                                printf("\nEnter Valid Book Id : ");
                                                                output=scanf("%d",&b_id1);
                                                                continue;
                                                            }
                                                        }
                                                        printf("\nEnter the PRN : ");
                                                        output= scanf("%d",&s_prn1);
                                                        while(1)
                                                        {
                                                            digit=0;
                                                            i=0;
                                                            itoa(s_prn1,Id,10);
                                                            length=strlen(Id);
                                                            while(i<length)
                                                            {
                                                                c=Id[i];
                                                                i++;
                                                                if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9')
                                                                {
                                                                    digit=digit+1;
                                                                }
                                                            }
                                                            if((strlen(Id)==10 ||strlen(Id)==9) && output==1 && digit==length)
                                                            {
                                                                break;
                                                            }
                                                            else
                                                            {
                                                                printf("\nEnter Valid PRN : ");
                                                                output=scanf("%d",&s_prn1);
                                                                continue;
                                                            }
                                                        }
                                                        struct Student *tmp=shead;
                                                        int val=0;
                                                        while(tmp!=NULL)
                                                        {
                                                            if(tmp->s_prn==s_prn1)
                                                            {
                                                                val=1;
                                                                break;
                                                            }
                                                            tmp=tmp->next;
                                                        }
                                                        struct StudentBook *tmp1=sbhead;
                                                        if(val==1)
                                                        {
                                                            while(tmp1!=NULL)
                                                            {
                                                                if(tmp1->b_id==b_id1)
                                                                {
                                                                    B_insert_data_end(&bhead,tmp1->b_id,tmp1->b_name,tmp1->b_author,tmp1->b_publication);
                                                                    btmp=bhead;
                                                                    FILE *bwfptr;
                                                                        
                                                                    bwfptr=fopen("Book.txt","w");
                                                                    while(btmp!=NULL)
                                                                    {
                                                                        index=0;
                                                                        char final[100];
                                                                        itoa(btmp->b_id,Id,10);
                                                                        for(l1=0;Id[l1]!='\0';l1++);
                                                                        for(l2=0;btmp->b_name[l2]!='\0';l2++);
                                                                        for(l3=0;btmp->b_author[l3]!='\0';l3++);
                                                                        for(l4=0;btmp->b_publication[l4]!='\0';l4++);
                                                                        for(i=0;i<l1;i++)
                                                                        {
                                                                            final[index]=Id[i];
                                                                            index++;

                                                                        }
                                                                        final[index]=';';
                                                                        index++;
                                                                        for(i=0;i<l2;i++)
                                                                        {
                                                                            final[index]=btmp->b_name[i];
                                                                            index++;
                                                                        }
                                                                        final[index]=';';
                                                                        index++;
                                                                        for(i=0;i<l3;i++)
                                                                        {
                                                                            final[index]=btmp->b_author[i];
                                                                            index++;
                                                                        }
                                                                        final[index]=';';
                                                                        index++;
                                                                        for(i=0;i<l4;i++)
                                                                        {
                                                                            final[index]=btmp->b_publication[i];
                                                                            index++;
                                                                        }
                                                                        final[index]=';';
                                                                        index++;
                                                                        
                                                                        fputs(final,bwfptr);
                                                                        fputs("\n",bwfptr);


                                                                        btmp=btmp->next;
                                                                        
                                                                    }
                                                                    fclose(bwfptr);
                                                                    
                                                                    StudentBook_delete(&sbhead,tmp1->s_prn,b_id1);
                                                                    sbtmp=sbhead;
                                                                    FILE *sbwfptr;
                                                                    sbwfptr=fopen("StudentBook.txt","w");
                                                                    while(sbtmp!=NULL)
                                                                    {
                                                                        char prn[10],d[10],m[10],y[10];
                                                                        index=0;
                                                                        int l5,l6,l7,l8;
                                                                        char final[100];
                                                                        itoa(sbtmp->b_id,Id,10);
                                                                        itoa(sbtmp->s_prn,prn,10);
                                                                        itoa(sbtmp->day,d,10);
                                                                        itoa(sbtmp->month,m,10);
                                                                        itoa(sbtmp->year,y,10);
                                                                        for(l5=0;d[l5]!='\0';l5++);
                                                                        for(l6=0;m[l6]!='\0';l6++);
                                                                        for(l7=0;y[l7]!='\0';l7++);
                                                                        for(l8=0;prn[l8]!='\0';l8++);
                                                                        for(l1=0;Id[l1]!='\0';l1++);
                                                                        for(l2=0;sbtmp->b_name[l2]!='\0';l2++);
                                                                        for(l3=0;sbtmp->b_author[l3]!='\0';l3++);
                                                                        for(l4=0;sbtmp->b_publication[l4]!='\0';l4++);
                                                                        //printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",l1,l2,l3,l4,l8,l5,l6,l7);
                                                                        
                                                                        for(i=0;i<l1;i++)
                                                                        {
                                                                            final[index]=Id[i];
                                                                            index++;

                                                                        }
                                                                        final[index]=';';
                                                                        index++;
                                                                        for(i=0;i<l2;i++)
                                                                        {
                                                                            final[index]=sbtmp->b_name[i];
                                                                            index++;
                                                                        }
                                                                        final[index]=';';
                                                                        index++;
                                                                        for(i=0;i<l3;i++)
                                                                        {
                                                                            final[index]=sbtmp->b_author[i];
                                                                            index++;
                                                                        }
                                                                        final[index]=';';
                                                                        index++;
                                                                        for(i=0;i<l4;i++)
                                                                        {
                                                                            final[index]=sbtmp->b_publication[i];
                                                                            index++;
                                                                        }
                                                                        final[index]=';';
                                                                        index++;
                                                                        for(i=0;i<l8;i++)
                                                                        {
                                                                            final[index]=prn[i];
                                                                            index++;
                                                                        }
                                                                        final[index]=';';
                                                                        index++;
                                                                        for(i=0;i<l5;i++)
                                                                        {
                                                                            final[index]=d[i];
                                                                            index++;
                                                                        }
                                                                        final[index]=';';
                                                                        index++;
                                                                        for(i=0;i<l6;i++)
                                                                        {
                                                                            final[index]=m[i];
                                                                            index++;
                                                                        }
                                                                        final[index]=';';
                                                                        index++;
                                                                        for(i=0;i<l7;i++)
                                                                        {
                                                                            final[index]=y[i];
                                                                            index++;
                                                                        }
                                                                        final[index]=';';
                                                                        index++;
                                                                        
                                                                        fputs(final,sbwfptr);
                                                                        fputs("\n",sbwfptr);
                                                                        sbtmp=sbtmp->next;
                                                                        
                                                                    }
                                                                    fclose(sbwfptr);
                                                                    
                                                                    printf("\nIssued Book Details :\n");
                                                                    printf("\nBook Id\t\t\t Name\t\t\t\tAuthor\t\t   Publication \n\n");
                                                                    SB_printList(sbhead);
                                                                    printf("\nAvailable Book Details :\n");
                                                                    printf("\nBook Id\t\t\t Name\t\t\t\tAuthor\t\t   Publication \n\n");
                                                                    B_printList(bhead);
                                                                    break;
                                                                }
                                                                tmp1=tmp1->next;
                                                            }
                                                        }
                                                        else
                                                        {
                                                            printf("\nStudent Account Not Exist !!!");
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if(c3==5)
                                                        {
                                                            printf("\nAvailable Book Details :\n");
                                                            printf("\nBook Id\t\t\t Name\t\t\t\tAuthor\t\t   Publication \n\n");
    
                                                            B_printList(bhead);

                                                        }
                                                        else
                                                        {
                                                            if(c3==6)
                                                            {
                                                                printf("\nIssued Book Details :\n");
                                                                printf("\nBook Id\t\t\t Name\t\t\t\tAuthor\t\t   Publication \n\n");
    
                                                                SB_printList(sbhead);

                                                            }

                                                            else
                                                            {
                                                                if(c3==7)
                                                                {
                                                                    int Total=0;
                                                                    struct StudentBook *tmp=sbhead;
                                                                    while(tmp!=NULL)
                                                                    {
                                                                        Total=Total+1;
                                                                        tmp=tmp->next;
                                                                    }
                                                                    printf("\nTotal Issued Books : %d",Total);
                                                                    

                                                                }
                                                                else
                                                                {
                                                                    if(c3==8)
                                                                    {
                                                                        int Total=0;
                                                                        struct Book *tmp=bhead;
                                                                        while(tmp!=NULL)
                                                                        {
                                                                            Total=Total+1;
                                                                            tmp=tmp->next;
                                                                        }
                                                                        printf("\nTotal Available Books : %d",Total);
                                                                    
                                                                    }
                                                                    else
                                                                    {
                                                                        if(c3==9)
                                                                        {
                                                                            printf("\nStudent Details :\n");
                                                                            printf("\nEnter Student PRN :");
                                                                            scanf("%d",&s_prn1);
                                                                            Student_delete(&shead,s_prn1);
                                                                            
                                                                            stmp=shead;
                                                                            FILE *swfptr;
                                                                                
                                                                            swfptr=fopen("Student.txt","w");
                                                                            while(stmp!=NULL)
                                                                            {
                                                                                index=0;
                                                                                char final[100];
                                                                                itoa(stmp->s_prn,Id,10);
                                                                                for(l1=0;Id[l1]!='\0';l1++);
                                                                                for(l2=0;stmp->s_name[l2]!='\0';l2++);
                                                                                for(l3=0;stmp->s_password[l3]!='\0';l3++);
                                                                                for(i=0;i<l1;i++)
                                                                                {
                                                                                    final[index]=Id[i];
                                                                                    index++;

                                                                                }
                                                                                final[index]=';';
                                                                                index++;
                                                                                for(i=0;i<l2;i++)
                                                                                {
                                                                                    final[index]=stmp->s_name[i];
                                                                                    index++;
                                                                                }
                                                                                final[index]=';';
                                                                                index++;
                                                                                for(i=0;i<l3;i++)
                                                                                {
                                                                                    final[index]=stmp->s_password[i];
                                                                                    index++;
                                                                                }
                                                                                final[index]=';';
                                                                                index++;

                                                                                for(l4=0;final[l4]!='\0';l4++);
                                                                                
                                                                                fputs(final,swfptr);
                                                                                fputs("\n",swfptr);


                                                                                stmp=stmp->next;
                                                                                
                                                                            }
                                                                            fclose(swfptr);
                                                                            
                                                                            S_printList(shead);
                                                                        }
                                                                        else
                                                                        {
                                                                            if(c3==10)
                                                                            {
                                                                                break;
                                                                            }
                                                                            else
                                                                            {
                                                                                printf("\nWrong Choice !!\n");
                                                                                continue;
                                                                            }

                                                                        }

                                                                    }

                                                                }
                                                            }
                                                        }

                                                    }       
                                                }

                                            }

                                        }
                                        
                                    }
                                    
                                }
                            }
                            
                            tmp=tmp->next;
                        }
                        
                    }
                    
                    else
                    {
                        if(c2==2)
                        {
                            printf("\nEnter PRN & Password for Login : \n");
                            printf("\nEnter PRN: ");
                            output= scanf("%d",&s_prn1);
                            while(1)
                            {
                                digit=0;
                                i=0;
                                itoa(s_prn1,Id,10);
                                length=strlen(Id);
                                while(i<length)
                                {
                                    c=Id[i];
                                    i++;
                                    if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9')
                                    {
                                        digit=digit+1;
                                    }
                                }
                                if((strlen(Id)==10 ||strlen(Id)==9) && output==1 && digit==length)
                                {
                                    break;
                                }
                                else
                                {
                                    printf("\nEnter Valid PRN : ");
                                    output=scanf("%d",&s_prn1);
                                    continue;
                                }
                            }
                            printf("\nEnter Valid Password like Pass.word@25 : ");
                            output= scanf("%s",&s_password1);
                            while(1)
                            {
                                length=strlen(s_password1);
                                i=0;
                                special=0;
                                lower=0;
                                upper=0;
                                digit=0;
                                
                                while(i<length)
                                {
                                    c=s_password1[i];
                                    i++;
                                    if(c=='@' || c=='!' || c=='#' || c=='$' )
                                    {
                                        special=1;
                                    }
                                    if(c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9')
                                    {
                                        digit=1;
                                    }
                                    if(c=='a' || c=='b' || c=='c' || c=='d' || c=='e' || c=='f' || c=='g' || c=='h' || c=='i' || c=='j' || c=='k' || c=='l' || c=='m' || c=='n' || c=='o' || c=='p' || c=='q' || c=='r' || c=='s' || c=='t' || c=='u' || c=='v' || c=='w' || c=='x' || c=='y' || c=='z')
                                    {
                                        lower=1;
                                    }
                                    if(c=='A' || c=='B' || c=='C' || c=='D' || c=='E' || c=='F' || c=='G' || c=='H' || c=='I' || c=='J' || c=='K' || c=='L' || c=='M' || c=='N' || c=='O' || c=='P' || c=='Q' || c=='R' || c=='S' || c=='T' || c=='U' || c=='V' || c=='W' || c=='X' || c=='Y' || c=='Z')
                                    {
                                        upper=1;
                                    }
                                    
                                }
                                if(length>=6 && upper==1 && lower==1 && digit==1 && special==1 && output==1)
                                {
                                    break;
                                }
                                else
                                {
                                    printf("\nEnter Valid Password : ");
                                    output=scanf("%s",&s_password1);
                                    continue;
                                }
                                
                            }
                            int i,val=0,l1=0,l2=0;
                            struct Student *tmp=shead;
                            while(tmp!=NULL)
                            {
                                for(l1=0;tmp->s_password[l1]!='\0';l1++);
                                for(l2=0;s_password1[l2]!='\0';l2++);
                                if(l1==l2)
                                {
                                    for(i=0;i<l1;i++)
                                    {
                                        if(tmp->s_password[i]==s_password1[i])
                                        {
                                            val=val+1;
                                            
                                        }
                                        else
                                        {
                                            val=0;
                                        }
                                        
                                    }
                                    if(val==l1 && tmp->s_prn==s_prn1)
                                    {
                                        printf("\nLogin Successful !!\n");
                                        while(1)
                                        {
                                            printf("\n\nSelect your Option\n");
                                            printf("1.Search Book\n");
                                            printf("2.Display Issued Book Details\n");
                                            printf("3.Exit\n");
                                            int c4;
                                            scanf("%d",&c4);
                                            if(c4==1)
                                            {
                                                while(1)
                                                {
                                                    printf("\n\nSelect your Option\n");
                                                    printf("1.Search by Book Name\n");
                                                    printf("2.Search by Book Author\n");   
                                                    printf("3.Search by Book Publication\n");  
                                                    printf("4.Exit\n");
                                                    int c5;
                                                    scanf("%d",&c5);
                                                    if(c5==1)
                                                    {
                                                        printf("\nEnter the Book Name : ");
                                                        output=scanf("%s",&b_name1);
                                                        while(1)
                                                        {
                                                            special=0;
                                                            lower=0;
                                                            upper=0;
                                                            length=strlen(b_name1);
                                                            i=0;
                                                            while(i<length)
                                                            {
                                                                c=b_name1[i];
                                                                i++;
                                                                if(c=='_' || c=='@' || c=='!' || c=='#' || c=='$' )
                                                                {
                                                                    special=special+1;
                                                                }
                                                                
                                                                if(c=='a' || c=='b' || c=='c' || c=='d' || c=='e' || c=='f' || c=='g' || c=='h' || c=='i' || c=='j' || c=='k' || c=='l' || c=='m' || c=='n' || c=='o' || c=='p' || c=='q' || c=='r' || c=='s' || c=='t' || c=='u' || c=='v' || c=='w' || c=='x' || c=='y' || c=='z')
                                                                {
                                                                    lower=lower+1;
                                                                }
                                                                if(c=='A' || c=='B' || c=='C' || c=='D' || c=='E' || c=='F' || c=='G' || c=='H' || c=='I' || c=='J' || c=='K' || c=='L' || c=='M' || c=='N' || c=='O' || c=='P' || c=='Q' || c=='R' || c=='S' || c=='T' || c=='U' || c=='V' || c=='W' || c=='X' || c=='Y' || c=='Z')
                                                                {
                                                                    upper=upper+1;
                                                                }

                                                            }
                                                            if(strlen(b_name1)>=4 && output==1 && (special+lower+upper)==length)
                                                            {
                                                                break;
                                                            }
                                                            else
                                                            {
                                                                printf("\nEnter Valid Book Name : ");
                                                                output=scanf("%s",&b_name1);
                                                                continue;
                                                            }
                                                        }
                                                        printf("\nBook Details :\n");
                                                        printf("\nBook Id\t\t\t Name\t\t\t\tAuthor\t\t   Publication \n\n");
                                                                    
                                                        int i,val=0,l1=0,l2=0;
                                                        struct Book *tmp=bhead;
                                                        while(tmp!=NULL)
                                                        {
                                                            for(l1=0;tmp->b_name[l1]!='\0';l1++);
                                                            for(l2=0;b_name1[l2]!='\0';l2++);
                                                            if(l1==l2)
                                                            {
                                                                for(i=0;i<l1;i++)
                                                                {
                                                                    if(tmp->b_name[i]==b_name1[i])
                                                                    {
                                                                        val=val+1;
                                                                        
                                                                    }
                                                                    else{
                                                                        val=0;
                                                                    }
                                                                    
                                                                }
                                                                //printf("\n%d",val);
                                                                if(val==l1)
                                                                {
                                                                    printf("%d\t%s\t%s\t%s",tmp->b_id,tmp->b_name,tmp->b_author,tmp->b_publication);
                                                                    break;
                                                                }
                                                            }
                                                            
                                                            tmp=tmp->next;
                                                        }
                                                        
                                                    }
                                                    else
                                                    {
                                                        if(c5==2)
                                                        {
                                                            printf("\nEnter the Book Author : ");
                                                            output=scanf("%s",&b_author1);
                                            
                                                            while(1)
                                                            {
                                                                special=0;
                                                                lower=0;
                                                                upper=0;
                                                                length=strlen(b_author1);
                                                                i=0;
                                                                while(i<length)
                                                                {
                                                                    c=b_author1[i];
                                                                    i++;
                                                                    if(c=='_' || c=='@' || c=='!' || c=='#' || c=='$' )
                                                                    {
                                                                        special=special+1;
                                                                    }
                                                                    if(c=='a' || c=='b' || c=='c' || c=='d' || c=='e' || c=='f' || c=='g' || c=='h' || c=='i' || c=='j' || c=='k' || c=='l' || c=='m' || c=='n' || c=='o' || c=='p' || c=='q' || c=='r' || c=='s' || c=='t' || c=='u' || c=='v' || c=='w' || c=='x' || c=='y' || c=='z')
                                                                    {
                                                                        lower=lower+1;
                                                                    }
                                                                    if(c=='A' || c=='B' || c=='C' || c=='D' || c=='E' || c=='F' || c=='G' || c=='H' || c=='I' || c=='J' || c=='K' || c=='L' || c=='M' || c=='N' || c=='O' || c=='P' || c=='Q' || c=='R' || c=='S' || c=='T' || c=='U' || c=='V' || c=='W' || c=='X' || c=='Y' || c=='Z')
                                                                    {
                                                                        upper=upper+1;
                                                                    }

                                                                }
                                                                if(strlen(b_author1)>=4 && output==1 && (special+lower+upper)==length)
                                                                {
                                                                    break;
                                                                }
                                                                else
                                                                {
                                                                    printf("\nEnter Valid Book Author : ");
                                                                    output=scanf("%s",&b_author1);
                                                                    continue;
                                                                }
                                                            }
                                                            printf("\nBook Details :\n");
                                                            printf("\nBook Id\t\t\t Name\t\t\t\tAuthor\t\t   Publication \n\n");
                                                                        
                                                            int i,val=0,l1=0,l2=0;
                                                            struct Book *tmp=bhead;
                                                            while(tmp!=NULL)
                                                            {
                                                                for(l1=0;tmp->b_author[l1]!='\0';l1++);
                                                                for(l2=0;b_author1[l2]!='\0';l2++);
                                                                if(l1==l2)
                                                                {
                                                                    for(i=0;i<l1;i++)
                                                                    {
                                                                        if(tmp->b_author[i]==b_author1[i])
                                                                        {
                                                                            val=val+1;
                                                                            
                                                                        }
                                                                        else{
                                                                            val=0;
                                                                        }
                                                                        
                                                                    }
                                                                    //printf("\n%d",val);
                                                                    if(val==l1)
                                                                    {
                                                                        printf("%d\t%s\t%s\t%s",tmp->b_id,tmp->b_name,tmp->b_author,tmp->b_publication);
                                                                        break;
                                                                    }
                                                                }
                                                                
                                                                tmp=tmp->next;
                                                            }
                                                        }
                                                        else
                                                        {
                                                            if(c5==3)
                                                            {
                                                                printf("\nEnter the Book Publication : ");
                                                                output=scanf("%s",&b_publication1);
                                                                while(1)
                                                                {
                                                                    special=0;
                                                                    lower=0;
                                                                    upper=0;
                                                                    length=strlen(b_publication1);
                                                                    i=0;
                                                                    while(i<length)
                                                                    {
                                                                        c=b_publication1[i];
                                                                        i++;
                                                                        if(c=='_' || c=='@' || c=='!' || c=='#' || c=='$' )
                                                                        {
                                                                            special=special+1;
                                                                        }
                                                                        if(c=='a' || c=='b' || c=='c' || c=='d' || c=='e' || c=='f' || c=='g' || c=='h' || c=='i' || c=='j' || c=='k' || c=='l' || c=='m' || c=='n' || c=='o' || c=='p' || c=='q' || c=='r' || c=='s' || c=='t' || c=='u' || c=='v' || c=='w' || c=='x' || c=='y' || c=='z')
                                                                        {
                                                                            lower=lower+1;
                                                                        }
                                                                        if(c=='A' || c=='B' || c=='C' || c=='D' || c=='E' || c=='F' || c=='G' || c=='H' || c=='I' || c=='J' || c=='K' || c=='L' || c=='M' || c=='N' || c=='O' || c=='P' || c=='Q' || c=='R' || c=='S' || c=='T' || c=='U' || c=='V' || c=='W' || c=='X' || c=='Y' || c=='Z')
                                                                        {
                                                                            upper=upper+1;
                                                                        }

                                                                    }
                                                                    if(strlen(b_publication1)>=4 && output==1 && (special+lower+upper)==length)
                                                                    {
                                                                        break;
                                                                    }
                                                                    else
                                                                    {
                                                                        printf("\nEnter Valid Book Publication : ");
                                                                        output=scanf("%s",&b_publication1);
                                                                        continue;
                                                                    }
                                                                }
                                                                printf("\nBook Details :\n");
                                                                printf("\nBook Id\t\t\t Name\t\t\t\tAuthor\t\t   Publication \n\n");
                                                                            
                                                                int i,val=0,l1=0,l2=0;
                                                                struct Book *tmp=bhead;
                                                                while(tmp!=NULL)
                                                                {
                                                                    for(l1=0;tmp->b_publication[l1]!='\0';l1++);
                                                                    for(l2=0;b_publication1[l2]!='\0';l2++);
                                                                    if(l1==l2)
                                                                    {
                                                                        for(i=0;i<l1;i++)
                                                                        {
                                                                            if(tmp->b_publication[i]==b_publication1[i])
                                                                            {
                                                                                val=val+1;
                                                                                
                                                                            }
                                                                            else{
                                                                                val=0;
                                                                            }
                                                                            
                                                                        }
                                                                        //printf("\n%d",val);
                                                                        if(val==l1)
                                                                        {
                                                                            printf("%d\t%s\t%s\t%s",tmp->b_id,tmp->b_name,tmp->b_author,tmp->b_publication);
                                                                            break;
                                                                        }
                                                                    }
                                                                    
                                                                    tmp=tmp->next;
                                                                }
                                                            }
                                                            else
                                                            {
                                                                if(c5==4)
                                                                {
                                                                    break;
                                                                }
                                                                else
                                                                {
                                                                    printf("\nWrong Choice !!\n");
                                                                    continue;
                                                                }

                                                            }
                                                        }
                                                    }
                                                }

                                            }
                                            else
                                            {
                                                if(c4==2)
                                                {
                                                    printf("\nIssued Book Details :\n");
                                                    printf("\nBook Id\t\t\t Name\t\t\t\tAuthor\t\t   Publication \n\n");
                                                    
                                                    SB_printList(sbhead);

                                                }
                                                else
                                                {
                                                    if(c4==3)
                                                    {
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        printf("\nWrong Choice !!\n");
                                                        continue;   

                                                    }

                                                }
                                            }
                                            
                                        }
                                    }
                                }
                                tmp=tmp->next;
                            }
                            
                        }
                        else
                        {
                            if(c2==3)
                            {
                                break;
                            }
                            else
                            {
                                printf("\nWrong Choice !!\n");
                                continue;
                            }
                        }

                    }
                    
                }

            }
            else
            {
                if(choice==3)
                {
                    break;

                }
                else{
                    printf("\nWrong Choice !!\n");
                    continue;
                    
                }
            }
        }

    }

}