using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] three = new int[] { 1, 3, 9, 27, 81, 243, 729, 2187, 6561 };
        int n = int.Parse(Console.ReadLine());
        for (int i = 0; i < three[n]; i++)
        {
            int p = i;
            for (int j = n - 1; j >= 0; j--)
            {
                Console.Write(char.ConvertFromUtf32('a' + p / three[j]));
                p = p % three[j];
            }
            Console.WriteLine();
        }
    }
}