using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    static string Conversion(string s)
    {
        string str = "";
        for (int i = 0; i < s.Length; i++)
        {
            char f = s[i];
            if ('A' <= f && f <= 'Z')
                f = (char)((f - 'A') + 'a');

            if (f == 'b' || f == 'c')
                str += '1';
            else if (f == 'd' || f == 'w')
                str += '2';
            else if (f == 't' || f == 'j')
                str += '3';
            else if (f == 'f' || f == 'q')
                str += '4';
            else if (f == 'l' || f == 'v')
                str += '5';
            else if (f == 's' || f == 'x')
                str += '6';
            else if (f == 'p' || f == 'm')
                str += '7';
            else if (f == 'h' || f == 'k')
                str += '8';
            else if (f == 'n' || f == 'g')
                str += '9';
            else if (f == 'z' || f == 'r')
                str += '0';
        }
        return str;
    }
    public static void Main()
    {
        Console.ReadLine();
        string[] str = Console.ReadLine().Split(' ');
        LinkedList<string> q = new LinkedList<string>();
        foreach (var i in str)
            q.AddLast(Conversion(i));
        string s = "";

        while (q.Remove("")) ;

        var t = q.First;

        while (true)
        {
            if (t == null)
                break;
            s += t.Value;
            t = t.Next;
            if (t != null)
                s += ' ';
        }
        Console.WriteLine(s);
    }
}