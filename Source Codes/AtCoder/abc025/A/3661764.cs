using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
       char[] c = Console.ReadLine().ToCharArray();
       int n = int.Parse(Console.ReadLine());
       int cnt = 0;
       
       for(int i = 0 ; i < c.Length ; i++)
       {
           for(int j = 0 ; j < c.Length ; j++)
           {
               cnt++;
               if(cnt == n) Console.WriteLine(c[i]+""+c[j]);
           }
       }
    }
}