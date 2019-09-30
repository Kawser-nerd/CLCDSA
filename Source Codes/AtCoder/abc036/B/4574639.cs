using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - ??
            int n = int.Parse(Console.ReadLine());

            var square = GetSquare(n);

            for(int i = 0; i < n; i++)
            {
                string s = "";

                for (int j = n - 1; j >= 0; j--)
                {
                    s += square[j, i];
                }

                Console.WriteLine(s);
            }            
        }

        static char[,] GetSquare(int n)
        {
            var square = new char[n, n];

            for(int i = 0; i < n; i++)
            {
                string s = Console.ReadLine();
                
                for(int j = 0; j < n; j++)
                {
                    square[i, j] = s[j];
                }
            }

            return square;
        }
    }
}