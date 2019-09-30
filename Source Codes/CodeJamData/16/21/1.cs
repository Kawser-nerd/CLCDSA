using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;



class Program
{

    static void Main(string[] args)
    {


        int[] Int1 = new int[] { 0, 2, 4, 6, 8 };
        String[] Num1 = new string[] { "ZERO", "TWO", "FOUR", "SIX", "EIGHT" };
        Char[] Char1 = new char[] { 'Z', 'W', 'U', 'X', 'G' };
        int[] Int2 = new int[] { 1, 3, 5, 7, 9 };
        String[] Num2 = new string[] { "ONE", "THREE", "FIVE", "SEVEN", "NINE" };
        Char[] Char2 = new char[] { 'O', 'R', 'F', 'S', 'I' };




        StreamReader sr = new StreamReader("D:\\in.in");
        StreamWriter sw = new StreamWriter("D:\\out.out");
        sw.AutoFlush = true;
        int n = int.Parse(sr.ReadLine());
        Console.WriteLine(n);
        for (int i = 0; i < n; i++)
        {
            sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solution(sr));
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }



    static void X(int[] Int1, string[] Num1, Char[] Char1, List<int> res, int[] N)
    {
        for (int i = 0; i < 5; i++)
        {
            while (N[Char1[i] - 'A'] > 0)
            {
                res.Add(Int1[i]);

                foreach (var c in Num1[i])
                {
                    N[c - 'A']--;
                }
            }
        }
    }

    static string Solution(StreamReader sr)
    {
        int[] Int1 = new int[] { 0, 2, 4, 6, 8 };
        String[] Num1 = new string[] { "ZERO", "TWO", "FOUR", "SIX", "EIGHT" };
        Char[] Char1 = new char[] { 'Z', 'W', 'U', 'X', 'G' };
        int[] Int2 = new int[] { 1, 3, 5, 7, 9 };
        String[] Num2 = new string[] { "ONE", "THREE", "FIVE", "SEVEN", "NINE" };
        Char[] Char2 = new char[] { 'O', 'R', 'F', 'S', 'I' };

        string r = "";

        string s = sr.ReadLine();

        int[] N = new int[30];

        foreach (char c in s)
        {
            N[c - 'A']++;
        }

        List<int> res = new List<int>();
        X(Int1, Num1, Char1, res, N);
        X(Int2, Num2, Char2, res, N);

        res.Sort();

        foreach (var i in res)
        {
            r += i.ToString();
        }


        return r;
    }
}