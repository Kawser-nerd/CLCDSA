using System;
using System.Collections;
using System.Collections.Generic;
using System.Web;
namespace WpfApp1
{
    class program
    {
        static int Max(int a,int b)
        {
            if (a <= b) return b;
            else return a;
        }
        static void Main(string[] args)
        {
            int q = int.Parse(Console.ReadLine());
            if (q == 1)
            {
                Console.WriteLine("ABC");
            }
            else
            {
                Console.WriteLine("chokudai");
            }
        }
    }
}