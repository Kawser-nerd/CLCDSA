using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        string[] cin = Console.ReadLine().Split();
        int a = int.Parse(cin[0]);
        int b = int.Parse(cin[1]);
        string s = Console.ReadLine();

        bool flag = false;
        for (int i = 0; i < s.Length; i++)
        {
            if (i == a && s[i] != '-')
            {
                flag = true;
                break;
            }
            else if (i != a)
            {
                if (s[i] < '0' || '9' < s[i]) flag = true;
            }
        }
        if (flag) Console.WriteLine("No");
        else Console.WriteLine("Yes");
    }
}