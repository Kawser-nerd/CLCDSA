using System;
using System.Linq;
using System.Collections.Generic;

public class Test
{
	public static void Main()
	{
        string[] line = Console.ReadLine().Split(' ');
        int n = int.Parse(line[0]);
        int k = int.Parse(line[1]);

        long ans = k;

        for(int i = 1; i < n ; i++) ans *= k - 1;
        Console.WriteLine(ans);
    }                                                                                                                                                                       
}