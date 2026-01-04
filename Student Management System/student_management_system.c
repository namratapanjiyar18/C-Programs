#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
    int roll;
    char name [50];
    float marks;
    float percentage;
    char grade;
};
char calculateGrade(float p){
    if (p >= 90)
    return 'A';
    else if (p >= 75)
    return 'B';
    else if (p >= 50)
    return 'C';
    else
    return 'F';
}int rollExists(int roll){
    FILE*fp;
    struct student s;
    fp = fopen("students.txt","r");
    if (fp == NULL)
    return 0;
    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.roll == roll){
        fclose(fp);
        return 1;
    }
}fclose(fp);
return 0;
}void addStudent(){
    FILE*fp;
    struct student s;
    printf("\n Enter roll number:");
    scanf("%d", &s.roll);
    if (rollExists(s.roll)){
        printf("\nRoll already exists! Try another.\n");
        return;
    }printf("Enter name:");
    scanf(" %[^\n]", s.name);
    printf("Enter Marks:");
    scanf("%f", &s.marks);
    s.percentage = s.marks;
    s.grade = calculateGrade(s.percentage);
    fp = fopen("students.txt","a");
    fwrite(&s,sizeof(s),1,fp);
    fclose(fp);
    printf("\nStudent added successfully!\n");
}void viewStudents(){
    FILE*fp;
    struct student s;
    fp=fopen("students.txt","r");
    if(fp==NULL){
        printf("\nNo data found!\n");
        return;
    }printf("\nSTUDENT LIST\n");
     while(fread(&s, sizeof(s), 1, fp)){
        printf("\nRoll:%d",s.roll);
        printf("\nName: %s", s.name);
        printf("\nMarks: %.2f", s.marks);
        printf("\nPercentage: %.2f", s.percentage);
        printf("\nGrade: %c\n", s.grade);
     }fclose(fp);
}void searchStudent(){
    FILE *fp;
    struct student s;
    int roll, found=0;
    printf("\nEnter roll number to search:");
    scanf("%d", &roll);
    fp = fopen("students.txt","r");
    while (fread(&s, sizeof(s), 1, fp)){
        if(s.roll == roll){
            printf("\nStudent Found!");
            printf("\nName: %s", s.name);
            printf("\nMarks: %.2f", s.marks);
            printf("\nPercentage: %.2f", s.percentage);
            printf("\nGrade: %c\n", s.grade);
            found = 1;
            break;
        }
    }if(!found)
    printf("\nStudent not found!\n");
    fclose(fp);
}void updateStudent(){
    FILE*fp, *temp;
    struct student s;
    int roll, found=0;
    fp=fopen("students.txt","r");
    temp=fopen("temp.txt","w");
    printf("\nEnter Roll Number to update:");
    scanf("%d", &roll);
     while (fread(&s, sizeof(s), 1, fp)){
        if(s.roll == roll){
            printf("Enter New Name:");
            scanf(" %[^\n]", s.name);
            printf("Enter New Marks: ");
            scanf("%f", &s.marks);
            s.percentage = s.marks;
            s.grade = calculateGrade(s.percentage);
            found = 1;
        }fwrite(&s, sizeof(s),1,temp);
     }fclose(fp);
     fclose(temp);
     remove("students.txt");
     rename("temp.txt","students.txt");
     if(found)
     printf("\nStudent updated successfully!\n");
     else
     printf("\nStudent not found!\n");
}void deleteStudent(){
    FILE *fp, *temp;
    struct student s;
    int roll, found=0;
    fp= fopen("students.txt","r");
    temp= fopen("temp.txt","w");
    printf("\nEnter Roll Number to delete:");
    scanf("%d",&roll);
    while (fread(&s, sizeof(s), 1, fp)){
        if(s.roll != roll)
        fwrite(&s,sizeof(s),1,temp);
        else
        found=1;
    }fclose(fp);
    fclose(temp);
    remove("students.txt");
    rename("temp.txt","students.txt");
    if(found)
    printf("\nStudent deleted successfully!\n");
    else
    printf("\nStudent not found!\n");
}int main(){
    int choice;
    do{
        printf("\nSTUDENT MANAGEMENT SYSTEM\n");
        printf("\n1. Add Student");
        printf("\n2. View Students");
        printf("\n3. Search Student");
        printf("\n4. Update Student");
        printf("\n5. Delete Student");
        printf("\n6. Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice){
    case 1: addStudent(); break;
    case 2: viewStudents(); break;
    case 3: searchStudent(); break;
    case 4: updateStudent(); break;
    case 5: deleteStudent(); break;
    case 6: exit(0);
    default: printf("\nInvalid choice!");
}

        }while(choice !=6);
        return 0;
    }
