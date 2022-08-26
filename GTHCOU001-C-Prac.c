#include <stdio.h>
#include <string.h>
#include <math.h>

//setting up name and title constants for program
#define Name "Courtney Gathecha" 
#define Year 2022
#define Title "DECIMAL TO RADIX-i converter"


void Dec2RadixI(int decValue, int radValue){

    float logb2= log2(decValue); //makes variable to store log to base 2

    printf("The log2 of the number is %.2f\n",logb2); //prints log results to 2dp

    int div= decValue/radValue; //division giving integer result

    printf("The integer result of the number divided by %d is %d\n",radValue, div); //printing division integer result
      
    int mod= decValue%radValue; //using modulo to find remainder

    printf("The remainder is %d\n",mod);//prints the remainder as an integer
       
   
    char s[1000]; // making an empty string for storage
   
    int j=0;

    while(decValue>0){
        int modl=decValue%radValue; //declaring modulo variable within loop
        char insert; //insert character
        
        if(modl<10){ // conversion by division below 10
          insert='0'+modl;
        }
        else{
            insert='A'+modl-10; //assigning letters if above 9
        }
        
        s[j]=insert; //stores in array
        j++;
        decValue=decValue/radValue; //finds next value after minusing radix
    }

    printf("The radix-%d value is: ",radValue); 
   
    for(int k=j;k>=0;k--){ //reversing string
        printf("%c",s[k]); //prints the reversed string
    }
    printf("\n");
   } 

int main (void)
{
    int symbol, TL;
    
    TL = strlen( Title); //finding the length of the title

    for(symbol=1; symbol<=TL;symbol++){ //for loop printing stars the length of the title
        printf("*");
    }

    printf("\n%s\nWritten by: %s\nYear: %d\n",Title,Name,Year); //calling constants and printing them

    for(symbol=1; symbol<=TL;symbol++){ //second for loop printing stars the length of the title
        printf("*");
    
    }
    
    printf("\n");

    int decValue, radValue;

    while(decValue>=0){
         //repeatedly asks for a user input until a condition to stop is met
        printf("Enter a decimal number: ");
        scanf("%d", &decValue);

        if(decValue<0){ //breaks out of while loop if decimal input is negative
          break;
         }

        else{ //asks for radix input given decimal input is non-negative
           printf("The decimal number you have entered is %d\n", decValue);
           printf("Enter a radix for the converter between 2 and 16: ");
           scanf("%d", &radValue);
           printf("The radix you have entered is %d\n", radValue);

           Dec2RadixI(decValue, radValue); //calling the radix function 
      
        }
    }
    printf("EXIT"); //prints EXIT when the while loop is exited

    return 0;

} 