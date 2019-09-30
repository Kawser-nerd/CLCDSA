using System;
using System.Linq;
class Program
{
    public static void Main()
    {
        string s = Console.ReadLine();
        char[] s2 = new char[s.Length];
        for (int i = 0; i < s.Length; i++)
            s2[i] = s[i];
        Console.WriteLine("{0} {1} {2} {3} {4} {5}", s2.Count(a => a == 'A'), s2.Count(a => a == 'B'), s2.Count(a => a == 'C'),
            s2.Count(a => a == 'D'), s2.Count(a => a == 'E'), s2.Count(a => a == 'F'));
    }
}