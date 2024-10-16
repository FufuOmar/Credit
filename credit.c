#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool checkSum(long credit_, int length);
int checkLength(long credit_);

int main()
{

   long credit = get_long("Enter credit number: "); // User inputs credit card number
   long networkNum;

   int length = checkLength(credit);
   bool legit = checkSum(credit, length);

   if (legit == true) //If legit, then check which network
   {
      if (length == 16) //Checks either VISA or MASTERCARD
      {
         networkNum = credit / 100000000000000;
         if (networkNum/10 == 4) //VISA check
         {
            printf("VISA\n");
         }
         else if (networkNum == 51 || networkNum == 52 || networkNum == 53 || networkNum == 54 || networkNum == 55) // MASTERCARD check
         {
            printf("MASTERCARD\n");
         }
         else
            //printf("Invalid: No known credit agency (16)\n");
            printf("INVALID\n"); //Neither, therefore invalid
      }
      else if (length == 15) // Checks AMEX
      {
         networkNum = credit / 10000000000000;
         if(networkNum == 34 || networkNum == 37)
         {
            printf("AMEX\n");
         }
         else
         {
            //printf("Invalid: No known credit agency (15)\n");
            printf("INVALID\n");
         }
      }
      else if (length == 13) // Checks VISA
      {
         networkNum = credit / 100000000000;
         if(networkNum/10 == 4)
         {
            printf("VISA\n");
         }
         else
         {
           //printf("Invalid: No known credit agency (13)\n");
            printf("INVALID\n");
         }
      }
      else
      {
         //printf("Invalid: length does not match\n");
         printf("INVALID\n");
      }
   }
   else
   {
   //printf("Invalid: fails checkSum procedure\n");
   printf("INVALID\n");
   }
}

bool checkSum(long credit_, int length){
   long inc = 10;
   int count;
   int temp;
   int num = 0;

   for (int i = 0; i < (length+1)/2; i++)
   {
      temp = ((credit_/inc) % 10) *2;
      if (temp > 9)
      {
         temp = temp % 10 + 1;
      }
      num += temp;
      inc = inc*100;
   }

   inc = 1;

   for (int i = 0; i < (length+1)/2; i++){
      temp = (credit_/inc) % 10;
      num += temp;
      inc *= 100;
   }
   //printf("%i\n", num);
   if (num % 10 == 0){
      return true;
   }
   else{
      return false;
   }
}

int checkLength(long credit_){
  int length = 0;
   do
   {
      credit_ = credit_/10;
      length++;
   }while(credit_ > 0);
  // printf("Length: %i\n", length);
   return length;
}