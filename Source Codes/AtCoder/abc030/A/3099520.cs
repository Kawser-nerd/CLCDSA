using System;
using System.Collections;
using System.Collections.Generic;
using System.Web;
namespace WpfApp1
{
    class program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int a = int.Parse(s[0]);
            int b = int.Parse(s[1]);
            int c = int.Parse(s[2]);
            int d = int.Parse(s[3]);
            if ((double)b / a < (double)d / c)
            {
                Console.WriteLine("AOKI");
            }
            else if ((double) b / a == (double)d / c)
            {
                Console.WriteLine("DRAW");
            }
            else
            {
                Console.WriteLine("TAKAHASHI");
            }
        }
        static int Max(int a, int b)
        {
            if (a <= b) return b;
            else return a;
        }
        static int Min(int a,int b)
        {
            if (a == Max(a, b)) return b;
            else return a;
        }
    }
}