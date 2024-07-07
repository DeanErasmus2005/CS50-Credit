//#include <cs50.h>
#//include <stdio.h>
//#include <string.h>

//int main(void)
//{
  // long credit_num ;
   //string cardType;

   //credit_num = get_long("Number: ");
   //int length = 0;
   //long temp = credit_num;

   //if (temp == 0) {
    //length = 1;
   //}
   //else{
    //while (temp != 0) {
      //  temp /= 10;
        //    length++;
        //}
    //}

    //  if(length == 15) {
    //     American_Express = credit_num;
    //  } else if(length == 16 && credit_num >= 5100000000000000 && credit_num < 5500000000000000){
    //         MasterCard = credit_num;
    //  }else if((length == 13 && credit_num >= 4000000000000) || (length == 16 && credit_num >= 4000000000000000)){
    //         Visa = credit_num;
    //  }

     //if(length == 15) {
       // cardType = "AMEX\n" ;
     //} else if(length == 16 && credit_num >= 5100000000000000 && credit_num < 5500000000000000){
       //     cardType = "MasterCard\n" ;
     //}else if((length == 13 && credit_num >= 4000000000000) || (length == 16 && credit_num >= 4000000000000000)){
          //  cardType = "Visa\n" ;
       // else if ((length == 13 && credit_num >= 4000000000000 && credit_num < 5000000000000) ||
         //(length == 16 && credit_num >= 4000000000000000 && credit_num < 5000000000000000))


      //int sum = 0;
      //int sumodd = 0;
      //int sumeven = 0;

      //for(int i = length - 2 ; i >= 0 ; i -= 2)
          // {
           //  sumodd = sum + (credit_num * 2);
        //   }

     // for(int i  = length - 1; i >= 1 ; i -= 2)
          // {
             //sumeven = sum + credit_num;
         //

      //int Total = sumodd + sumeven;

      //int sumodd = 0;
      //int sumeven = 0;

// Calculate checksum
//for (int i = length - 2; i >= 0; i -= 2)
//{
  //  int digit = (credit_num / 10 % 10) * 2; // Extract and double every other digit
    //sumodd += digit % 10 + digit / 10; // Add the digits of the result to sumodd
    //credit_num /= 100; // Move to the next digit
//}

//for (int i = length - 1; i >= 0; i -= 2)
//{
  //  sumeven += credit_num % 10; // Add the remaining digits to sumeven
    //credit_num /= 100; // Move to the next digit
//}

//int Total = sumodd + sumeven;


  //    if (Total % 10 == 0)
//{
  //  printf("%s\n", cardType);
//}
//else
//{
  //  printf("Invalid\n");
//}


/*

get_long (to get the card number from the user)
declare a variable to store the type of card (string (declare as an empty string))
get card type (American Express = 15 digits
               Mastercard = 16 digits AND start with 51, 52, 53 or 54
               Visa = 13 digits or 16 digits AND start with 4)
               (1. Get length of card number
                2. Compare lengths of different cards
                3. Based on lengths decide card type or compare starting characters and thendecide card type)
store card type in variable (to be displayed later)
Do math that was given on site
Print Card type or INVALID

*/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long credit_num;
    string cardType;

    credit_num = get_long("Number: ");
    int length = 0;
    //printf(length);
    long temp = credit_num;

    if (temp == 0)
    {
        length = 1;
    }
    else
    {
        while (temp != 0)
        {
            temp /= 10;
            length++;
        }
    }

    //printf("%d\n", length);

    if (length == 15 && (credit_num >= 340000000000000 || credit_num >= 370000000000000))
    {
        cardType = "AMEX";
        //printf("%s\n", cardType);
    }
    else if (length == 16 && (credit_num >= 5100000000000000 || credit_num >= 5200000000000000 || credit_num >= 5300000000000000 || credit_num >=5400000000000000))
    {
        cardType = "MASTERCARD";
        //printf("%s\n", cardType);
    }
    else if ((length == 13 && credit_num >= 4000000000000) ||
             (length == 16 && credit_num >= 4000000000000000 && credit_num < 5000000000000000))
    {
        cardType = "VISA";
        //printf("%s\n", cardType);

    }

    int sum = 0;
    int sumodd = 0;
    int sumeven = 0;

    long modNum = 100;
    long divideNum = 10;

    // Calculate checksum
    for (int i = length - 1; i >= 0; i -= 2)
    {
        // int digit = (credit_num / 10 % 10) * 2; // Extract and double every other digit
        // sumodd += digit % 10 + digit / 10;      // Add the digits of the result to sumodd
        // credit_num /= 100;                      // Move to the next digit

        long digit = (credit_num % modNum);
        //printf("%li\n", digit);
        digit = digit/divideNum;

        //printf("%li\n", digit);
        modNum = modNum * 100;
        divideNum = divideNum * 100;
        //printf("%li\n", modNum);
        //printf("%li\n", divideNum);
        //printf("END\n");

        //digit*2
        digit = digit * 2;
        if(digit >= 10)
        {
          long digit1 = digit % 10;

          long digit2 = digit % 100;
          digit2 = digit2/10;

          sumodd = sumodd + digit1 + digit2;
        }
        else
        {

          sumodd = sumodd + digit;

        }
        //sumodd = sumodd + digit


    }

    //printf("%d\n", sumodd);

    modNum = 10;
    divideNum = 1;


    for (int i = length; i >= 0; i -= 2)
    {
        // sumeven += credit_num % 10; // Add the remaining digits to sumeven
        // credit_num /= 100;           // Move to the next digit

        //write code to obtain digit
         long digit = (credit_num % modNum);

         digit = digit/divideNum;

         modNum = modNum * 100;

         divideNum = divideNum * 100;
        //sumeven = sumeven + digit
        sumeven = sumeven + digit;

    }

    //printf("%d\n", sumeven);

    int Total = sumodd + sumeven;

    //printf("%d\n", Total);

    if (Total % 10 == 0)
    {
        printf("%s\n", cardType);
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
