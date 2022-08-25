//*************************************
//This code converts a decimal number to the equivalent value with a new radix defined by the User. 
//Code written by Oscar Liss for EEE2046S Practical 2. 
//*************************************

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void Dec2RadixI(int decValue, int radValue) //Void output with two input integer inputs 
{
    printf("Your radix-%d number: ", radValue);     //Print for user to know the radix of the output
    double logVal = log(decValue)/log(radValue);    //Calculate and initialize logVal. The log of the decimal with radix as the base
    int logVal_floor = floor(logVal);   //Calculate and initialize logVal_floor. The floor of the logVal
    if(decValue==0){printf("%c", 48);}  //When decValue is equal to 0 the if condition allows function to bypass the rest of the Dec2RadixI and straight ptints the char 0
    else //In all other cases carry on with Dec2RadixI
    {
        for(int i=0; i<=logVal_floor; i++) //Creates a for loop with i starting at 0 until i<= logVal_floor:
        {
            int unit = pow(radValue, logVal_floor-i);   //Calculate and initialize unit. The radix to the power of (logVal_floor – i)
            int num_unit = floor(decValue/unit);    //Calculate and initialize num_unit. The floor of the decimal divided by unit
            if(num_unit>9)  //If num_unit is greater than 9
            {
                printf("%c", num_unit+55); //Print the relative ASCII char associated (A,B,C,D,E,F)
            }
            else //All other cases 
            {
                printf("%c", num_unit+48);  //Print the relative ASCII char associated (1,2,3,4,5,6,7,8,9)
            }
            decValue -= (num_unit*unit); //Calculate the new decimal value minus num_unit*unit
        }
    }
    printf("\n");
}

int main () //Integer output with no input 
{
    //Define the three different personal variables for the the title card 
    #define TITLE "DECIMAL TO RADIX-i converter"
    #define NAME "Oscar Liss"
    #define YEAR "2022"
    int dec = 0, radix; //Initialize the decimal and radix as integers 

    printf("*****************************\n%s\nWritten by: %s\nDate: %s\n*****************************\n", TITLE, NAME, YEAR);  //Print out the title card

    while(dec>=0) //While loop that only exits once the user has input a negative number 
    {
        printf("Enter a decimal number: ");
        scanf("%d", &dec);  //Scan in the decimal number from the user 

        if(dec<0) //Condition to bypass the Dec2RadixI function when a negative number is retrieved 
        {
            printf("EXIT\n"); //Prints EXIT to inform the user 
        }
        else    //If the entered decimal is greater than or equal to zero than carry on 
        {
            printf("The decimal number you have entered is %d\n", dec); //Print decimal to the terminal to inform the user of the number they entered
            printf("Enter a radix for the converter between 2 and 16: ");   //Scan in the radix number from the user
            scanf("%d", &radix);
            if(radix<2 | radix>16){printf("Not a vaild radix... Try again!\n"); continue;} //If radix is out of bounds then will go back to start of while loop
            printf("The radix you have entered is %d\n", radix);    //Print radix to the terminal to inform the user of the number they entered
            double log_2;   //Calculate, initialize and print log base 2 of decimal number
            log_2 = log2(dec);
            printf("The log2 of the number is %.2f\n", log_2);
            printf("The integer result of the number divided by %d is %d\n", radix, (dec/radix)); //Calculate and print the integer result of decimal divided by radix
            printf("The remainder is %d\n", (dec%radix));   //Calculate and print the remainder
            Dec2RadixI(dec, radix); //Call Dec2RadI
            // on final iteration decimal value will equal zero and the code will loop back to the start of the while loop
        }
    }

    return 0; //Means that main has successfully finished 
}