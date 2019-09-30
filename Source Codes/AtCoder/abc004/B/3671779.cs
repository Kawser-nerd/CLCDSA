using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{   
        string[] s = new string[4];
        for(int i = 0; i < s.Length ; i++)
        {
              s[i] = Console.ReadLine().Replace(" ", "");
        }
        for(int i = 3; i >= 0 ; i--)
        {
            string s2 = s[i];
            for(int j = 3; j >= 0 ; j--)
            {
                Console.Write(s2[j]);
                if(j>0) Console.Write(" ");                
            }
            Console.WriteLine();
        }
        
	}
}