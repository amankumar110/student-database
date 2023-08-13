#include<stdio.h>
struct student
{
int rollNum,age,standard;
char name[50];
};
struct student students[100];
int counts=0;

//Showing Students
showStudents()
{
    if(counts==0)
        printf("No Student To Show");
    else {
            int i;
        for(i=0;i<counts;i++)
        {
            printf("\nName:%s - Class:%dth - Roll Number:%d - age:%d",students[i].name,students[i].standard,students[i].rollNum,students[i].age);

        }
    }
}

int findIndexOf(roll)
{
    int i;
    for(i=0;i<counts;i++)
    {
        if(students[i].rollNum==roll)
        {
            return (i);
            break;
        }
    }
}

//Deleting Students
deleteStudents()
{
    int rollNum;
    printf("Enter Roll Number For Deletion\n");
    scanf("%d",&rollNum);
    int index = findIndexOf(rollNum),i;
    for(i=index;i<=counts;i++)
    {
        students[i]=students[i+1];
    }
    printf("\nDeleted Successfully");
    counts--;
}
//Adding Students
addStudents()
{
    struct student s;
    s.rollNum = counts+1;
    printf("Enter The Name Of Student\n");
    fflush(stdin);
    gets(s.name);

    printf("Enter Your Class\n");
    scanf("%d",&s.standard);
    printf("Enter The Age\n");
    scanf("%d",&s.age);
    students[counts] = s;
    counts++;
    printf("Student Added Successfully");


}

// Updating Student's Name
void updateName(rollNum)
{
int i;
for(i=0;i<counts;i++)
 {
   if(students[i].rollNum == rollNum)
   {
       fflush(stdin);
       printf("enter student's new name\n");
       gets(students[i].name);
       printf("%d Name Updated");
       break;
   }
 }
 if(i==counts)
 printf("\nNo Student found");
}

void updateClass(rollNum)
{
int i;
for(i=0;i<counts;i++)
 {
   if(students[i].rollNum == rollNum)
   {
       fflush(stdin);
       printf("enter student's new class\n");
       gets(students[i].standard);
       printf("Class Updated");
       break;
   }
 }
 if(i==counts)
 printf("\nNo Student found");
}

void updateAge(rollNum)
{
int i;
for(i=0;i<counts;i++)
 {
   if(students[i].rollNum == rollNum)
   {
       fflush(stdin);
       printf("enter student's new age\n");
       gets(students[i].age);
       printf("\n Age Updated");
       break;
   }
 }
 if(i==counts)
 printf("\nNo Student found");
}


// Updating student
updateStudent()
{
    printf("Enter your roll number\n");
    int rollNum;
    scanf("%d",&rollNum);
    printf("\nWhat you want to update?");
    printf("\n1 for name \n2 for class \n3 for age ");
    int ans;
    scanf("\n%d",&ans);
    switch(ans){
     case 1 : updateName(rollNum);break;
     case 2 : updateClass(rollNum);break;
     case 3 : updateAge(rollNum);break;
    }
}

// Main Function
main()
{
 printf("Welcome To The Student Database");
    while(1)
    {

    printf("\nWhat Operation You Want To Perform?\n");
    printf("Enter 1 for adding students. \nEnter 2 for viewing students. \nEnter 3 for Updating Student Info. \nEnter 4 to delete.\n");
        printf("\nEnter Command : ");
        int ans;
        scanf("\n%d",&ans);
       if(ans==1)
        addStudents();
       else if(ans==2)
        showStudents();
       else if(ans==3)
        updateStudent();
        else if(ans==4)
            deleteStudents();
    }
}
