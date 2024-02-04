/* Consider the system of linear Equations
  x-2y+9z=8
    3x+y-z=3
    2x-8y+z=-5 Find i) Augmented Matrix ii) Solve the system by gaussian elimination method*/

#include<stdio.h>
void augmented_matrix(int n, int matrix[][n+1])
{
    int i,j;
    printf("The augmented Matrix is : \t");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1; j++)
        {
                printf("%d\t", matrix[i][j]);

        }
        printf("\n");
        
    }
    //return 0;
} 

void gaussian_elimination(int n, int matrix[][n+1] )
{
    int i,j,k;
    float pivot;

    
    for(int i=0;i<n;i++)
    {   // Make the diagonal element 1
        pivot=matrix[i][i];
        for(int j=0; j<n+1;j++)
        {
            matrix[i][j]/=pivot;
        }
    }
    // Make the other rows 0 in the current column
    for(int k=0; k<n;k++)
    {
        if(k!=i)
        {
            pivot=matrix[k][i];
            for(int j=0;j<n+1;j++)
            {
                matrix[k][j]-=pivot*matrix[i][k];
                
            }
        }   
    }

    printf("The Echeleon form of the matrix :\n");
    for(int i=0;i<n;i++)
    {
        printf("x%d=%f\n", i+1, matrix[i][n]);
    }
}
int main()
{
    int n;
    int i,j;

    printf("enter the number of equations");
    scanf("%d", &n);

    int matrix[n][n+1];
    
    for(i=0;i<n;i++)
    {
        printf("Enter values of equation %d\n", (i+1));
        for(j=0;j<n+1;j++)
        {
            // Input the matrix
            scanf("%d", &matrix[i][j]);
        }
    }
    augmented_matrix(n,matrix);
    gaussian_elimination(n,matrix);
    return 0;

}