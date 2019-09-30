using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class Test
{	
    public static void Main()
	{
        double[] asp  = Console.ReadLine().Split(' ').Select(s => double.Parse(s)).ToArray();
        double ft = 4.000 / 3.000;
        double sn = 16.000/9.000;
        double aspect = asp[0]/asp[1];

        if(aspect == ft) Console.WriteLine("4:3");
        else Console.WriteLine("16:9");
	}
}