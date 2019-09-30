using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        List<int> list = new List<int>();
        List<int> sort = new List<int>();
        
        for(int i = 0 ; i < 3 ; i++) 
        {
            int n = int.Parse(Console.ReadLine());
            list.Add(n);
            sort.Add(n);
        }
        sort.Sort((a, b) => b - a);
        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                if(list[i] == sort[j]) Console.WriteLine(j+1);
            }
        }
	}
}