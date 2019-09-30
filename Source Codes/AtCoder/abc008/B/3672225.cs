using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{   
	    int max = 1;
        int n = int.Parse(Console.ReadLine());
        string[] name = new string[100];
        int[] score = new int[100];
        
        string s;
        for(int i = 0 ; i < n ; i++)
        {
            s = Console.ReadLine();
            if(!name.Contains(s))
            {
                name[i] = s;
                score[i]++;
            }
            else
            {
                int a = Array.IndexOf(name,s);
                score[a]++;
                max = Math.Max(max, score[a]);
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(max == score[i])
            {
                Console.WriteLine(name[i]);
                break;
            }
        }
	}
}