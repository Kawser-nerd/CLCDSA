using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class MyProgram
{	

    public static void Main()
	{
	    int[] n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        int N = n[0];
        n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        
        bool can = true;
        int max = 0;
        int cnt = 0;
        for(int i = 0 ; i < N ; i++)
        {
            //cnt = 0;
            can = true;
            while(can)
            {
                if(n[i] % 2 ==0)
                {
                    n[i] /= 2;
                    cnt++;
                }
                else
                {
                    can = false;
                }
            }
          
        }
        Console.WriteLine(cnt);
	}
}