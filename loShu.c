#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

//returns true if parameter square is a valid Lo Shu square
bool loShuValidator(int square[][3], int size)
{
    int i = 0, j = 0, diagR, diagL, row, col;

    //a helper array to track duplicates
    //each arr[i][j] is added to corresponding index here
    //each index should have only 1 entry
    int duplicateChecker[9] = {0};
   
    diagR = 0;
    diagL = 0;

    printf("\nSUMS:");
    //calculating diagonal sums
    for (i = 0; i < size; i++)
    {
        diagR += square[i][i];
        diagL += square[i][size-1-i];
    }

    printf("\nDR:   %d", diagR);
    printf("\nDL:   %d", diagL);
   
    //return false if sums are not equal
    if(diagR != diagL){
        printf("\nINVALID SUM: different diagonal values");
        return false;
    }
 
    //calculate row/col sums
    for (i = 0; i < size; i++) {
         
        row = 0;
        col = 0;

        for (j = 0; j < size; j++)
        {
            duplicateChecker[square[i][j] - 1] ++;//add each entry to helper array
            row += square[i][j];
            col += square[j][i];
        }
        printf("\nRow%d: %d", i, row);
        printf("\nCol%d: %d", i, col);

        
            
        if (row != diagR){
            printf("\nINVALID SUM: row%d", i);
            return false;
        }
            
        else if (col != diagR){
            printf("\nINVALID COL: col%d", j);
            return false;
        }
            
        
    }

    for(int k = 0; k < 9; k++){
            //printf("%d", duplicateChecker[k]);
            if(duplicateChecker[k] != 1){
                printf("\nDUPLICATE: %d instances of %d\n", duplicateChecker[k], k+1);
                return false;
            }
        }


   return true;
}


int main(void){
    srand(time(NULL));
    int size = 3, count = 0;
    bool isValid = false;

    int square[3][3] = {{4,9,2},
                        {3,5,7},
                        {8,1,6}};

    /**
     * PART 2
     * (See part 1 below - complementary to part 2)
    */
    do{
        count++;//track iterations
        //shuffle matrix
        for (int i=0; i<3; i++){
            int r = rand() % (2 + 1);
            for (int j = 0; j < 3; j++){
                int r2 = rand() % (2 + 1);
                int temp =  square[i][j];
                square[i][j] =  square[r][r2];
                square[r][r2] = temp;
                }
        }
        //check for validity
        isValid = loShuValidator(square, 3);
        
    }while(!isValid);



    printf("\n\n** Count of squares generated: %d", count);
    //end part 2
    

    //PART 1 STARTS HERE
    
    //print the square
    printf("\n\nSquare: \n");
    printf("\n- - -");
    for(int i = 0; i < 3; i++){
        printf("\n");
        for(int j = 0; j < 3; j++)
            printf("%d ", square[i][j]);
    }
    printf("\n- - -\n");

    //check validation return
    if(loShuValidator(square, 3))
        printf("\n\nValid Lo Shu Square!\n\n");
    else
        printf("\n\nInvalid Lo Shu Square!\n\n");

    //end part 1


}