using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram
{
    public class Program
    {	
        public static void Main(string[] args)
        {
            string s = Console.ReadLine();
            string ss = s.Substring(1,s.Length-2);
            Console.WriteLine(s[0]+""+ss.Length+""+s[s.Length-1]);
        }
    }
}