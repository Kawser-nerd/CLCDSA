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
            string[] s = Console.ReadLine().Split(' ');
            int[] a = new int[3];
            for (int i = 0; i < 3; i++) a[i] = int.Parse(s[i]);
            Array.Sort(a);
            Console.WriteLine(a[1]);
            return;
        }
    }
}