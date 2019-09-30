using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ_R1C_A
{
    class Program
    {
        static int n;

        static bool[,] a;

        static int[] b;

        static bool result;

        static bool[] flags;

        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines(@"..\..\input.txt");

            StringBuilder output = new StringBuilder();

            int countOfTests = int.Parse(input[0]);
            int k = 1;
            for (int i = 0; i < countOfTests; i++)
            {
                n = int.Parse(input[k]);
                a = new bool[n,n];
                flags = new bool[n];
                
                for (int j = 0; j < n; j++)
                {
                    string[] row = input[k + j + 1].Split(' ');

                    int count = int.Parse(row[0]);
                    
                    for (int p = 0; p < count; p++)
                    {
                        int u = int.Parse(row[p + 1]);
                        a[j, u - 1] = true;
                    }
                }

                for (int j = 0; j < n; j++)
                {
                    result = false;

                    b = new int[n];
                    Find(j);

                    if (result)
                        break;

                }

                output.AppendLine(string.Format("Case #{0}: {1}", i + 1, result ? "Yes" : "No"));
                k += n + 1;
            }

            File.WriteAllText(@"..\..\output.txt", output.ToString());
        }

        private static void Find(int v)
        {
            if (result)
                return;
            if (b[v] > 0)
            {
                result = true;
                return;
            }
            else
                b[v]++;

            for(int u = 0;u<n;u++)
                if (a[v, u])
                {
                    a[v, u] = false;
                    Find(u);
                    a[v, u] = true;
                }

        }
    }
}
