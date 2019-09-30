using System;
using System.Collections.Generic;

public class CSharp{
    public static void Main(){
        Kyopuro chokudai = new Kyopuro();
	    chokudai.AtCoder();
	}
}

public class Kyopuro{
    public void AtCoder(){
        string[] s;
		s = Console.ReadLine().Split(' ');
		int n = int.Parse(s[0]);
		int[] l = new int[n];
		int[] r = new int[n];
		for(int i=0; i<n; i++){
		    s = Console.ReadLine().Split(' ');
		    l[i] = int.Parse(s[0]);
		    r[i] = int.Parse(s[1]);
		}
		bool[] f = new bool[n];
		
		int[] x = new int[n];
		for(int i=0; i<n; i++) x[i] = r[i];
		int[] ordx = new int[n];
		for(int i=0; i<n; i++){
		    ordx[i] = i;
		}
		Array.Sort(x, ordx);
		int[] y = new int[n];
		for(int i=0; i<n; i++) y[i] = l[i];
		int[] ordy = new int[n];
		for(int i=0; i<n; i++){
		    ordy[i] = i;
		}
		Array.Sort(y, ordy);
		
		long ans0 = 0;
		int ix = 0;
		int iy = n - 1;
		int p = 0;
		bool skip = false;
		while(!skip){
		    skip = true;
		    if(ix<n && x[ix] < p){
		        skip = false;
		        ans0 += Math.Abs(p - x[ix]);
		        p = x[ix];
		        ix++;
		    }
		    if(iy>-1 && y[iy] > p){
		        skip = false;
		        ans0 += Math.Abs(p - y[iy]);
		        p = y[iy];
		        iy--;
		    }
		}
        ans0 += Math.Abs(p);
        
		long ans1 = 0;
		ix = 0;
		iy = n - 1;
		p = 0;
		skip = false;
		f = new bool[n];
		while(!skip){
		    skip = true;
		    if(iy>-1 && y[iy] > p){
		        skip = false;
		        ans1 += Math.Abs(p - y[iy]);
		        p = y[iy];
		        iy--;
		    }
		    if(ix<n && x[ix] < p){
		        skip = false;
		        ans1 += Math.Abs(p - x[ix]);
		        p = x[ix];
		        ix++;
		    }
		}
		ans1 += Math.Abs(p);
		
		Console.WriteLine(Math.Max(ans0, ans1));
    }
    
    public static void DebugWL(object x){ System.Diagnostics.Debug.WriteLine(x); }
}