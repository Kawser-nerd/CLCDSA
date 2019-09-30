using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        string n = long.Parse(Console.ReadLine()).ToString();
        int res = 0;
        if (n.Length == 1)
        {
            res = n[0] - '0';
        }
        else if (n[0] != '9')
        {
            if (n.Count(x => x != '9') == 1)
            {
                res = 9 * (n.Length - 1) + (n[0] - '0');
            }
            else
            {
                res = 9 * (n.Length - 1) + (n[0] - '0' - 1);
            }
        }
        else if (n.Count(x => x != '9') != 0)
        {
            res = 9 * (n.Length - 1) + 8;
        }
        else
        {
            res = 9 * (n.Length - 1) + 9;
        }
        Console.WriteLine(res);
    }
}