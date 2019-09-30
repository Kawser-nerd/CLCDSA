using System;
using System.Linq;
using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(ReadLine());
        var a = new string[n].Select(_ => ReadLine()).ToArray();
        for (int i = 0; i < n; i++)
        {
            for (int j = n; j > 0; j--)
            {
                Write(a[j - 1][i]);
            }
            WriteLine();
        }
    }
}