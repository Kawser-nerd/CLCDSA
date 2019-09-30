using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        Console.ReadLine();
        string s = Console.ReadLine();
        string a = "b";
        if (s == a)
        {
            Console.WriteLine(0);
            return;
        }
        for (int i = 1; s.Length > a.Length; i++)
        {
            switch (i % 3)
            {
                case 1:
                a = "a" + a + "c";
                break;
                case 2:
                a = "c" + a + "a";
                break;
                case 0:
                a = "b" + a + "b";
                break;
                default:
                break;
            }
            if (s == a)
            {
                Console.WriteLine(i);
                return;
            }
        }
        Console.WriteLine(-1);
    }
}