/*
 * pointer.c - Source file with your solutions to the Lab.
 *             This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>. The included file, "common.c" contains a function declaration
 * that should prevent a compiler warning. In general, it's not good practice
 * to ignore compiler warnings, but in this case it's OK.
 */

#ifndef COMMON_H
#include "common.h"
#endif

/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

#if 0
You will provide your solution to this homework by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
     not allowed to use big constants such as 0xffffffff.
     However, you are allowed to combine constants to values greater
     than 255 or less than 0. e.g. 250 + 250 = 500, so long as
     the operator you are using to combine the constants is listed as
     "legal" at the top of the method you are writing.
  2. Function arguments and local variables (no global variables).
  3. Any operators listed as "allowed" at the top of the method you are writing.
  4. casting.

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc. (unless
     otherwise stated).
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions (unless otherwise stated).
  5. Use any operators not "allowed" at the top of the method you are writing.

  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has *undefined* behavior when shifting by a negative amount or an amount
     greater than or equal to the number of bits in the value being shifted.
     e.g. For x >> n, shifts by n < 0 or n >= *size of x* are undefined
     e.g. if x is a 32-bit int, shifts by >= 32 bits are undefined
     Undefined means you do not know what result you will get from the operation.
#endif

/*
 * STEP 2: Modify the following functions according the coding rules.
 */

/*
 * Return the size of an integer in bytes.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, eFDIStc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */
int intSize() { 
  int result;
  int intArray[10];
  int * intPtr1;
  int * intPtr2;

//pointer containing address of array that holds first int
 intPtr1 = intArray;  

 //pointer containing address of array that hold second int
 intPtr2 = (intArray + 1);    

 //Casting the pointers to long int to make them 8 bytes long 
 result = (long int)intPtr2 - (long int)intPtr1;
 return result;
}

/*
 * Return the size of a double in bytes.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */
int doubleSize() { 
  int result;
  double doubArray[10];
  double * doubPtr1;
  double * doubPtr2;
  
  //Pointer containing address of first item in array
  doubPtr1 = doubArray;  

  //Pointer containing address of second item in array
  doubPtr2 = (doubArray + 1);    

  //Casting to make 8 bytes 
  result = (long int)doubPtr2 - (long int)doubPtr1;
  return result;
}

/*
 * Return the size of a pointer in bytes.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */
int pointerSize() { 
  int result;
  int * ptrArray[10];
  int ** ptrPtr1;
  int ** ptrPtr2;
  
  //Pointer containing address of first pointer in array
  ptrPtr1 = ptrArray;  

  //Pointer containing address of second pointer in array
  ptrPtr2 = (ptrArray + 1);     

  //Casting to make 8 bytes long
  result = (long int)ptrPtr2 - (long int)ptrPtr1;
  return result;
}

/*
 * Given pointers to two distinct variables write a function to swap the values
 * of said variables.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */

void swapInts(int * ptr1, int * ptr2) { 
  //temp stores the initial value being stored at the address in ptr1
  int temp;  
  temp = *ptr1; 
  //Swapping the values by dereferencing
  *ptr1 = *ptr2; 
  *ptr2 = temp;  
} 

/*
 * Modify intArray[5] to be the value 449 using only intArray and pointer arithmetic.
 * 
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, <<, >>, ==, ^
 *   Unary integer operators: !, ~
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, ~= etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, !=, /, %
 *   Unary integer operators: -
 */
int changeValue() {
  int intArray[10]; 
  //Creating pointer to first address
  int * intPtr1 = intArray;  
  
  //Creating pointer which contains address of 6th item (5th index)
  intPtr1 = (int*)intArray + 5;    

  //Setting value at that address to be 449 
  *intPtr1 = 200 + 200 + 49;
  return *intPtr1; 
}  

/*
 * Return 1 if the addresses stored in ptr1 and ptr2 are within the
 * *same* 64-byte aligned  block of memory. Check the spec for examples if you are
 * confused about what this means. Return zero otherwise.
 * Operators / and % and loops are NOT allowed.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, <<, >>, ==, ^
 *   Unary integer operators: !, ~
 *   Shorthand operators based on the above: ex. <<=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, !=, /, %
 *   Unary integer operators: -
 */
int withinSameBlock(int * ptr1, int * ptr2) {
  //if the ptr2 - ptr1 is divisible by 64, return 0 
  //Shift right by 6 
  //Somehow check if after shifting, we get a whole number adress or a decimal 
    
    int pointer1 = (unsigned long)ptr1; 
    int pointer2 = (unsigned long)ptr2;

    //Shift right by 6 to divide by 2^6 = 64
    pointer1 = pointer1 >> 6;  
    pointer2 = pointer2 >> 6;  

    //Each byte has its own address
    //If pointers are both equal after dividing by 64, they are in the same 64 byte range 
    //returning 1 if both pointers are equal, 0 if unequal 
    return !(pointer1^pointer2);
}

/*
 * Return 1 if ptr points to an element within the specified intArray, 0 otherwise.
 * Pointing anywhere in the array is fair game, ptr does not have to
 * point to the beginning of an element. Check the spec for examples if you are 
 * confused about what this method is determining.
 * size is the size of intArray in number of ints. Can assume size != 0.
 * Operators / and % and loops are NOT allowed.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, <<, >>, ==, ^
 *   Unary integer operators: !, ~
 *   Shorthand operators based on the above: ex. <<=, *=, ++, --, etc.
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, !=, /, %
 *   Unary integer operators: -
 */
int withinArray(int * intArray, int size, int * ptr) {
  
  //start holds first adress of array
  int start = (long)(intArray); 

  //end holds last adress of array 
  //We multiply by 4 bc size is an int, and an int has 4 bytes 
  //we want end to be in terms of individual bytes since each byte has its own memory address
  int end = (long)(intArray) + 4*(size -1); 
  //Casting as long to make it 8 bytes long-size of a pointer 
  int myptr = (long)ptr;  
  //Checking to see if any of the ints are negative
  int sign1 = (myptr - start) >> 31;  
  int sign2 = (end - myptr) >> 31; 

  //If ptr is outside the range, either sign1 or sign2 will be negative
  //If sign1 or sign2 is negative-equals (1111...111)- they are not equal and we return 0
  return !(sign1 ^ sign2);
}

/*
 * In C characters are are terminated by the null character ('\0')
 * given a pointer to the start of the string return the length of this string.
 * (The null character is not counted as part of the string length.)
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, ==, !=, <, >
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. <<=, *=, ++, --, etc.
 *   Control constructs: for, while
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <<, >>, ^, /, %
 *   Unary integer operators: ~, -
 */
int stringLength(char * s) 
{ 
  //int pos, char*currPtr, char currChar;
  int pos = 0; 
  char * currPtr = s; 
  char currChar = *(s); 
  while(currChar != '\0') 
  { 
    //Incrementing pointer
    currPtr = currPtr + 1; 

    //Settig currChar equal to the next char in string s
    currChar = *(currPtr);
    pos ++;
  } 
  return pos;
}

/*
 * Returns the length of the initial portion of str1 which consists only of characters that are part of str2.
 * The search does not include the terminating null-characters of either strings, but ends there.
 * 
 * Example, stringSpan("abcdefgh", "abXXcdeZZh"); // returns 5
 *  
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, ==, !=, <, >
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. <<=, *=, ++, --, etc.
 *   Control constructs: for, while
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <<, >>, ^, /, %
 *   Unary integer operators: ~, -
 */

int stringSpan(char * str1, char * str2) 
{
  int length = 0; 
  int pos = 0;  
  int count = 0; 
  char * ptr = str1; 
  char curr = *(ptr);
  char currChar1 = *(str1);  
  char currChar2 = *(str2); 

  //Finding length of str1
  while(curr != '\0') 
  { 
    ptr = ptr + 1;
    curr = *(ptr);
    length ++;
  }  
  
  while(pos <= length) 
  { 
    //If match is found,we can increment str1 and check match for next char in first string
    if(currChar1 == currChar2) 
    { 
      str1 = str1 + 1; 
      currChar1 = *(str1); 

      //Increment count if match is found
      count = count +1; 
    } 
    else 
    { 
      //If no match found, str1 is still pointing to same char. But we check the next char in str2 for match
      str2 = str2 + 1; 
      currChar2 = *(str2);  
      //Incrment pos to make sure that we don't pass length of str1
      pos = pos +1;
    }
  } 
  return count;
}

/*
 * Change the value pointed to by ptr byte-by-byte so that when returned as an integer
 * the value is 449449.
 *
 * Hint: Remember that an int is 4 bytes.
 *
 * Hint: Remember how little endian works for data storage, how is it different between an multiple bytes(int) and a single byte?
 *
 * Hint: It will be easiest to start convert 449449 into binary form and starting seeing how the endian works from there.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, etc.
 *   Unary integer operators: !
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <, >, <<, >>, ==, !=, ^, /, %
 *   Unary integer operators: ~, -
 */
int endianExperiment(int * ptr) 
{ 
  //449449 in hex form is 0x0006DBA9 
  //If we are using little endian, the least significant byte is inserted first 
  //We create char pointer to point to each byte individually 
  //byte pointer is pointing to first byte address in ptr
  char *byte = (char*) ptr; 
  //Setting value of first byte 
  *byte = 0xA9; 
  byte ++;  
  *byte = 0xDB;    
  byte ++;
  *byte = 0x06; 
  byte ++;  
  *byte = 0x00;  
  return *ptr;
}

/*
 * Selection sort is a sorting algorithim that works by partitioning the array into
 * a sorted section and unsorted section. Then it repeatedly selects the minimum element
 * from the unsorted section and moves it to the end of the sorted section.
 *
 * So the pseudo-code might look something like this:
 * arr - an array
 * n - the length of arr
 *
 * for i = 0 to n - 1
 *   minIndex = i
 *   for  j = i + 1 to n
 *       if arr[minIndex] > arr[j]
 *           minIndex = j
 *       end if
 *   end for
 *   Swap(arr[i], arr[minIndex])
 * end for
 *
 * Implement selection sort below, it might be helpful to use the swapInts function you
 * defined earlier.
 *
 * ALLOWED:
 *   Pointer operators: *, &
 *   Binary integer operators: -, +, *, ==, !=, <, >
 *   Unary integer operators: !
 *   Shorthand operators based on the above: ex. +=, *=, ++, --, etc.
 *   Control constructs: for, while, if
 *   Function calls: swapInt()
 *
 * DISALLOWED:
 *   Pointer operators: [] (Array Indexing Operator)
 *   Binary integer operators: &, &&, |, ||, <<, >>, ^, /
 *   Unary integer operators: ~, -
 */
void selectionSort(int arr[], int arrLength) 
{
  int i, j, min_index;
  // Your code here 
  for (i = 0; i < arrLength - 1; i++) 
  { 
    min_index = i; 
    //j starts at first position of unsorted array
    for (j = i + 1; j < arrLength; j++) 
    { 
      //Going through all values until we find the min value in unsorted array 
      if (*(arr+min_index) > *(arr+j)) 
      { 
        min_index = j;
      }
    }
    //Once we find the min value, we insert that as the next item of sorted array 
    //By swapping the item in last index of sorted array with what we found to be the min index in unsorted
    swapInts((arr + i), (arr + min_index));
  }
}

