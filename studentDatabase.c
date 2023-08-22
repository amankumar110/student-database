#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int random(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

struct student
{
int rollNum,age,standard;
char name[50];
};
char filename[] = "myfile.txt";
//Showing Students
void showStudents()
{
    FILE *fp = fopen(filename,"rb");
    if(fp == NULL) {
        printf("No Student To Show");
    } else {
        struct student s;
        int count = 0;
        while(fread(&s,sizeof(s),1,fp) == 1) {
            printf("\nName:%s - Class:%dth - Roll Number:%d - age:%d",s.name,s.standard,s.rollNum,s.age);
            count++;
        }
        if(count == 0) {
            printf("No Student To Show");
        }
        fclose(fp);
    }
}

showByRollNumber()
{
    FILE *fp = fopen(filename,"rb");
    printf("\nEnter your roll number\n");
    int i,rollNum;
    scanf("%d",&rollNum);
    struct student s;
        int count = 0;
        while(fread(&s,sizeof(s),1,fp) == 1) {
                if(s.rollNum==rollNum)
                {
                  printf("\nName:%s - Class:%dth - Roll Number:%d - age:%d",s.name,s.standard,s.rollNum,s.age);
                  count++;
                }

        }
        if( count == 0) {
            printf("No Student To Show");
        }
        fclose(fp);
}


showByName()
{
    FILE *fp = fopen(filename,"rb");
    printf("\nEnter your Exact Name\n");
    int i;
    char name[50];
    fflush(stdin);
    gets(name);
    struct student s;
    int count = 0;
    while(fread(&s,sizeof(s),1,fp) == 1) {
            if(strcmp(s.name,name)==0)
            {
            printf("\nName:%s - Class:%dth - Roll Number:%d - age:%d",s.name,s.standard,s.rollNum,s.age);
            count++;
            }
        }
        if(count == 0) {
            printf("No Student To Show");
        }
        fclose(fp);
}

int findIndex(struct student *array, int size, int target) {
    int i=0;
    while((i<size) && ((*(array+i)).rollNum != target)) i++;
    return (i<size) ? (i) : (-1);
}

//Deleting Students
deleteStudents(rollNum)
{
    FILE *fp = fopen(filename,"rb");
    int i,j,k;
    struct student students[100];
   for(i=0;!feof(fp);i++)
    {
        fread(&students[i],sizeof(students[i]),1,fp);
    }

    int index = findIndex(&students,100,rollNum);
    if(index!=-1)
    {
    for(j=index;j<=i;j++)
        students[j]=students[j+1];
    fclose(fp);
    fp =fopen(filename,"wb");
    for(k=0;k<i-2;k++)
        fwrite(&students[k],sizeof(struct student),1,fp);
    fclose(fp);
    return (1);
    } else
    {
        printf("delete failed");
        return (0);
    }

}
//Adding Students
addStudents()
{
    FILE *fp = fopen(filename,"ab");
    struct student s;
    s.rollNum = random(0,500);
    printf("Enter The Name Of Student\n");
    fflush(stdin);
    gets(s.name);
    printf("Enter Your Class\n");
    scanf("%d",&s.standard);
    printf("Enter The Age\n");
    scanf("%d",&s.age);
    fwrite(&s,sizeof(s),1,fp);
    printf("Student Added Successfully");
    fclose(fp);
}

void updateName()
{
    FILE *fp = fopen(filename,"ab+");
    struct student s;
    printf("enter roll number: ");
    scanf("%d",&s.rollNum);
    printf("Enter The New Name Of Student\n");
    fflush(stdin);
    gets(s.name);
    printf("Enter Your New Class\n");
    scanf("%d",&s.standard);
    printf("Enter The New Age\n");
    scanf("%d",&s.age);
    int status = deleteStudents(s.rollNum);
    if(status==1)
    {
        printf("\nupdated successfully");
    } else { printf("\nupdate failed");}
    fwrite(&s,sizeof(s),1,fp);
    fclose(fp);
}


// Main Function
main()
{
 printf("Welcome To The Student Database");
    while(1)
    {

    printf("\nWhat Operation You Want To Perform?\n");
    printf("Enter 1 for adding students. \nEnter 2 for viewing students.");
    printf("\nEnter 3 for Updating Student Info. \nEnter 4 to delete. ");
    printf("\nEnter 5 for Show by roll number. \nEnter 6 to search by name \nEnter 7 to exit. \n");
    printf("\nEnter Command : ");
        int ans;
        scanf("\n%d",&ans);
       if(ans==1)
        addStudents();
       else if(ans==2)
        showStudents();
       else if(ans==3)
        updateName();
        else if(ans==4)
        {
            int rollNum;
            printf("Enter roll number for deletion : ");
            scanf("%d",&rollNum);
            int status = deleteStudents(rollNum);
            if(status==1)
                printf("\ndeleted successfully");
            else
                printf("\ndelete failed");
        }

        else if(ans==5)
            showByRollNumber();
        else if(ans==6)
            showByName();
        else if(ans==7)
            exit(0);
    }

}
