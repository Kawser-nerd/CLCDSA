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
            int C = int.Parse(ReadLine());
            List<int[]> boxes = new List<int[]>();
            for (int i = 0; i < C; i++)
            {
                int[] ar = Sort( ReadLine()
                    .Split(' ')
                    .Select(_ => int.Parse(_))
                    .ToArray());
                boxes.Add(ar);
            }
            int n = 0, m = 0, l = 0;
            foreach(var box in boxes)
            {
                if (n < box[0])
                    n = box[0];
                if (m < box[1])
                    m = box[1];
                if (l < box[2])
                    l = box[2];
            }
            WriteLine(n * m * l);
            ReadLine();
        }
        static int[] Sort(int[] ar)
        {
            for (int i = 0; i < ar.Length; i++)
            {
                for (var j = ar.Length - 1; j > i; j--)
                {
                    if (ar[j] < ar[j - 1])
                    {
                        int buf = ar[j];
                        ar[j] = ar[j - 1];
                        ar[j - 1] = buf;
                    }
                }
            }
            return ar;
        }
    }
}