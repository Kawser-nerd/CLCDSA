#import <stdio.h>
#import <stdlib.h>
#import <string.h>
#include <stdarg.h>

#define false 0
#define true 1
#define bool int
#define read fscanf

bool isInFile, isOutFile;
FILE *inFile, *outFile;

void write(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    if (isOutFile)
        vfprintf(outFile, fmt, ap);
    va_end(ap);
}

void solveOne();

void main(int argc, char **argv) {
    int T, i;

    isInFile = (argc > 1);
    if (isInFile) {
        inFile = fopen(argv[1], "r");
        if (inFile == NULL) {
            printf("infile not found");
            exit(0);
        }
    } else {
        inFile = stdin;
    }
    isOutFile = (argc > 2);
    if (isOutFile) {
        outFile = fopen(argv[2], "w");
        if (outFile == NULL) {
            printf("outfile error");
            exit(0);
        }
    }

    read(inFile, "%d\n", &T);
    for (i = 1; i <= T; i++) {
        write("Case #%d: ", i);
        solveOne();
        write("\n");
    }

}

int check(char line[]) {
    int nX = 0, nO = 0, nT = 0;
    int i;
    for (i = 0; i < 4; i++) {
        switch (line[i]) {
            case 'X':
                nX++;
                break;
            case 'O':
                nO++;
                break;
            case 'T':
                nT++;
                break;
        }
    }
    //write("%d %d %d\n", nX ,nO, nT);
    if (nX + nT == 4)
        return 1; //X won
    if (nO + nT == 4)
        return 2; //0 won
    if (nX + nO + nT == 4)
        return 0; //line complete
    return -1; //line not complete
}

void solveOne() {
    int i, j;
    char b[4][4];
    char temp[4];
    int lineResult;
    int complete = 1;

    /* read data */
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            read(inFile, "%c", &(b[i][j]));
        read(inFile, "\n");
    }
    read(inFile, "\n");

    /* solve */
    //horzontal
    for (i = 0; i < 4; i++) {
        temp[0] = b[i][0];
        temp[1] = b[i][1];
        temp[2] = b[i][2];
        temp[3] = b[i][3];
        lineResult = check(temp);
        //write("%d", lineResult);
        switch (lineResult) {
            case 1:
                write("X won");
                return;
            case 2:
                write("O won");
                return;
            case -1:
                complete = 0;
                break;
        }
    }
    //vertical
    for (i = 0; i < 4; i++) {
        temp[0] = b[0][i];
        temp[1] = b[1][i];
        temp[2] = b[2][i];
        temp[3] = b[3][i];
        switch (check(temp)) {
            case 1:
                write("X won");
                return;
            case 2:
                write("O won");
                return;
            case -1:
                complete = 0;
        }
    }
    //left-top to right-bottom
    temp[0] = b[0][0];
    temp[1] = b[1][1];
    temp[2] = b[2][2];
    temp[3] = b[3][3];
    switch (check(temp)) {
        case 1:
            write("X won");
            return;
        case 2:
            write("O won");
            return;
        case -1:
            complete = 0;
    }

    //right-top to left-bottom
    temp[0] = b[0][3];
    temp[1] = b[1][2];
    temp[2] = b[2][1];
    temp[3] = b[3][0];
    switch (check(temp)) {
        case 1:
            write("X won");
            return;
        case 2:
            write("O won");
            return;
        case -1:
            complete = 0;
    }

    if (complete == 0)
        write("Game has not completed");
    else
        write("Draw");
}
