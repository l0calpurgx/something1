#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// If someone reads this IM SORRY (cluster f### to debug, f### ton of if, else if, else statements)

int main(){
    int age = 0;
    char name[50] = "";
    char study[50] = "";
    char work[50] = "";
    char schPaymentQu = '\0';
    float schPayment = 0.0f;
    char wrkPaymentQu = '\0';
    float wrkPayment = 0.0f;
    char currency = '$';
    char DoUstudy = '\0';
    char DoUwork = '\0';

    printf("To start this survey, enter your age: ");
    scanf(" %d", &age);
    if(age > 16){
        getchar();
        printf("You can take this survey now!\n");
        printf("Enter your name: \n");
        fgets(name, sizeof(name), stdin);
        name[strlen(name) -1] = '\0';

        while(strlen(name) == 0){
            printf("Name cannot be empty, please write your name!: ");
            fgets(name, sizeof(name), stdin);
            name[strlen(name) -1] = '\0';
        }

        // For teenagers
        if( age <= 18){
            printf("Do you study?(Y or N): ");
            scanf("%c", &DoUstudy);
            getchar();
            if(DoUstudy == 'Y' || DoUstudy == 'y'){
                printf("What do you study?: \n");
                fgets(study, sizeof(study), stdin);
                study[strlen(study) -1] = '\0';

                while(strlen(study) == 0){
                    printf("You need to write what you study!: ");
                    fgets(study, sizeof(study), stdin);
                    study[strlen(study) -1] = '\0';
                }

                printf("Do you get paid to study?(Y or N): \n");
                scanf("%c", &schPaymentQu);
                    if(schPaymentQu == 'Y' || schPaymentQu == 'y'){
                        printf("How much do you get paid to study?: \n");
                        scanf("%f", &schPayment);
                    }
                    else if(schPaymentQu == 'N' || schPaymentQu == 'n'){
                        printf("You dont get paid anything as a student");
                    }
                    else{
                        printf("Program Crash// Type Y or N");
                        return 1;
                    }
            }
            else if(DoUstudy == 'N' || DoUstudy == 'n'){
                printf("You dont study anything.");
            }
            else{
                printf("Program Crash// Type Y or N");
                return 1;
            }
            
            // final print if student
            printf("You are %d years old\n", age);
            printf("Your name is: %s\n", name);
            if(DoUstudy == 'Y'|| DoUstudy == 'y'){
                if(schPaymentQu == 'Y' || schPaymentQu == 'y'){
                printf("You study %s and get paid: %c%.2f as a student\n",study,  currency, schPayment);
                }
                else if(schPaymentQu == 'N' || schPaymentQu == 'n'){
                printf("You dont get paid for being a student\n");
                }
            }
            else{
                printf("You dont study, therefore you dont get anything");
            }

        }
        // For adults
        else if( age > 18){
            printf("Do you work?(Y or N): \n");
            scanf("%c", &DoUwork);
            getchar();
            if(DoUwork == 'Y' || DoUwork == 'y'){
                printf("What do you work?: \n");
                fgets(work, sizeof(work), stdin);
                work[strlen(work) -1] = '\0';

                printf("How much do you get paid?(Y to answer, N to not say): \n");
                scanf("%c", &wrkPaymentQu);
                if(wrkPaymentQu == 'Y' || wrkPaymentQu == 'y'){
                    printf("How much do you make?: \n");
                    scanf("%f", &wrkPayment);
                }
                else if(wrkPaymentQu == 'N' || wrkPaymentQu == 'n'){
                    printf("You want to hide your earnings.");
                }
                else{
                    printf("Program Crash// Type Y or N");
                }
            }
            else if(DoUwork == 'N' || DoUwork == 'n'){
                printf("You do not work.");
            }
            else{
                printf("Program Crash// Type Y or N");
                return 1;
            }

            // final print if adult
            printf("You are %d years old\n", age);
            printf("Your name is: %s\n", name);
            if(DoUwork == 'Y' || DoUwork == 'y'){
                if(wrkPaymentQu == 'Y' || wrkPaymentQu == 'y'){
                    printf("You work as an: %s and earn %c%.2f", work, currency, wrkPayment);
                }
                else if(wrkPaymentQu == 'N' || wrkPaymentQu == 'n'){
                    printf("You work as an: %s and decided to not say your earnings.", work);
                }
            }
            else if(DoUwork == 'N' || DoUwork == 'n'){
                printf("You work nothing, therefore you make nothing.");
            }
        }
        
    }
    else if(age < 16){
        printf("You are not old enought to take this survey.");
        return 1;
    }
    return 0;
}
