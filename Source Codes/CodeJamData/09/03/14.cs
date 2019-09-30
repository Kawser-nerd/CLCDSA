using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Collections;
using System.Text.RegularExpressions;

namespace Welcome_to_Code_Jam
{
    class Program
    {
        static StreamReader reader;
        static StreamWriter writer;

        static void Main(string[] args)
        {
            Console.WriteLine("Enter file name: ");
            String fileName = Console.ReadLine();
            reader = new StreamReader(fileName);
            writer = new StreamWriter(fileName.Replace(".in", ".out"));
            int cases = Convert.ToInt32(reader.ReadLine());
            for (int i = 1; i <= cases; i++)
                ProcessCase(i);
            writer.Flush();
            writer.Close();
        }

        static int[][] tableF;
        static int[][][] tableG;
        static String message;
        static String target = "welcome to code jam";

        static void ProcessCase(int caseNumber)
        {
            int total = 0;
            message = reader.ReadLine();
            tableF = new int[target.Length][];
            for (int a = 0; a < tableF.Length; a++)
            {
                tableF[a] = new int[message.Length];
                for (int b = 0; b < tableF[a].Length; b++)
                    tableF[a][b] = -1;
            }
            tableG = new int[target.Length][][];
            for (int a = 0; a < tableG.Length; a++)
            {
                tableG[a] = new int[message.Length][];
                for (int b = 0; b < tableG[a].Length; b++)
                {
                    tableG[a][b] = new int[message.Length];
                    for (int c = 0; c < tableG[a][b].Length; c++)
                        tableG[a][b][c] = -1;
                }
            }
            total = ComputeF(0, 0);
            String answer = total.ToString();
            if (answer.Length < 4)
                answer = new String('0', 4-answer.Length) + answer;
            writer.WriteLine("Case #{0}: " + answer, caseNumber);
        }

        static int ComputeF(int i, int j)
        {
            int f = tableF[i][j];
            if (f < 0)
            {
                if (i < target.Length - 1)
                {
                    f = 0;
                    int last = message.Length - target.Length + i;
                    for (int k = j; k <= last; k++)
                    {
                        f = (ComputeF(i+1,k+1) * ComputeG(i,k,k) + f) % 10000;
                    }
                }
                else
                {
                    f = ComputeG(i,j,message.Length - 1);
                }
                tableF[i][j] = f;
            }
            return f;
        }

        static int ComputeG(int i, int j, int k)
        {
            int g = tableG[i][j][k];
            if (g < 0)
            {
                if (j < k)
                {
                    if (k < message.Length - 1)
                        g = ComputeG(i, j, j) + ComputeG(i, j + 1, k + 1) - ComputeG(i, k + 1, k + 1);
                    else
                        g = ComputeG(i, j, j) + ComputeG(i, j + 1, k);
                }
                else
                {
                    if (message[j] == target[i])
                        g = 1;
                    else
                        g = 0;
                }
                tableG[i][j][k] = g;
            }
            return g;
        }
    }
}