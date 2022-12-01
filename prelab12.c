#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    FILE *fp;

    int MAXCHAR = 1000; //row length
    int MAXLENGTH = 5;

    char row[MAXCHAR];
    int totalCount = 0;

    int acArr[MAXLENGTH];

    fp = fopen("test.csv", "r");

    for (int i = 1; i < MAXLENGTH; i++)
    {
        if (feof(fp) == true)
        {
            break;
        }
        fgets(row, MAXCHAR, fp);

        int targetColumn = 1;

        int indexPosStart;
        int indexPosEnd;

        for (int j = 0, columnCount = 0; j < strlen(row); j++)
        {
            char currentChar = row[j];

            if (',' == current_char)
            {
                columnCount++;
                if (columnCount == targetColumn)
                {
                    indexPosStart = j;
                }
                if (columnCount == targetColumn+1) {
                    indexPosEnd = j;
                }
                
            }
        }

        int outLength = (indexPosEnd - indexPosStart);
        char out[outLength];
        for (int j = indexPosStart+1; j < indexPosEnd; j++) {
            int pos = (j-indexPosStart);
            out[pos] = row[j];
            
        }
        printf("%s\n", out);
    }

    return 0;
}