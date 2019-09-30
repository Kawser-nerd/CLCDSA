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
        long[] p = new long[62];
        p[0] = 1;
        for(int i=1; i<62; i++) p[i] = p[i-1] * 2;
        long a = long.Parse(Console.ReadLine());
        long b = long.Parse(Console.ReadLine());
        if(a == b) {
            Console.WriteLine(1);
            return;
        }
        long la = 0; long lb = 0;
        int ia = 0; while(p[ia] <= a) ia++;
        int ib = 0; while(p[ib] <= b) ib++;
        la = p[--ia];
        lb = p[--ib];
        while(la == lb){
            if(a == la) break;
            a -= la;
            b -= lb;
            while(p[ia] > a) ia--;
            while(p[ib] > b) ib--;
            la = p[ia]; lb = p[ib];
        }
        long c = b - lb;
        long lc = 0;
        if(c != 0){
            lc = (long)Math.Pow(2,1+(long)Math.Log(c, 2)) - 1;
        }
        Console.WriteLine(lb-a+1+Math.Min(lc + lb - a, lb-1));
    }
    
    public static void DebugWL(object x){ System.Diagnostics.Debug.WriteLine(x); }
}