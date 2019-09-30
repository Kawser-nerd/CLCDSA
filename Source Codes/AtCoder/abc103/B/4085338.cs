using System;
using System.Web;
using System.IO;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using static System.Math;
 

class P
{
    static void Main()
    {
        string s = Console.ReadLine();
        string t = Console.ReadLine();
        for (int i = 0; i < s.Length; i++)
        {
            t = t.Last() + t.Substring(0, s.Length - 1);
            if(s == t)
            {
                Console.WriteLine("Yes");
                return;
            }
        }
        Console.WriteLine("No");
    }
}