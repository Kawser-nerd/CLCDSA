using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace c
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] hw = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int h = hw[0];
            int w = hw[1];
            string[] a = new string[h];
            string[] odd = new string[h];
            string[] even = new string[h];
            for (int i = 0; i < h; i++)
            {
                a[i] = Console.ReadLine();
            }

            //even
            for (int i = 0; i < h; i++)
            {
                StringBuilder sb = new StringBuilder();
                if (i % 2 == 0)
                {
                    for (int j = 0; j < w - 1; j++)
                    {
                        sb.Append('#');
                    }
                    sb.Append('.');
                }
                else
                {
                    sb.Append('#');
                    for (int j = 1; j < w; j++)
                    {
                        sb.Append(a[i][j]);
                    }
                }
                even[i] = sb.ToString();
            }
            //odd
            for (int i = 0; i < h; i++)
            {
                StringBuilder sb = new StringBuilder();
                if (i % 2 == 1)
                {
                    sb.Append('.');
                    for (int j = 0; j < w - 1; j++)
                    {
                        sb.Append('#');
                    }
                }
                else
                {
                    for (int j = 0; j < w - 1; j++)
                    {
                        sb.Append(a[i][j]);
                    }
                    sb.Append('#');

                }
                odd[i] = sb.ToString();
            }

            for (int i = 0; i < h; i++)
            {
                Console.WriteLine(even[i]);
            }
            Console.WriteLine();
            for (int i = 0; i < h; i++)
            {
                Console.WriteLine(odd[i]);
            }
        }
    }
}