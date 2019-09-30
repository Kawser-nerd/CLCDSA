using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

public class A : Problem
{
    protected override string solveCase()
    {
        line = reader.ReadLine();
        String[] valoriInput = line.Split(' ');

        int R = int.Parse(valoriInput[0]);
        int C = int.Parse(valoriInput[1]);

        int[,] matrix=new int[R,C];

        for (int i = 0; i < R; i++)
        {
            line = reader.ReadLine();
          
            for (int j = 0; j < C; j++)
            {
                if ((line[j] == '#'))
                {
                    matrix[i, j] = 1;
                }
            }
        }

        Console.WriteLine();

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (matrix[i, j] ==1)
                {
                    matrix[i, j] = -1;
                    
                    if ( i==R-1 || matrix[i+1, j] <=0)
                    {
                        return "\nImpossible";
                    }
                    matrix[i + 1, j] = -2;

                    if (j == C - 1 || matrix[i, j+1] <= 0)
                    {
                        return "\nImpossible";
                    }
                    matrix[i, j + 1] = -2;

                    if (matrix[i + 1, j+1] <= 0)
                    {
                        return "\nImpossible";
                    }
                    matrix[i + 1, j+1] = -1;
                }
            }
        }




        string res = "";

        for (int i = 0; i < R; i++)
        {
            res += "\n";
            for (int j = 0; j < C; j++)
            {
                if (matrix[i, j] == 0)
                {
                    res += ".";
                }
                else if (matrix[i, j] == -1)
                {
                    res += "/";
                }
                else if (matrix[i, j] == -2)
                {
                    res += "\\";
                }
            }
            
        }


        return res;
    }






   

}


