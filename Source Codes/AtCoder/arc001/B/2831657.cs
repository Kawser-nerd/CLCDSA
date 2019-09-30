using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Program
{
    static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        string s = Console.ReadLine();
        int[] c = new int[n];

        for(int i = 0; i < n; i++)
        {
            c[i] = int.Parse(s[i].ToString());
        }

        int min = n + 1;
        int max = -1;

        for(int j = 1; j <= 4; j++)
        {
            int tmp = 0;
            for(int i = 0; i < n; i++)
            {
                tmp += c[i] == j ? 1 : 0;
            }
            min = Math.Min(min, tmp);
            max = Math.Max(max, tmp);
        }
        Console.WriteLine("{0} {1}", max, min);
    }
}