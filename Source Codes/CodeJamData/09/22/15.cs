using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.IO;


public class Round1A
{

    public static void Main(string[] args)
    {
        DateTime start = DateTime.Now;

        StreamReader sr = new StreamReader(@"C:\Users\yuzou\Documents\TestProgram\CSharpTest\CSharpTest\CSharpTest\in.txt");
        StreamWriter sw = new StreamWriter(@"C:\Users\yuzou\Documents\TestProgram\CSharpTest\CSharpTest\CSharpTest\out.txt");

        string str = sr.ReadLine();
        int tt = int.Parse(str);

        for (int t = 1; t <= tt; t++)
        {
            str = "0" + sr.ReadLine().Trim();
            char[] nums = str.ToCharArray();

            //for (int i = 0; i < nums.Length; i++)
            //{
            //    Console.Write(nums[i]);
            //}
            //Console.WriteLine();

            NextPermutation<char>(nums, 0, nums.Length);

            int i;
            if (nums[0] == '0')
                i = 1;
            else
                i = 0;
            sw.Write("Case #{0}: ", t);
            for (; i < nums.Length; i++)
            {
                sw.Write(nums[i]);
            }
            sw.WriteLine();
            
            
            


        }

        sw.Close();
        DateTime end = DateTime.Now;
        Console.WriteLine(end - start);
    }


    private static void Swap<T>(ref T a, ref T b)
    {
        T tmp = a;
        a = b;
        b = tmp;
    }

    // TEMPLATE FUNCTION Next_Permutation, Class T using IComparable
    private static bool NextPermutation<T>(T[] p, int first, int last) where T : IComparable
    {
        if (last - first <= 1)
        {
            return false;
        }
        int next = last - 1;

        while (true)
        {
            // find rightmost element smaller than successor
            int next1 = next;
            if (p[--next].CompareTo(p[next1]) < 0)
            {
                // swap with rightmost element that's smaller, flip suffix
                int mid = last;
                while (!(p[next].CompareTo(p[--mid]) < 0)) ;

                Swap<T>(ref p[next], ref p[mid]);

                Array.Reverse(p, next1, last - next1);
                return true;
            }
            if (next == first)
            {
                // pure descending, flip all
                Array.Reverse(p, next, last - next);
                return false;
            }
        }
    }

}
