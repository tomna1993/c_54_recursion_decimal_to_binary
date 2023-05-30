#include <cs50.h>
#include <stdio.h>

#define ARRAY_LENGTH 32

void dec_to_binary(int input_decimal, int output_binary[], int array_length);

int main(void)
{
    // MSB = binary[0]
    // LSB = binary[ARRAY_LENGTH-1]
    int binary[ARRAY_LENGTH];

    // Initialize the binary array
    for (int i = 0; i < ARRAY_LENGTH-1; i++)
    {
        binary[i] = 0;
    }

    int decimal = get_int("Number: ");

    // Convert decimal number to binary and save it into "binary" array
    dec_to_binary(decimal, binary, ARRAY_LENGTH);

    // Print binary number separeted to 8-bits in a row
    // MSB    LSB
    for (int LastByte = ARRAY_LENGTH / 8, byteCount = 1; LastByte >= byteCount; byteCount++)
    {
        for (int MSB = (byteCount * 8)-8, LSB = (byteCount * 8)-1; MSB <= LSB; MSB++) 
        {
            printf ("%i", binary[MSB]);     
        }
        printf ("\n");
    }
}

void dec_to_binary(int input_decimal, int output_binary[], int array_length)
{
    // Define base-case / exit condition
    if (input_decimal == 0 || array_length < 0)
    {
        return;
    }

    // Save remainder; first iteration starts with the last element
    // of the array - LSB
    output_binary[array_length - 1] = input_decimal % 2;

    // Call function recursively
    dec_to_binary(input_decimal / 2, output_binary, array_length - 1);
}