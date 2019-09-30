using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class MyProgram
{	
    static int min = 999999999;
    static int G = 0;
    static int D = 0;
    static int[] Q = new int[10];
    static int[] B = new int[10];
    
    public static void Main()
	{
	    int[] n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
	    D = n[0];
	    G = n[1];
	    
	    for(int i = 0 ; i < D ; i++)
	    {
	        n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
	        Q[i] = n[0];
	        B[i] = n[1];
	    }
	    string ss = "";
	    tansaku(ss);
	    Console.WriteLine(min);
	}
	
	public static void tansaku(string s)
	{
	    if(s.Length == D)
	    {
	        keisan(s);
	    }
	    else
	    {
	        tansaku(s+"1");
	        tansaku(s+"0");
	    }
	}
	
	public static void keisan(string s)
	{
	    char[] c = s.ToCharArray();
	    int cnt = 0;
	    int a = 0;
	    
	    for(int i = 0 ; i < D ; i++)
	    {
	        if(c[i] == '1')
	        {
	            a += (Q[i] * (i+1) * 100 ) + B[i];
	            cnt += Q[i];
	        }
	    }
	    
	    for(int i = D-1 ; i >= 0 ; i--)
	    {
	        if(c[i] == '0')
	        {
	            int aa = 0;
	            while(G > a && aa < Q[i])
	            {
	                a += ((i+1) * 100);
	                aa ++;
	                cnt++;
	            }
	            break;
	        }
	    }
	    if(min > cnt && G <= a)
	    {
	        min = cnt;
	    }
	}
}