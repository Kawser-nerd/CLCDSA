using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class MyProgram
{	

    public static void Main()
	{
        int N = int.Parse(Console.ReadLine());
	    int[] n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        
        long sum = 0;
        foreach(int i in n) sum += i-1;
        
	    Console.WriteLine(sum);
	}
}