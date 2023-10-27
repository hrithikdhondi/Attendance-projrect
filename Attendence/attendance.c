#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int num_of_absentees1,num_of_absentees2,copy_num_of_absentees,roll_no,option,absentees1[60],absentees2[60],absentees_copy[60],count=0;
    printf("*******Program To Get The List Of Abseentees Or Presentees*******\n");
    printf("1.Abseentees Details\n2.Presentees Details\nEnter your required option(1/2):");
    scanf("%d",&option);
    printf("Enter the no.of absentees(F/N): ");
    scanf("%d",&num_of_absentees1);
    absentees1[num_of_absentees1];
    printf("Enter the Roll.Nos: ");
    for(int i=0; i<num_of_absentees1; i++){
        scanf("%d",&absentees1[i]);
    }
    printf("Enter the no.of absentees(A/N): ");
    scanf("%d",&num_of_absentees2);
    absentees2[num_of_absentees2];
    printf("Enter the Roll.Nos: ");
    for(int i=0; i<num_of_absentees2; i++){
        scanf("%d",&absentees2[i]);
    }
    
    for(int i=0; i<2; i++){
        if(i==0){
        copy_num_of_absentees=num_of_absentees1;
        for(int j=0; j<num_of_absentees1; j++){
            absentees_copy[j] = absentees1[j];
        }
        }
        else{
        copy_num_of_absentees=num_of_absentees2;
        for(int j=0; j<num_of_absentees2; j++){
            absentees_copy[j] = absentees2[j];
        }
        }
        FILE *fptr;
        fptr = fopen("Attendence.csv","r");
        if(fptr==NULL){
            printf("The File Doesn't Exist");
            exit(0);
        }
        char line[200],*token;
        if(option==1){
            if(i==0){
                printf("Absentees:\n");
                printf("Morning:-\n");
            }else{
                printf("Afternoon:-\n");
            }
            while(fgets(line,200,fptr) != NULL){
                token = strtok(line,",");
                roll_no = atoi(token);
                token = strtok(NULL,",");
                for(int j=0; j<copy_num_of_absentees; j++){
                    if(roll_no == absentees_copy[j]){
                        while(token!=NULL){
                            printf("%s",token);
                            token = strtok(NULL,",");
                        }
                        break;   
                    }  
                }
            }
        }
        else if(option==2){
            if(i==0){
                printf("Absentees:\n");
                printf("Morning:-\n");
            }else{
                printf("Afternoon:-\n");
            }
            while(fgets(line,200,fptr) != NULL){
                count=0;
                token = strtok(line,",");
                roll_no = atoi(token);
                token = strtok(NULL,",");
                for(int j=0; j<copy_num_of_absentees; j++){
                    if(roll_no == absentees_copy[j]){
                        count=1;
                        break;
                    }
                }
                if(count==0){
                    while(token!=NULL){
                        printf("%s",token);
                        token = strtok(NULL,",");
                    }   
                }   
            }
        }
        else{
            printf("INVALID CHOICE");
        }
        fclose(fptr);
    }
    return 0;
}
