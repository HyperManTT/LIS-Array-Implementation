#include <stdio.h>
#include <stdlib.h>


void printArray(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void printSequence(int sequence[], int bestSequenceSoFar[], int startingPosOfSequence[], int size)
{
    printf("\n");
    int max = 0, i, maxIndex = 0;
    for (i = 0; i < size; i++)
    {
        if(bestSequenceSoFar[i] > max)
        {
            max = bestSequenceSoFar[i];
            maxIndex = i;
        }
    }

    int numPrints = bestSequenceSoFar[maxIndex];
    int indexToPrint = maxIndex;
    while(numPrints > 0)
    {
        printf("%d ", sequence[indexToPrint]);
        indexToPrint = startingPosOfSequence[indexToPrint];
        numPrints--;
    }
}
void getLIS(int sequence[], int bestSequenceSoFar[], int startingPosOfSequence[], int size)
{
    int currentMaxSequence, i, j;
    int startingIndexPos = 0;
    bestSequenceSoFar[0] = 1;
    startingPosOfSequence[0] = 0;
    for ( i = 1; i < size; i++)
    {
        currentMaxSequence = 0;
        startingIndexPos = i;
        for(j = 0; j < i; j ++)
        {
            if(sequence[i] > sequence[j])
            {
                if(bestSequenceSoFar[j] > currentMaxSequence)
                {
                    currentMaxSequence = bestSequenceSoFar[j];
                    startingIndexPos = j;
                }
            }
        }
        bestSequenceSoFar[i] = currentMaxSequence + 1;
        startingPosOfSequence[i] = startingIndexPos;
    }
    printArray(bestSequenceSoFar, 11);
    printSequence(sequence, bestSequenceSoFar, startingPosOfSequence, size);
}

int main()
{
    int sequence[] = {25, 18, 12, 32, 47, 41, 27, 51, 30, 58, 23};
    int bestSequenceSoFar[11];
    int startingPosOfSequence[11];
    getLIS(sequence, bestSequenceSoFar, startingPosOfSequence, 11);
}
