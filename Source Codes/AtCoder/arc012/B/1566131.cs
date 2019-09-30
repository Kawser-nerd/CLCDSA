using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using static System.Console;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] ar = ReadLine().Split(' ');
            int N = int.Parse(ar[0]);
            int Va = int.Parse(ar[1]);
            int Vb = int.Parse(ar[2]);
            float L = float.Parse(ar[3]);
            for(int i = 0; i < N; i++)
            {
                L /= Va;
                L *= Vb;
            }
            WriteLine(L);
            ReadLine();
        }
    }
}