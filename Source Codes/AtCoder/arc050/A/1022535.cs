using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;

class Magatro
{
    const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string abc = "abcdefghijklmnopqrstuvwxyz";
    static void Main()
    {
        char[] C = Console.ReadLine().Where(c => c != ' ').ToArray();
        for(int i = 0; i < 26; i++)
        {
            if (abc[i] == C[1] && ABC[i] == C[0])
            {
                Console.WriteLine("Yes");
                return;
            }
        }
        Console.WriteLine("No");
    }
   
}