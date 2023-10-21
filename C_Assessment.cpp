#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverseString(char *str) 
{
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to concatenate two strings
void concatenateStrings(char *str1, char *str2) {
    strcat(str1, str2);
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int length = strlen(str);
.    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}

// Function to copy a string
void copyString(char *dest, char *src) {
    strcpy(dest, src);
}

// Function to find the length of a string
int findStringLength(char *str) {
    return strlen(str);
}

// Function to count the frequency of a character in a string
int countCharacterFrequency(char *str, char ch) {
    int count = 0;
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}

// Function to count vowels and consonants in a string
void countVowelsAndConsonants(char *str) {
    int vowels = 0;
    int consonants = 0;
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        char ch = tolower(str[i]);
        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    printf("Vowels: %d\nConsonants: %d\n", vowels, consonants);
}

// Function to count blank spaces and digits in a string
void countBlankSpacesAndDigits(char *str) {
    int spaces = 0;
    int digits = 0;
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (isspace(str[i])) {
            spaces++;
        } else if (isdigit(str[i])) {
            digits++;
        }
    }
    printf("Blank Spaces: %d\nDigits: %d\n", spaces, digits);
}

int main() {
    char choice;
    char str1[100], str2[100];

    do {
        printf("String Operations Menu:\n");
        printf("1. Reverse a string\n");
        printf("2. Concatenate two strings\n");
        printf("3. Check if a string is a palindrome\n");
        printf("4. Copy a string\n");
        printf("5. Find the length of a string\n");
        printf("6. Count the frequency of a character in a string\n");
        printf("7. Count vowels and consonants in a string\n");
        printf("8. Count blank spaces and digits in a string\n");
        printf("9. Quit\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter a string to reverse: ");
                scanf(" %s", str1);
                reverseString(str1);
                printf("Reversed string: %s\n", str1);
                break;
            case '2':
                printf("Enter the first string: ");
                scanf(" %s", str1);
                printf("Enter the second string: ");
                scanf(" %s", str2);
                concatenateStrings(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;
            case '3':
                printf("Enter a string to check for palindrome: ");
                scanf(" %s", str1);
                if (isPalindrome(str1)) {
                    printf("The string is a palindrome.\n");
                } else {
                    printf("The string is not a palindrome.\n");
                }
                break;
            case '4':
                printf("Enter a string to copy: ");
                scanf(" %s", str1);
                copyString(str2, str1);
                printf("Copied string: %s\n", str2);
                break;
            case '5':
                printf("Enter a string to find its length: ");
                scanf(" %s", str1);
                printf("Length of the string: %d\n", findStringLength(str1));
                break;
            case '6':
                printf("Enter a string: ");
                scanf(" %s", str1);
                char ch;
                printf("Enter a character to find its frequency: ");
                scanf(" %c", &ch);
                printf("Frequency of '%c' in the string: %d\n", ch, countCharacterFrequency(str1, ch));
                break;
            case '7':
                printf("Enter a string: ");
                scanf(" %s", str1);
                countVowelsAndConsonants(str1);
                break;
            case '8':
                printf("Enter a string: ");
                scanf(" %s", str1);
                countBlankSpacesAndDigits(str1);
                break;
            case '9':
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }

        printf("Do you want to perform another operation? (y/n): ");
        scanf(" %c", &choice);

    }
	 while (choice == 'y' || choice == 'Y');

    return 0;
}
