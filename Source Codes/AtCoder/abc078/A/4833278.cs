using System;
using System.Collections.Generic;
class Program
    {
    	static void Main(string[] args)
    	{
            string s = Console.ReadLine();
            if (s[0] < s[2]) Console.WriteLine("<");
            else if (s[0] == s[2]) Console.WriteLine("=");
            else Console.WriteLine(">");
        }
    }
    //mcs Main.cs
    //mono Main.exe