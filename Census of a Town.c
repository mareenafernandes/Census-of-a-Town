/*CODE AND OUTPUT*/
#include <stdio.h>
#include<stdlib.h>
struct node
{
  char name[50];
  char dob[10];
  char gender[5]; 
  float salary;
  int ID; 
  char disable[5];
  int mark;
  struct node *next;
  struct node *prev;  
};
struct node *start = NULL;
struct node *add (struct node *start);
void display(struct node *start);
struct node *del(struct node *start);
void display_fm(struct node *start);
void display_id(struct node *start); 
void total(struct node *start);
void dis_el(struct node *start);
void list_sal(struct node *start);
int count1=100;                                  //female
int count2=200;                                  //male
void main ()
{
    int opt;
    
    printf("================MENU==============\n");
    printf("1)Add details of a person to the list\n");              
    printf("2)Display the list of all people\n");                    
    printf("3)Delete details of a person from the list\n");         
    printf("4)Display a list of male and female\n");                
    printf("5)To find details of a person with their id number\n");     
    printf("6)To find the total number of people present in a town\n");
    printf("7)To find the list of people above a paticular salary amount\n");
    printf("8)Exit\n");
    printf("========================================\n\n");
    printf("Enter your choice: ");
    scanf("%d",&opt);
    do
    {
       switch(opt)
       {
        case 1: printf ("=============ENROLLMENT FORM==============\n");
        	printf("          (NOTE:ENTER VALID DETAILS)          \n");
        	start = add (start);
        	printf("***********************************************\n");
       		break;
        case 2: display(start);
        	break;
        case 3: start=del(start);
       		break;
        case 4: display_fm(start);
        	break;
        case 5: display_id(start);
        	break;
        case 6: total(start);
        	break;
        case 7: list_sal(start);
                break;
        case 8: printf("\n EXIT !!!\n");
                break;
	default:printf("Invalid Input!!");
       }
        printf("Enter your choice: ");
	scanf("%d",&opt);
    }while(opt!=8);
}


struct node *add(struct node *start)
{
    struct node *new_node,*ptr,*temp;
    int gen,dis;
    float sa;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("NAME:");
    scanf("%s",new_node->name);
    printf("(Enter M:Male F:Female)\n");
    printf("GENDER:");
    scanf("%s",new_node->gender);
    
    
    if(new_node->gender[0]=='F'||new_node->gender[0]=='f')         
    {
        count1++;
        new_node->ID=count1;
    }
    else
    {
        count2++;
        new_node->ID=count2;
    }
    printf("MONTHLY INCOME:");
    scanf("%f",&sa);
    new_node->salary=sa;
    
    if(start==NULL)
    {
        new_node->prev=NULL;
        new_node->next=NULL;
        start=new_node;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
        new_node->prev=ptr;
        new_node->next=NULL;
    }
    
    return start;
}


void display(struct node *start)
{
   
    struct node *ptr;
    
    if(start==NULL)
    {
        printf("No entries present\n");
    }
    else
    {
        
        printf("===============LIST OF PEOPLE=================\n");
        ptr=start;
        
        while(ptr!=NULL)
        {  
            printf("ID:%d\t",ptr->ID);
            printf("NAME:%s\t",ptr->name);
            printf("GENDER:%s\t",ptr->gender);
            printf("MONTHLY INCOME:%f\t",ptr->salary);
            printf("\n");
            ptr=ptr->next;
        }
      
        printf("\n");
        
    }
}

struct node *del(struct node *start)
{
    /*
        when only one person is present *
        when list is empty *
        when you have to delete the first person *
        when you have to delete the last person  *
        when delete it the middle  *
        id not found *
    */
    
    int id;
    struct node *ptr,*temp1,*temp2;
    
    
    if(start==NULL)
    {
        printf("No entries present\n");
    }
    
    else
    {
        printf("Enter the id no that you want to delete from the list:");
        scanf("%d",&id);
        if(start->next==NULL &&start->ID==id)
        {
            ptr=start;
            free(ptr);
            start=NULL;
            
        }
        else if(start->ID==id)
        {
            ptr=start;
            start=start->next;
            free(ptr);
            
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL && ptr->ID!=id)
            {
                ptr=ptr->next;
            }
            if(ptr->next==NULL && ptr->ID==id)
            {
                temp1=ptr->prev;   
                temp1->next=NULL;
                free(ptr);
            }
            else if(ptr->next==NULL && ptr->ID!=id)
            {
                printf("INVALID ID\n");
            }
            else
            {
                temp1=ptr->prev;
                temp1->next=ptr->next;
                temp2=ptr->next;
                temp2->prev=temp1;
            }
        }    
        
    }
    return start;
}


void display_fm(struct node *start)
{
    int in;
    struct node *ptr;
    if(start==NULL)
    {
        printf("No entries present\n");
    }
    else
    {
        printf("Enter any one option:\n1:List of female\n2:List of male\n");
        scanf("%d",&in);
        ptr=start;
        
        if(in==2)
        {
            printf("==============LIST OF MEN=============\n");
        while(ptr!=NULL)
        {
            
            if(ptr->ID>200)
            {
                printf("ID:%d\t",ptr->ID);
                printf("NAME:%s  \t",ptr->name);
                printf("\n\n");
                ptr=ptr->next;
            }
            else
            {
                ptr=ptr->next;
            }
        }
        printf("***********************************************\n");
        }
        else
        {
            printf("==============LIST OF WOMEN=============\n");
            while(ptr!=NULL)
        {
            
            if(ptr->ID>100 &&ptr->ID<200)
            {
                printf("ID:%d\t",ptr->ID);
                printf("NAME:%s  \t",ptr->name);
                printf("\n\n");
                ptr=ptr->next;
            }
            else
            {
                ptr=ptr->next;
            }
        }
        printf("***********************************************\n");

        }
    }
}

void display_id(struct node *start)
{
    
   /* if no entries are filled in
    if entires are present but id is wrong 
    if id is found display the details */
    
    int id;
    struct node *ptr;
    printf("Enter ID no:");
    scanf("%d",&id);
    
    
    if(start==NULL)
    {
        printf("No entries present\n");
    }
    else
    {
        ptr=start;   
        while(ptr->next!=NULL && ptr->ID!=id)
        {
            ptr=ptr->next;
        }
        if(ptr->ID ==id &&ptr->next==NULL)                //if it is the last node
        {
            printf("              PERSONAL  INFORMATION            \n ");
            
            printf("NAME:%s\n",ptr->name);
            printf("GENDER:%s\n",ptr->gender);
            printf("MONTHLY INCOME:%f\n",ptr->salary);
            
        }
        else if (ptr->ID !=id &&ptr->next==NULL)
        {
            printf("INVALID ID\n");
        }
        else
        {
            printf("              PERSONAL  INFORMATION            \n ");
            
            printf("NAME:%s\n",ptr->name);
            printf("GENDER:%s\n",ptr->gender);
            printf("MONTHLY INCOME:%f\n",ptr->salary);
            
        }
        
    }
    
}


void total(struct node *start)
{
    struct node *ptr;
    int count=0;
    if(start==NULL)
    {
        printf("No entries present\n");
    }
    else
    {
        ptr=start;
        while(ptr!=NULL)
        {
            count ++;
            ptr=ptr->next;
        }
    }
    printf("Total no of people present :%d\n",count);
}

void list_sal(struct node *start)
{
    int amt;
    struct node *ptr;
    if(start==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Enter the amount :");            //amt above which list of people need to be displayed
        scanf("%d",&amt);
        ptr=start;
        
            while(ptr!=NULL)
            {
            
                if(ptr->salary>amt)
            {
                printf("ID:%d\t",ptr->ID);
                printf("NAME:%s  \t",ptr->name);
                printf("MONTHLY SALARY:%f\t",ptr->salary);
                printf("\n\n");
                ptr=ptr->next;
            }
            else
            {
                ptr=ptr->next;
            }
        }
    }
}


/*
OUTPUT
================MENU==============
1)Add details of a person to the list
2)Display the list of all people
3)Delete details of a person from the list
4)Display a list of male and female
5)To find details of a person with their id number
6)To find the total number of people present in a town
7)To find the list of people above a paticular salary amount
8)Exit
========================================

Enter your choice: 1
=============ENROLLMENT FORM==============
          (NOTE:ENTER VALID DETAILS)          
NAME:Mareena
(Enter M:Male F:Female)
GENDER:F
MONTHLY INCOME:18000
***********************************************
Enter your choice: 1
=============ENROLLMENT FORM==============
          (NOTE:ENTER VALID DETAILS)          
NAME:Anu
(Enter M:Male F:Female)
GENDER:F
MONTHLY INCOME:10000
***********************************************
Enter your choice: 1
=============ENROLLMENT FORM==============
          (NOTE:ENTER VALID DETAILS)          
NAME:Aaron
(Enter M:Male F:Female)
GENDER:M
MONTHLY INCOME:15000
***********************************************
Enter your choice: 1
=============ENROLLMENT FORM==============
          (NOTE:ENTER VALID DETAILS)          
NAME:Manuel
(Enter M:Male F:Female)
GENDER:M
MONTHLY INCOME:10000
***********************************************
Enter your choice: 1
=============ENROLLMENT FORM==============
          (NOTE:ENTER VALID DETAILS)          
NAME:Steve
(Enter M:Male F:Female)
GENDER:M
MONTHLY INCOME:15000
***********************************************
Enter your choice: 1
=============ENROLLMENT FORM==============
          (NOTE:ENTER VALID DETAILS)          
NAME:Sarah
(Enter M:Male F:Female)
GENDER:F
MONTHLY INCOME:20000
***********************************************
Enter your choice: 2
===============LIST OF PEOPLE=================
ID:101	NAME:Mareena	GENDER:F	MONTHLY INCOME:18000.000000	
ID:102	NAME:Anu	GENDER:F	MONTHLY INCOME:10000.000000	
ID:201	NAME:Aaron	GENDER:M	MONTHLY INCOME:15000.000000	
ID:202	NAME:Manuel	GENDER:M	MONTHLY INCOME:10000.000000	
ID:203	NAME:Steve	GENDER:M	MONTHLY INCOME:15000.000000	
ID:103	NAME:Sarah	GENDER:F	MONTHLY INCOME:20000.000000	

Enter your choice: 3
Enter the id no that you want to delete from the list:203
Enter your choice: 4
Enter any one option:
1:List of female
2:List of male
1
==============LIST OF WOMEN=============
ID:101	NAME:Mareena  	

ID:102	NAME:Anu  	

ID:103	NAME:Sarah  	

***********************************************
Enter your choice: 4
Enter any one option:
1:List of female
2:List of male
2
==============LIST OF MEN=============
ID:201	NAME:Aaron  	

ID:202	NAME:Manuel  	

***********************************************
Enter your choice: 5
Enter ID no:101
              PERSONAL  INFORMATION            
 NAME:Mareena
GENDER:F
MONTHLY INCOME:18000.000000
Enter your choice: 6
Total no of people present :5
Enter your choice: 7
Enter the amount :15000
ID:101	NAME:Mareena  	MONTHLY SALARY:18000.000000	

ID:103	NAME:Sarah  	MONTHLY SALARY:20000.000000	

Enter your choice: 8
8669@acer06:~/Desktop/DSA$ 
*/
