using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    static Dictionary<char, char> conversion;
    static Dictionary<char, char> reverseconversion;
    static string Conversion(string s)
    {
        string str = "";
        for (int i = 0; i < s.Length; i++)
            str += conversion[s[i]];
        return str;
    }
    static string ReverseConversion(string s)
    {
        string str = "";
        for (int i = 0; i < s.Length; i++)
            str += reverseconversion[s[i]];
        return str;
    }
    public static void Main()
    {
        string var = Console.ReadLine();
        conversion = new Dictionary<char, char>();
        reverseconversion = new Dictionary<char, char>();
        for (int i = 0; i < 10; i++)
        {
            conversion.Add(var[2 * i], (char)(i + '0'));
            reverseconversion.Add((char)(i + '0'), var[2 * i]);
        }
        int N = int.Parse(Console.ReadLine());

        List<int> L = new List<int>() { Capacity = N };

        for (int i = 0; i < N; i++)
            L.Add(int.Parse(Conversion(Console.ReadLine())));
        L.Sort();
        foreach (var i in L)
            Console.WriteLine(ReverseConversion(i.ToString()));
    }
}