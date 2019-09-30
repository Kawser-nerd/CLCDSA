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
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]);
            int b = int.Parse(input[1]);
            
            int cnt = 0;
            for(int i = a ; i <= b ; i++)
            {
                if(Check(i)) cnt++;
            }
            Console.WriteLine(cnt);
        }
        public static bool Check(int target)
        {
            string s = target.ToString();
            char[] c = s.ToCharArray();
            
            string s2 = "";
            for(int i = s.Length-1; i >= 0 ;i--)
            {
                s2 += c[i];
            }

            if(s == s2) return true;
            else return false;
        }
    }
}