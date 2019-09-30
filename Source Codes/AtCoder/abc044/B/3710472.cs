using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram{
    public class Program
    {	
        public static void Main(string[] args)
    	{
            int[] kaisuu = new int[26];
            string s = Console.ReadLine();
            
            for(int i = 0 ; i < s.Length ; i++)
            {
                int a = s[i] - 'a';
                kaisuu[a]++;
            }
            
            bool isGood = true;
            for(int i = 0 ; i < kaisuu.Length; i++)
            {
                if(kaisuu[i] % 2 == 1) isGood = false;
            }
            
            if(isGood) Console.WriteLine("Yes");
            else Console.WriteLine("No");
    	}
    }
}