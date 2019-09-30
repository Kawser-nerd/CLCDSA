using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
	    int[] n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        List <int> list = new List<int>();
        list.Add(n[0]+n[1]);
        list.Add(n[0]-n[1]);
        list.Add(n[0]*n[1]);
        list.Sort();
        Console.WriteLine(list[list.Count-1]);
	} 
}