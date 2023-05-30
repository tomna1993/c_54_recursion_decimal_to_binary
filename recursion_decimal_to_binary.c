#include <cs50.h>
#include <stdio.h>

#define ARRAY_LENGTH 32
#define BITS 8

void print_binary(int binary_array[], int array_length);
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

    print_binary(binary, ARRAY_LENGTH);

    return 0;
}

// Print binary number
void print_binary(int binary_array[], int array_length)
{
    for (int i = 0; i < array_length; i++)
    {
        printf ("%i", binary_array[i]);   

        // Separate each 4 bits with space
        if ((i+1) % 4 == 0)
        {
            printf (" ");
        }  
    }

    printf ("\n");
}

// Convert decimal number to binary
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