/*
    CSC 325-your_section_here
    Lab 2, Part 2
    Name: Eyad Merajuddin
    Email: merajue1@tcnj.edu
*/

#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


// constants
const int MAX_UNSIGNED_8_BIT = 255;
const int MAX_SIGNED_8_BIT = 127;


 // functions
    void question1();
    void question2();
    void question3();
    void question4();
    void question5();
    void question6();
    void question7();
    void question8();
    void question9();




    //helper functions  
    char* invertBinary(char* binary);
  
    int decimal_to_binary(int decimal);
    int binary_to_decimal(int binary);
char* addBinary(char* a, char* b);
    char* convert_decimal_to_binary(int decimal);
    int convert_unsigned_binary_to_decimal(int binary);
int convert_signed_binary_to_decimal(const char* binary);
    int add_binary_numbers(int binary1, int binary2);
    char convert_binary_to_hexadecimal(int binary);
    char* convert_hex_to_binary(const char* hex);
char* subtractBinary(char* minuend, char* subtrahend);
    int twos_complement(int binary);
int main(int argc, char *argv[]) {
    // TODO - write your code here
    // question1();
    // question2();
    // question3();
    // question4();
    // question5();
    // question6();
    // question7();
    // question8();
    // question9();

    for (int i = 1; i <= 9; i++) {
        char function_name[20];
        snprintf(function_name, sizeof(function_name), "question%d", i);
        
        if (i == 1) {
            question1();
            printf("\n");
        }
        else if (i == 2) {
            question2();
            printf("\n");
        }
        else if (i == 3) {
            question3();
            printf("\n");
        }
        else if (i == 4) {
            question4();
            printf("\n");
        }
        else if (i == 5) {
            question5();
            printf("\n");
        }
        else if (i == 6) {
            question6();
            printf("\n");
        }
        else if (i == 7) {
            question7();
            printf("\n");
        }
        else if (i == 8) {
            question8();
            printf("\n");
        }
        else if (i == 9) {
            question9();
            printf("\n");
        }
    }



   












    
    
    
    
}
void type_text(const char *text, int delay_ms){
    for(int i = 0; i < strlen(text); i++){
        putchar(text[i]);
        fflush(stdout);
        usleep(delay_ms * 1000);
    }
    // printf("\n");
}




void question1(){
    int max_decimal = pow(2, 8) - 1;
    int max_binary = decimal_to_binary(max_decimal);

    char buffer[1024];

    snprintf(buffer, sizeof(buffer), "Question 1: What is the largest positive value that can be represented \
with an unsigned 8-bit number? Explain.\n");
    type_text(buffer, 50);
    printf("\n");

    snprintf(buffer, sizeof(buffer),"The largest positive value that can be represented with an unsigned 8-bit number \
is %d. This is because when you add 1 more bit to the binary number %d, it will \
carry the 1 to the next bit, making it 100000000. This is 256 in decimal. However, \
since we are only using 8 bits, the 1 is lost, so the largest positive value is 255 and \
will overflow. Also, 2^8-1 = %d or %d in binary\n", max_decimal, max_binary ,max_decimal, max_binary);

type_text(buffer, 10);
printf("\n");


printf("--------------------------------------------\n");

}

void question2(){

    int max_decimal = pow(2, 7) - 1;
    int max_binary = decimal_to_binary(max_decimal);
        char buffer[1024];
 snprintf(buffer, sizeof(buffer), "Question 2:What is the largest positive value that can be represented with \
a 2's complement 8-bit number? Explain. \n");
    type_text(buffer, 50);
    printf("\n");

    snprintf(buffer, sizeof(buffer),"The largest positive value that can be represented with a 2's complement 8-bit number \
is %d. This is because the range of a 2's complement 8bit number is from -128 to 127, so to \
calculate the largest positive value, which only occurs when the sign bit is 0 and the rest of the bits are 1, so \
in binary, it would be 01111111, to calculate the decimal value, we can use the formula \
2^7 + 2^6 + 2^5 + 2^4 + 2^3 + 2^2 + 2^1 + 2^0 = 127, so the largest positive value is 127. Also, 2^7-1 = %d or %d in binary\n\t", max_decimal, max_binary, max_decimal, max_binary);
type_text(buffer, 10);
printf("\n");


printf("--------------------------------------------\n");


}

void question3(){
    //coverting unsigned binary to decimal
      char buffer[1024];
     snprintf(buffer, sizeof(buffer), "Question 3:  Convert the unsigned 8-bit binary \
value 0b10100110 to decimal. Show your work.\n");
     type_text(buffer, 50);
printf("\n");

     int binary = 10100110;
     int decimal = binary_to_decimal(binary);

     snprintf(buffer, sizeof(buffer), "128 64 32 16 8 4 2 1\n");
     type_text(buffer,10);

     snprintf(buffer, sizeof(buffer), " 1   0  1  0 0 1 1 0 \n");
     type_text(buffer, 10);

     snprintf(buffer, sizeof(buffer), "128 + 32 + 4 + 2 = %d\n", decimal);
     type_text(buffer, 10);

     printf("--------------------------------------------\n");

printf("\n");



}

void question4(){
        //coverting signed binary to decimal
          char buffer[1024];
     snprintf(buffer, sizeof(buffer), "Question 4:\n");
     type_text(buffer, 50);

     char binary_string[]="10100110"; 

     char one[]="1";

    char* binary_string_inverted = invertBinary(binary_string);
    char bin[9];
    strcpy(bin, binary_string_inverted);
    char* sum = addBinary(&bin, &one);

     int decimal = convert_signed_binary_to_decimal(sum);
     snprintf(buffer, sizeof(buffer), "128 64 32 16 8 4 2 1\n");
     type_text(buffer, 10);

     snprintf(buffer, sizeof(buffer), " 10100110 \n");
     type_text(buffer, 10);

     snprintf(buffer, sizeof(buffer), " 01011010 \n");
     type_text(buffer, 10);

       snprintf(buffer, sizeof(buffer), "+      1 \n");
     type_text(buffer, 10);

       snprintf(buffer, sizeof(buffer), "---------- \n");
     type_text(buffer, 10);

    snprintf(buffer, sizeof(buffer),"%s\n", sum);
     type_text(buffer, 10);



     snprintf(buffer, sizeof(buffer), "64 + 16 + 8 + 2 = %d\n", decimal);
     type_text(buffer, 10);


     printf("--------------------------------------------\n");



}

void question5(){

    char value1[] = "01011101";
    char value2[] = "01100101";
    char buffer[1024];
     snprintf(buffer, sizeof(buffer), "Question 5:  For the following 8-bit binary values (show your work):\n");
     type_text(buffer, 50);

// adding binary numbers
     snprintf(buffer, sizeof(buffer), "a: Add the binary values together. What is the decimal representation of the \
result if it is interpreted as a signed 8-bit value? \n");
     type_text(buffer, 10);

     char* sum = addBinary(&value1, &value2);

     int decimal = convert_signed_binary_to_decimal(sum);
   

snprintf(buffer, sizeof(buffer), "The binary representation of the result is %s \
and the decimal representation of the result is %d\n", sum, decimal);
     type_text(buffer, 10);


//subtracting binary numbers
     snprintf(buffer, sizeof(buffer), "b:For the same addition, what is the decimal representation of the result if it is \
interpreted as an unsigned 8-bit value?\n");
     type_text(buffer, 10);

      decimal = convert_unsigned_binary_to_decimal(11000010);

     snprintf(buffer, sizeof(buffer), "The unsigned-decimal representation of the result is %d\n", decimal);
     type_text(buffer, 10);


      snprintf(buffer, sizeof(buffer), "c: What is the binary representation of the result of adding value1 and value2 \ 
together? Does this operation result in overflow? If so, under what \ 
interpretation of the values (signed/unsigned)? \n");
     type_text(buffer, 10);

     snprintf(buffer, sizeof(buffer), "The binary result of adding 01011101 and 01100101 was 11000010.");
     type_text(buffer, 10);
          snprintf(buffer, sizeof(buffer), "As noted earlier, 11000010 is 194 in unsigned form and -62 in signed form. \
For overflow: \n");
type_text(buffer, 10);

snprintf(buffer, sizeof(buffer), "Signed overflow: Occurs if the sum exceeds the range of -128 to 127. Since 194 (or 11000010) is outside this range for a signed 8-bit value, there is signed overflow. \
Unsigned overflow: No overflow here because 194 is within the range for unsigned 8-bit values (0 to 255).\n");



      snprintf(buffer, sizeof(buffer), "d: What is the binary representation of the result of subtracting value2 from \
value1? Does this operation result in overflow? If so, under what \
interpretation of the values (signed/unsigned)?\n");
     type_text(buffer, 10);
     char* difference = subtractBinary(&value2, &value1);
     int dec = convert_signed_binary_to_decimal(difference);
     int dec2 = convert_unsigned_binary_to_decimal(11111000);

     snprintf(buffer, sizeof(buffer), "The binary representation of the result of subtracting value2 from value1 is 11111000 \
and the signed decimal representation of the result is -%d\n", dec);
     type_text(buffer, 10);
     
     snprintf(buffer, sizeof(buffer), "The binary representation of the result of subtracting value2 from value1 is 11111000 \
and the unsigned decimal representation of the result is %d\n", dec2);
     type_text(buffer, 10);

    snprintf(buffer, sizeof(buffer), "Signed Interpretation: There's no overflow because the result -8 is within the range of signed 8-bit values (which is from -128 to 127).\n");
     type_text(buffer, 10);

     snprintf(buffer, sizeof(buffer), "Unsigned Interpretation: There's no overflow because the result 248 is within the range of unsigned 8-bit values (which is from 0 to 255).\n");
     type_text(buffer, 10);

     



    printf("--------------------------------------------\n");

}

void question6(){
    //converting binary to hexadecimal
    char buffer[1024];

         snprintf(buffer, sizeof(buffer), "Question 6:\n");
     type_text(buffer, 50);

    snprintf(buffer, sizeof(buffer), "a:\n");
     type_text(buffer, 10);


    char hex1 = convert_binary_to_hexadecimal(0000);
    char hex2 = convert_binary_to_hexadecimal(0b0110);
    char hex3 = convert_binary_to_hexadecimal(0001);
    char hex4 = convert_binary_to_hexadecimal(1111);

    snprintf(buffer, sizeof(buffer), "0000 0110 0001 1111 = 0000 = %c, 0110 = %c, 0001 = %c, 1111 = %c, = 0x%c%c%c%c\n", 
             hex1, hex2, hex3, hex4, hex1, hex2, hex3, hex4);
    type_text(buffer, 10);
     snprintf(buffer, sizeof(buffer), "b:\n");
     type_text(buffer, 10);

     
    char hex11 = convert_binary_to_hexadecimal(1100);
    char hex22 = convert_binary_to_hexadecimal(0b0101);
    char hex33 = convert_binary_to_hexadecimal(1110);
    char hex44 = convert_binary_to_hexadecimal(0b0101);
    snprintf(buffer, sizeof(buffer), "1100 0101 1110 0101 = 1100 = %c, 0101 = %c, 1110 = %c, 0101 = %c, = 0x%c%c%c%c\n", 
             hex11, hex22, hex33, hex44, hex11, hex22, hex33, hex44);
    type_text(buffer, 10);

      snprintf(buffer, sizeof(buffer), "c:\n");
     type_text(buffer, 5100);

        char hex111 = convert_binary_to_hexadecimal(1010);
    char hex222 = convert_binary_to_hexadecimal(0b0111);
    char hex333 = convert_binary_to_hexadecimal(1101);
    char hex444 = convert_binary_to_hexadecimal(0b0110);

        snprintf(buffer, sizeof(buffer), "1010 0111 1101 0110 = 1010 = %c, 0111 = %c, 1101 = %c, 0110 = %c, = 0x%c%c%c%c\n", 
             hex111, hex222, hex333, hex444, hex111, hex222, hex333, hex444);
     type_text(buffer, 50);

    printf("--------------------------------------------\n");


}

void question7(){
    //converting hexadecimal to binary

        char buffer[1024];

                snprintf(buffer, sizeof(buffer), "Question 7:\n");
     type_text(buffer, 50);

    snprintf(buffer, sizeof(buffer), "a:\n");
     type_text(buffer, 10);

     char* binary_a = convert_hex_to_binary("0x23");
     type_text(binary_a, 10);
     printf("\n");


     snprintf(buffer, sizeof(buffer), "b:\n");
     type_text(buffer, 10);
  char* binary_b = convert_hex_to_binary("0x852");
     type_text(binary_b, 10);
     printf("\n");

      snprintf(buffer, sizeof(buffer), "c:\n");
     type_text(buffer, 10);
  char* binary_c = convert_hex_to_binary("0xC1A6");
     type_text(binary_c, 10);
     printf("\n");
      snprintf(buffer, sizeof(buffer), "d:\n");
     type_text(buffer, 10);
      char* binary_d = convert_hex_to_binary("0xEFAB");
     type_text(binary_d, 10);
     printf("\n");

         printf("--------------------------------------------\n");


}

void question8(){
// converting decimal to binary to hexadecimal
    char buffer[1024];

         snprintf(buffer, sizeof(buffer), "Question 8: Convert the following decimal values to 8-bit (2’s complement) binary and \
additionally convert the binary results to hexadecimal. Show your work: \ 
a. 12 = 0000 1100 = 0x0C \n");
     type_text(buffer, 50);

    snprintf(buffer, sizeof(buffer), "a:\n");
     type_text(buffer, 10);

     char* binary_a = convert_decimal_to_binary(12);

     char hexa1 = convert_binary_to_hexadecimal(0000);
     char hexa2 = convert_binary_to_hexadecimal(1100);

     snprintf(buffer, sizeof(buffer), "12 = %s = 0x%c%c\n", binary_a,hexa1, hexa2);
     type_text(buffer, 10);





     

     printf("\n");


     snprintf(buffer, sizeof(buffer), "b:\n");
     type_text(buffer, 10);

           char* binary_b = convert_decimal_to_binary(-36);

     char hexb1 = convert_binary_to_hexadecimal(1101);
     char hexb2 = convert_binary_to_hexadecimal(1100);

     snprintf(buffer, sizeof(buffer), " -36 = %s = 0x%c%c\n", binary_b, hexb1, hexb2);
     type_text(buffer, 10);


      snprintf(buffer, sizeof(buffer), "c:\n");
     type_text(buffer, 10);

           char* binary_c = convert_decimal_to_binary(123);

     char hexc1 = convert_binary_to_hexadecimal(0b0111);
     char hexc2 = convert_binary_to_hexadecimal(1011);

     snprintf(buffer, sizeof(buffer), " 123 = %s = 0x%c%c\n", binary_c, hexc1, hexc2);
     type_text(buffer, 10);

      snprintf(buffer, sizeof(buffer), "d:\n");
     type_text(buffer, 10);

            char* binary_d = convert_decimal_to_binary(-123);

     char hexd1 = convert_binary_to_hexadecimal(1000);
     char hexd2 = convert_binary_to_hexadecimal(0b0101);

     snprintf(buffer, sizeof(buffer), " -123 = %s = 0x%c%c\n", binary_d, hexd1, hexd2);
     type_text(buffer, 10);

     printf("\n");

     printf("--------------------------------------------\n");

      
}

void question9(){
    //bitwise operations



        char buffer[1024];

        
    snprintf(buffer, sizeof(buffer), "Question 9:  Given the following 4-bit binary values, show the results of each bit-wise \
operation, showing both the binary and decimal result value for each (list the \
unsigned decimal value): \n");
     type_text(buffer, 50);

   

     int a =0b0110 | (~0b1010 & 0xF);
    int b = ( ~(0b0110 | 0b1010) ) & 0xF;

     int c =( 0b0111 & ~(0b1001) ) & 0xF;
     int d = ((0b1010 | 0b0000) & 0b1111) & 0xF;
     int e =( 0b0011 ^ 0b1110) & 0xF;
     int f =( 0b0111 << 2) & 0xF;
     int g = (0b0111 >> 2) & 0xF;

    snprintf(buffer, sizeof(buffer), "a: %d\n", a);
     type_text(buffer, 10);



     snprintf(buffer, sizeof(buffer), "b: %d\n", b);
     type_text(buffer, 10);


      snprintf(buffer, sizeof(buffer), "c: %d\n", c);
     type_text(buffer, 10);

      snprintf(buffer, sizeof(buffer), "d: %d\n", d);
     type_text(buffer, 10);

           snprintf(buffer, sizeof(buffer), "e: %d\n", e);
     type_text(buffer, 10);
           snprintf(buffer, sizeof(buffer), "f: %d\n", f);
     type_text(buffer, 10);
           snprintf(buffer, sizeof(buffer), "g: %d\n", g);
     type_text(buffer, 10);


}



int decimal_to_binary(int decimal){
    int binary = 0;
    int i = 1;
    while(decimal != 0){
        binary = binary + (decimal % 2) * i;
        decimal = decimal / 2;
        i = i * 10;
    }
    return binary;

}


int binary_to_decimal(int binary){
    int decimal = 0;
    int i = 0;
    while(binary != 0){
        decimal = decimal + (binary % 10) * pow(2, i);
        binary = binary / 10;
        i++;
    }
    return decimal;

}

    


// Function to add two binary numbers
char* addBinary(char* a, char* b) {
    static char result[10]; // Static array to hold the result (8 bits + null terminator)
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int carry = 0;
    int k = 0;

    while ((i >= 0 || j >= 0 || carry) && k < 8) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }

    // If there is a carry left after 8 bits, it is ignored
    result[k] = '\0';

    // Reverse the result
    for (int l = 0, m = k - 1; l < m; l++, m--) {
        char temp = result[l];
        result[l] = result[m];
        result[m] = temp;
    }

    // Ensure the result is 8 bits long
    if (k < 8) {
        for (int l = k; l < 8; l++) {
            result[l] = '0';
        }
        result[8] = '\0';
    }

    return result;
}




int convert_signed_binary_to_decimal(const char* binary) {
    int decimal = 0;
    int sign = 1;

    // Check if the number is negative (leftmost bit is 1)
    if (binary[0] == '1') {
        sign = -1;
        // Perform two's complement
        char inverted[9];
        for (int i = 0; i < 8; i++) {
            inverted[i] = (binary[i] == '0') ? '1' : '0';
        }
        inverted[8] = '\0';

        // Add 1 to the inverted binary number
        int carry = 1;
        for (int i = 7; i >= 0; i--) {
            if (inverted[i] == '1' && carry == 1) {
                inverted[i] = '0';
            } else if (inverted[i] == '0' && carry == 1) {
                inverted[i] = '1';
                carry = 0;
            }
        }

        // Convert the two's complement binary to decimal
        for (int i = 0; i < 8; i++) {
            if (inverted[i] == '1') {
                decimal += pow(2, 7 - i);
            }
        }
    } else {
        // Convert positive binary to decimal
        for (int i = 0; i < 8; i++) {
            if (binary[i] == '1') {
                decimal += pow(2, 7 - i);
            }
        }
    }

    return sign * decimal;
}


int convert_unsigned_binary_to_decimal(int binary) {
    int decimal = 0;
    int base = 1; // 2^0

    while (binary != 0) {
        int last_digit = binary % 10;
        binary = binary / 10;
        decimal += last_digit * base;
        base = base * 2;
    }

    return decimal;
}



char convert_binary_to_hexadecimal(int binary) {
    int decimal = 0;
    int base = 1;
    
    // Convert 4-digit binary to decimal
    for (int i = 0; i < 4; i++) {
        decimal += (binary % 10) * base;
        binary /= 10;
        base *= 2;
    }
    
    // Convert decimal to hexadecimal character
    if (decimal >= 0 && decimal <= 9) {
        return '0' + decimal;
    } else if (decimal >= 10 && decimal <= 15) {
        return 'A' + (decimal - 10);
    } else {
        // Invalid input
        return 'X';
    }
}




char* convert_hex_to_binary(const char* hex) {
    static char binary[33];  // Max 32 bits (8 hex digits) + null terminator
    int i, j;
    char chunk[5];  // 4 binary digits + null terminator

    binary[0] = '\0';  // Initialize the string

    // Skip "0x" prefix if present
    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
        hex += 2;
    }

    for (i = 0; hex[i] != '\0'; i++) {
        int value;
        if (hex[i] >= '0' && hex[i] <= '9') {
            value = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            value = hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            value = hex[i] - 'a' + 10;
        } else {
            return NULL;  // Invalid hexadecimal digit
        }

        // Convert to 4-bit binary
        for (j = 3; j >= 0; j--) {
            chunk[j] = (value & 1) + '0';
            value >>= 1;
        }
        chunk[4] = '\0';

        // Append to result with space every 4 digits
        if (i > 0 && i % 2 == 0) {
            strcat(binary, " ");
        }
        strcat(binary, chunk);
    }

    return binary;
}


char* convert_decimal_to_binary(int decimal) {
    static char binary[9];  // 8 bits + null terminator
    int i = 7;
    unsigned char value;

    // Initialize the binary string
    binary[8] = '\0';

    // Handle negative numbers and ensure 8-bit range
    value = (unsigned char)decimal;

    // Convert to binary
    do {
        binary[i--] = (value & 1) + '0';
        value >>= 1;
    } while (i >= 0);

    return binary;
}



// invert binary
char* invertBinary(char* binary) {
    for (int i = 0; i < strlen(binary); i++) {
        if (binary[i] == '0') {
            binary[i] = '1';
        } else if (binary[i] == '1') {
            binary[i] = '0';
        }
    }
    return binary;
}


// subtract binary numbers
char* subtractBinary(char* minuend, char* subtrahend) {
    static char twosComplement[10];
    strcpy(twosComplement, subtrahend);

    // Step 1: Find the two's complement of the subtrahend
    invertBinary(twosComplement);
    char one[] = "1";
    strcpy(twosComplement, addBinary(twosComplement, one));

    // Step 2: Add the minuend and the two's complement of the subtrahend
    char* result = addBinary(minuend, twosComplement);

       if (strlen(result) > 8) {
        result += strlen(result) - 8;
    }

    return result;

}

