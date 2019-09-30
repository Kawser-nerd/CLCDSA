using System;
using System.Linq;
using System.Collections.Generic;

public class Test
{
	public static void Main()
	{
        string[] line = Console.ReadLine().Split(' ');
        int n = int.Parse(line[0]);
        int m = int.Parse(line[1]);
        int cnt = 0;

        int[] brigde = new int[n];
        
        string[] youbou = new string[2];
        int[] a = new int[m];
        int[] b = new int[m];

        for(int i = 0 ; i < m ; i++){
            youbou = Console.ReadLine().Split(' ');
            a[i] = int.Parse(youbou[0]);
            b[i] = int.Parse(youbou[1]);
        }

        Array.Sort(b,a);
        int c = 0;        
        for(int i = 0 ; i < m ; i++){
            if(a[i] < c){
            } else {
                brigde[b[i]-1] = 1;
                c = b[i];
            }
        }

        cnt = brigde.Sum();
        Console.WriteLine(cnt);
    }                                                                                                                                   
}