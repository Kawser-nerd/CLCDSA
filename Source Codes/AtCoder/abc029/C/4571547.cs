using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    static string Cnv(int i)
    {
        Stack<int> s = new Stack<int>();
        do
        {
            s.Push(i % 3);
            i = (i - (i % 3)) / 3;
        } while (i != 0);
        string str = "";
        while (s.Count > 0)
            str += (char)(s.Pop() + '0');
        return str;
    }

    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        int t = 1;
        for (int i = 0; i < N; i++)
            t *= 3;

        for (int i = 0; i < t; i++)
        {
            var f = Cnv(i);
            f=f.PadLeft(N,'0');
            f=f.Replace('0', 'a');
            f=f.Replace('1', 'b');
            f=f.Replace('2', 'c');
            Console.WriteLine(f);
        }
    }
}