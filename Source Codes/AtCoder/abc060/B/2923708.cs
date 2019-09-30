using System;
using System.Linq;
using System.Collections.Generic;

public class Test
{
	public static void Main()
	{
        string[] line = Console.ReadLine().Split(' ');
        int a = int.Parse(line[0]);
        int b = int.Parse(line[1]);
        int x = int.Parse(line[2]);

        bool can = false;

        for(int i = a ; i < 10000 ; i += a){
            if(i % b == x){
                can = true;
            }
        }

        if(can){
            Console.WriteLine("YES");
        } else {
            Console.WriteLine("NO");
        }
    }                                                                                                                                                                       
}