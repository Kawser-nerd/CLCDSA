using System;
using System.Linq;
using System.Collections.Generic;

public class Test
{
	public static void Main()
	{
        string[] line = Console.ReadLine().Split(' ');
        long a = long.Parse(line[0]);
        long b = long.Parse(line[1]);
        long x = long.Parse(line[2]);

        long min;
        if(a == 0){
            min = -1;
        } else {
            min = (a - 1) / x;
        }    

        long max = b / x;

        Console.WriteLine(max - min);
    }                                                                                                                                                                       
}