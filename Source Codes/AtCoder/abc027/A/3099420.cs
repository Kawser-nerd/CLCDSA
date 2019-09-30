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
            int a, b, c;
            string[] s = Console.ReadLine().Split(' ');
            a = int.Parse(s[0]);
            b = int.Parse(s[1]);
            c = int.Parse(s[2]);
            if (a == b)
            {
                Console.WriteLine(c);
            }
            else if (a == c)
            {
                Console.WriteLine(b);
            }
            else
            {
                Console.WriteLine(a);
            }
        }
        static int Max(int a, int b)
        {
            if (a <= b) return b;
            else return a;
        }
    }
}