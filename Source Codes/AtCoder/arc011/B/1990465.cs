using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        Console.ReadLine();
        string[] a = Console.ReadLine().Split();
        List<string> res = new List<string>();
        
        foreach (string s in a)
        {
            string resstr = "";
            foreach (char c in s.ToLower())
            {
                if (c == 'b' || c == 'c') resstr += '1';
                else if (c == 't' || c == 'j') resstr += '3';
                else if (c == 'l' || c == 'v') resstr += '5';
                else if (c == 'p' || c == 'm') resstr += '7';
                else if (c == 'n' || c == 'g') resstr += '9';
                else if (c == 'd' || c == 'w') resstr += '2';
                else if (c == 'f' || c == 'q') resstr += '4';
                else if (c == 's' || c == 'x') resstr += '6';
                else if (c == 'h' || c == 'k') resstr += '8';
                else if (c == 'z' || c == 'r') resstr += '0';
            }
            if (resstr != "") res.Add(resstr);
        }
        Console.WriteLine(string.Join(" ",res));
    }
}