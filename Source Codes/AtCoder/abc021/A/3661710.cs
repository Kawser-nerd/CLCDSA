using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        List<int> list = new List<int>();
        int n = int.Parse(Console.ReadLine());
        string s  = Convert.ToString(n,2);
        int a = 1;
        for(int i = s.Length-1 ; i >= 0 ; i--)
        {
            if(s[i] == '1') list.Add(a);
            a *= 2;
        }
        Console.WriteLine(list.Count);
        for(int i = 0 ; i < list.Count ; i++)
        {
            Console.WriteLine(list[i]);
        }
    }
}