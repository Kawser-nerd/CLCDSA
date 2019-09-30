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
            int n = int.Parse(Console.ReadLine());
            if (n == 100) Console.WriteLine("Perfect");
            else if (n >= 90) Console.WriteLine("Great");
            else if (n >= 60) Console.WriteLine("Good");
            else Console.WriteLine("Bad");
            Console.ReadLine();
        }
        static int Max(int a, int b)
        {
            if (a <= b) return b;
            else return a;
        }
    }
}