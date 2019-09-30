using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;

class Magatro
{

    static void Main()
    {
        string[] s = Console.ReadLine().Split(' ');
        
        int I = int.Parse(s[0]);
        int J = int.Parse(s[3]);
        int L = int.Parse(s[4]);
        long ansa, ansb;
        ansa = int.Parse(s[1]);
        ansb = int.Parse(s[1]);
        if (I > 0 && J > 0 && L > 0)
        {
            ansa += 3;
            ansa += (I - 1) / 2 * 2;
            ansa += (J - 1) / 2 * 2;
            ansa += (L - 1) / 2 * 2;
        }
        ansb += I / 2 * 2;
        ansb += J / 2 * 2;
        ansb += L / 2 * 2;
        Console.WriteLine(Math.Max(ansa,ansb));
    }
    
}