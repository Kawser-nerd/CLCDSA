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
            string w = Console.ReadLine();
            Console.WriteLine(w + 's');
            Console.ReadLine();
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