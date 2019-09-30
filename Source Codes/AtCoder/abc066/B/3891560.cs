using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;
using static System.Math;


class P
{
    static void Main()
    {
        string s = Console.ReadLine();
        for (int i = s.Length - 2; i >= 0; i--)
        {
            if(s.Substring(0, i) == s.Substring(0, i / 2) + s.Substring(0, i / 2))
            {
                Console.WriteLine(i);
                return;
            }
        }
    }
}