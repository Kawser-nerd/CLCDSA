using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace atcoder01
{
    class Program
    {
        //0036
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            char[,] a = new char[n, n];  //string ??char
            char[,] b = new char[n, n];

            for(int i = 0;i<n;i++)
            {
                string str = Console.ReadLine();

                for (int j = 0; j < n; j++) a[i, j] = str[j];
            }

            for (int x = 0; x < n ;x++)
            {
                for (int y = 0; y < n;y++)
                {
                    b[x,y] = a[n-y-1,x];
                }
            }

            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y < n; y++)
                {
                    Console.Write(b[x, y]);
                }
                Console.WriteLine();
            }
        }
    }
}