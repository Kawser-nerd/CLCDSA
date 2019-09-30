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
            string s = Console.ReadLine();
            int t = int.Parse(Console.ReadLine());
            char[] a = new char[5];
            for (int i = 0; i < 5; i++) a[i] = s[i];
            Console.Write(a[(t - 1) / 5]);
            Console.WriteLine(a[(t - 1) % 5]);
        }
    }
}