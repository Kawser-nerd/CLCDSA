using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    int N;
    long[] x;
    int M;
    long K;
    int[] a;
    int[] original;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        int[] swap;
        long[] dx = new long[N-1];
        long[] adx = new long[N-1];
        original = new int[N-1];
        for(int i=0;i<N-1;i++){
            original[i] = i;
        }
        for(int i=0;i<M;i++){
            int j = original[a[i]-1];
            original[a[i]-1] = original[a[i]];
            original[a[i]] = j;
        }
        swap = m(K);
        for(int i=0;i<N-1;i++){
            dx[i] = x[i+1]-x[i];
        }
        for(int i=0;i<N-1;i++){
            adx[i] = dx[swap[i]]; 
        }
        StringBuilder sb = new StringBuilder();
        long count = x[0];
        sb.Append(count+"\n");
        for(int i=0;i<N-1;i++){
            count += adx[i];
            sb.Append(count+"\n");
        }
        Console.Write(sb.ToString());
    }
    int[] m(long k){
        if(k <= 1){
            return original;
        }
        else if(k%2 == 0){
            int[] s = m(k/2);
            int[] t = new int[N-1];
            for(int i=0;i<N-1;i++){
                t[i] = s[s[i]];
            }
            return t;
        }
        else{
            int[] s = m(k-1);
            int[] t = new int[N-1];
            for(int i=0;i<N-1;i++){
                t[i] =original[s[i]];
            }
            return t;
        }
    }
    void getinput(){
        N = int.Parse(Console.ReadLine());
        x = new long[N];
        string[] str = Console.ReadLine().Split(' ');
        for(int i=0;i<N;i++){
            x[i] = Int64.Parse(str[i]);
        }
        str = Console.ReadLine().Split(' ');
        M = int.Parse(str[0]);
        K = Int64.Parse(str[1]);
        a = new int[M];
        str = Console.ReadLine().Split(' ');
        for(int i=0;i<M;i++){
            a[i] = int.Parse(str[i])-1;
        }
    }    
}