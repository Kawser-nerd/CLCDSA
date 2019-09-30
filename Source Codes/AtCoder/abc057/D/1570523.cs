using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
public class Simple {
    public static void Main() {new Simple().Solve();}
    int N, A, B;
    long[] v;
    void Solve(){
        //input
        var inp = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        N = inp[0];
        A = inp[1];
        B = inp[2];
        v=Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
        v = v.OrderByDescending(v => v).ToArray();

        //average
        var ave = (double)v.Take(A).Average();

        //patern
        var patern = 0L;
        var Comb = C(50);
        var top = v.First();
        var bot = v[A - 1];
        var usable = v.Where(v => v == bot).Count();
        if(v[0]==v[A-1]){
            for (int i = A; i <= B;i++){
                if (usable < i) break;
                patern += Comb[usable, i];
            }
        }else{
            var use = v.Select((e, i) => new { e, i }).
                       Where(v => v.e == bot && v.i < A).Count();
            patern = Comb[usable, use];
        }

        //res
        Console.WriteLine(ave);
        Console.WriteLine(patern);
    }

    long[,] C(int N) {
        long[,] ret = new long[N + 1, N + 1];
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= i; j++)
                ret[i, j] = (j == 0 || j == i) ? 1L : ret[i - 1, j - 1] + ret[i - 1, j];
        return ret;
    }
    
        
}