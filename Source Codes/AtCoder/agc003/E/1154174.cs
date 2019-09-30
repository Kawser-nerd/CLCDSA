using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    public Solve(){}
    StringBuilder sb;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        int N;
        long[] Q;
        long[] V;
        long[] C;
        {
            string[] str = Console.ReadLine().Split(' ');
            long[] stack = new long[int.Parse(str[1])+1];
            int p = 1;
            N = int.Parse(str[0]);
            stack[0] = N;
            for (int i=0;i<int.Parse(str[1]);i++){
                long q = long.Parse(Console.ReadLine());
                while(p > 0 && stack[p-1] >= q){
                    p--;
                }
                stack[p] = q;
                p++;
            }
            Q = new long[p];
            Array.Copy(stack,0,Q,0,p);
        }
        int N2 = (int)Q[0];
        int l = Q.Length+N2-1;
        V = new long[l];
        C = new long[l];
        C[l-1] = 1;
        for(int i=0;i<N2;i++){
            V[i] = i+1;
        }
        for(int i=N2;i<l;i++){
            V[i] = Q[i-N2+1];
        }
        for(int i=l-1;i>=N2;i--){
            if(C[i] != 0){
                long v = V[i];
                C[i-1] += v/V[i-1]*C[i];
                v %= V[i-1];
                int p = i-2;
                while(v > N2){
                    int f = 0;
                    int t = p;
                    while(f != t){
                        int c = (f+t+1)/2;
                        if(v >= V[c]){
                            f = c;
                        }
                        else{
                            t = c-1;
                        }
                    }
                    C[f] += v/V[f]*C[i];
                    v %= V[f];
                    p = f-1;
                }
                if(v != 0){
                    C[v-1] += C[i];
                }
            }
        }
        long count = 0;
        for(int i=0;i<N2;i++){
            count += C[i];
        }
        for(int i=0;i<N2;i++){
            sb.Append(count+"\n");
            count -= C[i];
        }
        for(int i=N2;i<N;i++){
            sb.Append("0\n");
        }
    }
}