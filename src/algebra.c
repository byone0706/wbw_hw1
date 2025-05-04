#include "algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
    // ToDo
    Matrix c;
    int i,j;
    if ((a.rows != b.rows)||(a.cols != b.cols))
    {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return ;
    } 
    else
    {
        c.cols=a.cols;
        c.rows=a.rows;
        for (i=0;i<a.rows;i++)
        {
            for (j=0;j<a.cols;j++)
            {
                c.data[i][j]=a.data[i][j]+b.data[i][j];
            }
        }
    }
    return c;
}

Matrix sub_matrix(Matrix a, Matrix b)
{
    // ToDo
    Matrix c;
    int i,j;
    if ((a.rows != b.rows)||(a.cols != b.cols))
    {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return ;
    } 
    else
    {
        c.cols=a.cols;
        c.rows=a.rows;
        for (i=0;i<a.rows;i++)
        {
            for (j=0;j<a.cols;j++)
            {
                c.data[i][j]=a.data[i][j]-b.data[i][j];
            }
        }
    }
    return c;
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    // ToDo
    Matrix c;
    int i,j,k;
    if ((a.cols != b.rows))
    {
        printf("Error: The number of cols of matrix a must be equal to the number of rows of matrix b.\n");
        return ;
    } 
    else
    {
        c.rows=a.rows;
        c.cols=b.cols;
        for (i=0;i<c.rows;i++)
        {
            for (j=0;j<c.cols;j++)
            {
                c.data[i][j]=0;
            }
        }
        for (i=0;i<c.rows;i++)
        {
            for (j=0;j<c.cols;j++)
            {
                for (k = 0;k<a.cols;k++)
                {
                    c.data[i][j]+=a.data[i][k]*b.data[k][j];
                }
            }
        }
    }
    return c;
}

Matrix scale_matrix(Matrix a, double k)
{
    // ToDo
    Matrix c;
    int i,j;
    c.cols=a.cols;
    c.rows=a.rows;
    for (i=0;i<a.rows;i++)
    {
        for (j=0;j<a.cols;j++)
        {
            c.data[i][j]=a.data[i][j]*k;
        }
    }
    return c;
}

Matrix transpose_matrix(Matrix a)
{
    // ToDo
    Matrix c;
    int i,j;
    c.cols=a.rows;
    c.rows=a.cols;
    for (i=0;i<a.rows;i++)
    {
        for (j=0;j<a.cols;j++)
        {
            c.data[j][i]=a.data[i][j];
        }
    }
    return c;
}

double det_matrix(Matrix a)
{
    // ToDo
    Matrix left;
    int i,j,k;
    double deta=0;
    if (a.rows != a.cols)
    {
        printf("Error: The matrix must be a square matrix.\n");
        return 0;
    } 
    else if (a.cols==1) 
    {
        return a.data[0][0];
    }
    else
    {
        left.cols=left.rows=a.cols-1;
        for (i=0;i<a.rows;i++)
        {
            for (j=0;j<a.cols;j++)
            {
                for (k=1;k<a.rows;k++)
                {
                    if (j < i)
                    {
                        left.data[k-1][j]=a.data[k][j];
                    }
                    else if (j > i)
                    {
                        left.data[k-1][j-1]=a.data[k][j];
                    }
                }
            }/*余子式*/
            deta+=a.data[0][i]*pow(-1,i)*det_matrix(left);
        }
    }
    return deta;
}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    Matrix left,inv;
    int i,j,row1,col1;
    if ((a.rows != a.cols)||(det_matrix(a) == 0))
    {
        printf("Error: The matrix must be a square matrix.\n");
        if (det_matrix(a) == 0)
        {
            printf("Error: The matrix is singular.\n");
        }
        return ;
    } 
    else
    {
        inv.cols=inv.rows=a.cols;
        left.cols=left.rows=a.cols-1;
        for (i=0;i<a.rows;i++)
        {
            for (j=0;j<a.cols;j++)/*确定去除的行和列*/
            {
                for (row1=0;row1<a.rows;row1++)
                {
                    for (col1=0;col1<a.cols;col1++)
                    {
                        left.data[row1][col1]=a.data[row1<i?row1:row1+1][col1<j?col1:col1+1];
                    }/*余子式*/
                }
                inv.data[i][j]=pow(-1,i+j)*det_matrix(left)/det_matrix(a);
            }
        }
    }
    return inv;
}

int rank_matrix(Matrix a)
{
    // ToDo
    return 0;
}

double trace_matrix(Matrix a)
{
    // ToDo
    Matrix left;
    int i;
    double trace=0;
    if (a.rows != a.cols)
    {
        printf("Error: The matrix must be a square matrix.\n");
        return 0;
    } 
    else
    {
        for (i=0;i<a.rows;i++)
        {
            trace+=a.data[i][i];
        }
    }
    return trace;
}

void print_matrix(Matrix a)
{
    int i,j;
    for ( i = 0; i < a.rows; i++)
    {
        for ( j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}