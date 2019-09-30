using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{   
	    List <int> list = new List<int>();
	    int n = int.Parse(Console.ReadLine());
	    int a;
	    for(int i=0 ; i < n ; i++)
	    {
	        a = int.Parse(Console.ReadLine());
	        if(!list.Contains(a)) list.Add(a);
	    }
	    list.Sort();
	    Console.WriteLine(list[list.Count-2]);
	}
}