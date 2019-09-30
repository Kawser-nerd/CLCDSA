using System;
using System.Collections.Generic;
class Program
    {
    	static void Main(string[] args)
    	{
    		string s = Console.ReadLine();
            List<char> usable = new List<char>();
            for(int i=0; i<26; i++) usable.Add((char)('a' + i));
            foreach(char c in s) usable.Remove(c);
            if (usable.Count > 0) Console.WriteLine(s + usable[0].ToString());
            else{
                int i = 25;
                while(true)
                {
                    usable.Add(s[i]);
                    usable.Sort();
                    foreach(char c in usable){
                        if (s[i - 1] < c) {
                            Console.WriteLine(s.Substring(0, i - 1) + c.ToString());
                            return;
                        } 
                    }
                    
                    i--;
                    if (i == 0) {
                        Console.WriteLine(-1);
                        break;
                    }
                }
            }
        }
    }
    //mcs Main.cs
    //mono Main.exe