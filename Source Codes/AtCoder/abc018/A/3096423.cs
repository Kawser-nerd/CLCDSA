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
            int aa = 1, bb = 1, cc = 1;
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());
            int c = int.Parse(Console.ReadLine());
            if (a < b) aa++;
            if (a < c) aa++;
            if (b < a) bb++;
            if (b < c) bb++;
            if (c < a) cc++;
            if (c < b) cc++;
            Console.WriteLine(aa + "\n" + bb + "\n" + cc);
            Console.ReadLine();
            return;
        }
    }
}