using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace AGC23_B_
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(ReadLine());
            char[][] m = new char[n][];
            for (int i = 0; i < n; i++)
            {
                m[i] = ReadLine().ToCharArray();
            }

            var ai = new List<int>();
            int flag1 = 0;
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                flag1 = 0;
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (m[(j + i) % n][k] == m[(k + i) % n][j])
                        {
                            flag1++;
                        }
                    }
                }
                if (flag1 == n * n)
                {
                    count++;
                }
            }
            
            WriteLine(count * n);
        }
    }
}