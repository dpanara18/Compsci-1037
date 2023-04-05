/* CS1037a 2022  */
/* Assignment 01 */
/* Dev Panara    */
/* 251208360     */
/* dpanara       */
/* 29/09/2022    */

#include <stdio.h>
#define printf __mingw_printf

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*                                          Project 1                                                        */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Printing the header of the code
    printf("Fibonacci Sequence : Until Overflow\n");
    printf("-------------------------------------------------\n");

    //Defining counter and first 2 values for fib as int, long and long long
    //Settled for long long as required by the question
    long long firstNum = 2, fib, fib1 = 0, fib2 = 1;
    /*There is no difference between using int and long type variable
    and this is because both int and long store values in 4 bytes and have the same range although long long stores
    values in 8 bytes which is double that of int and long, it also has double the range of int and that is why int
    and long only print 47 values of the fib series while long long does double that due to the double storage capacity
    and range.*/

    //Printing the first 2 values of the fib series
    printf("0:0\n");
    printf("1:1\n");

    //Do while statement to make the fib series work and print and exit running once the fib series becomes negative
    do{
        //Calculations for the fib series
        fib = fib1 + fib2;  //Next number in the series that prints
        fib1 = fib2;        //Reassigning the first number to the second
        fib2 = fib;         //Reassigning the second number as the new number calculated

        //Printing the nth term and the fib series and incrementing the count
        printf("%lld:%lld\n", firstNum, fib);
        firstNum++;
    }

    //The condition in the while ensures the program stops looping when the next number in the fib series is negative
    while((fib1 + fib2) >= 0);
    printf("\n\n-------------------------------------------------\n\n");

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*                                          Project 2                                                        */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

        int rows;
    printf("Enter an odd number of rows in your diamond: ");
    scanf("%d", &rows); //Getting user input to define the int "rows" to the number of rows they want their diamond to be

    //Condition in the if statement to see if the user input for rows is an even number
    if (rows%2 == 0){
        printf("%d is not an odd number. The program will produce %d rows instead:\n\n", rows, rows + 1);
        rows = rows + 1; //Redefining rows to be 1 number more than what the user entered if the condition of the if statement is met, i.e. an even number to make it odd
    }

    int count = 1;
    int space = (rows + 1)/2; //These are the number of spaces I want in the first row

    printf("-------------------------------------------------\n");

    /*          Printing the top half of the diamond to middle row          */
    //////////////////////////////////////////////////////////////////////////

    //First while statement that loops "(rows+1)/2" amount of times
    while(count <= rows){
            //Integers that I want to reset at the start of each loop
            int num = 1;
            int stars = 1;

        //Second while loop to loop the amount of times I want the stars to print
        while(stars <= count){
                //Final while loop that loops the amount of times I want the spaces to print
                while(num <= space){
                    printf(" "); //Prints the spaces
                    num++;       //Increments num
                }//Loop ends when "num" is less than or equal to the int "space"
            printf("*"); //Prints a star
            stars++;     //Increments starts
        }//Loop ends when the int "stars" is less than or equal to the int "count"
        space--;           //Decrements "space" so that the next row will have one less space
        printf("\n");      //Goes to the next row
        count = count + 2; //"count" gets incremented twice "2 added to it" after each first loop runs
    }//Loop ends when "count" is less than or equal to "rows" or until it has looped "(rows+1)/2" times

    /*                  Printing one row below middle row to the last row                     */
    ////////////////////////////////////////////////////////////////////////////////////////////

    count = (rows-1)/2;    //Redefining count to be the number of rows remaining to print
    space = 2;             //Redefining space to be 2 as this is the number of spaces I need in the row below the middle one
    int count1 = 1;
    int count2 = rows - 2; //Integer for stars loop as this is the number of stars I need in the row below the middle one

    //First while loop to loop "(rows-1)/2" times
    while(count1 <= count){
            //Integers that I want to reset at the start of each loop
            int num = 1;
            int stars = 1;
        //Second while loop to loop the amount of times I want the stars to print
        while(stars <= count2){
                //Final while loop that loops the amount of times I want the spaces to print
                while(num <= space){
                    printf(" ");
                    num++;
                }//Loop ends when "num" is less than or equal to the int "space"
            printf("*");
            stars++;
        }//Loop ends when the int "stars" is less than or equal to the int "count2"
        space++;             //Incrementing "space" so that the next row will have one more space than the last
        printf("\n");        //Goes to the next row
        count1++;            //Incrementing count1 for first while loop
        count2 = count2 - 2; //Decrementing count2 twice or subtracting 2 each time to print 2 less stars each time
    }

    printf("-------------------------------------------------\n\n");


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*                                          Project 3                                                        */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("\nEnter a pair <product number followed by quantity sold> in a single line. Enter zero zero <0 0> to finish.\n\n");

    //Declaring variables for product number, quantity, price and total.
    int pNumber, quantity;
    double price, total;

    //Infinitely loops so user can enter as many items as necessary
    while(1){
        printf("Item #  Quantity: ");
        scanf("%d %d", &pNumber, &quantity); //User input for product number and quantity

        //Switch statement to define the product number to the defined price
        switch(pNumber){
        //If user enters 0 it will just break from the switch statement but needs to be a valid entry as <0 0> ends the loop
        case 0:
        break;

        case 1:
        price = 3.37;
        break;

        case 2:
        price = 4.23;
        break;

        case 3:
        price = 5.00;
        break;

        case 4:
        price = 7.99;
        break;

        case 5:
        price = 8.29;
        break;

        //If no correct product number is entered it will tell the user so and rerun the loop without adding to the total
        default:
        printf("\nIncorrect input. No item corresponds to the code of %d.\nPlease try again.\n\n", pNumber);
        continue;
    }
        //Breaks out of the loop if <0 0> is entered by the user
        if(pNumber == 0 && quantity == 0)
            break;

        //Ensures that if a product number of 0 is entered by the user with a quantity it doesn't add to the total
        if (pNumber != 0)
            total = total + price * quantity; //Calculates the total
    }

    //Prints total to 2 decimal places
    printf("\nThis is the final total: $%.2f\n", total);

    return 0;
}
