//
// Created by linho on 2024-09-29.

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 10
#define MAX_LINE_LENGTH 13

int wordsFitLine(char *word, int max_line_length) {
    int wordLength = 0;

    if (word != NULL) {
        wordLength = strlen(word);
    }

    if (wordLength > max_line_length) {
        return 0;
    } else {
        return 1;
    }
}

void printJustifiedLine(char **words, int word_count, int max_line_length, bool is_last_line) {
    char **wordsPerLine = malloc(MAX_WORD_LENGTH *sizeof(char));
    int wordCount = 0;
    int arraySize = MAX_WORD_LENGTH;
    int currentLineLength = 0;
    char word[100];         // Temporary buffer to hold each word
    int wordLength = 0;

    for (int i = 0; i < word_count; i++) {
        int fitLineLength = wordsFitLine(words[i], max_line_length);
        currentLineLength += strlen(words[i]);

        if (fitLineLength == 1) {
            if (currentLineLength <= max_line_length) {
                wordsPerLine[wordCount++] = words[i];
                printf("%s\n", words[i]);
                printf("%d\n", currentLineLength);
            } else {
                wordsPerLine[wordCount++] = words[i];
                currentLineLength = strlen(words[i]);
                printf("%s\n", words[i]);
                printf("%d\n", currentLineLength);
            }
        } else {
            printf("Error. The word processor can't display the output.");
            return;
        }
    }

}

int main(int argc, char *argv[]) {
    // if( argc != 3) {
    //     printf("Usage: ./a.out <input file> <output file>\n");
    //     return 1;
    // }

    // int max_line_length = atoi((argv[1]));
    // if(max_line_length < 1 || max_line_length > MAX_LINE_LENGTH) {
    //     return 1;
    // }

    char **words = malloc(3 * sizeof(char *));
    words[0] = malloc(6 * sizeof(char));
    words[1] = malloc(6 * sizeof(char));
    words[2] = malloc(3 * sizeof(char));

    strcpy(words[0], "hello");
    strcpy(words[1], "worldzzzzzzz");
    strcpy(words[2], "ca");
    printJustifiedLine(words, 3, 15, true);
}
