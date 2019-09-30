using System;
using System.Collections.Generic;
class Solve{
    int n;
    long l;
    int q;
    long[] x;
    int[] a;
    int[] b;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        int logx = 1;
        {   
            long i = 1;
            while(i <= x[n-1]){
                i*=2;
                logx++;
            }
        }
        int[,] dp = new int[n,logx];
        for(int i=0;i<n;i++){
            int f = 0;
            int ll = n-1;
            while(f != ll){
                int c = (f+ll+1)/2;
                if(x[c] - x[i] <= l){
                    f = c;
                }
                else{
                    ll = c-1;
                }
            }
            dp[i,0] = f;
        }
        for(int i=1;i<logx;i++){
            for(int j=0;j<n;j++){
                dp[j,i] = dp[dp[j,i-1],i-1];
            }
        }
        for(int i = 0;i<q;i++){
            int sum=1;
            int d = 0;
            int s,t;
            if(a[i]<b[i]){
                s = a[i];
                t = b[i];
            }
            else{
                s = b[i];
                t = a[i];
            }
            while(dp[s,d] < t){
                d++;
            }
            if(d == 0){
                Console.WriteLine(1);
                continue;
            }
            int r = dp[s,d-1];
            for(int ii=0;ii<d-1;ii++){
                sum*=2;
                if(dp[r,d-ii-2] < t){
                    sum++;
                    r = dp[r,d-ii-2];
                }
            }
            if(r<t){
                sum++;
            }
            Console.WriteLine(sum);
        }
    }
    void getinput(){
        n = int.Parse(Console.ReadLine());
        string[] str = Console.ReadLine().Split(' ');
        x = new long[n];
        for(int i=0;i<n;i++){
            x[i] = Int64.Parse(str[i]);
        }
        l = Int64.Parse(Console.ReadLine());
        q = int.Parse(Console.ReadLine());
        a = new int[q];
        b = new int[q];
        for(int i=0;i<q;i++){
            str = Console.ReadLine().Split(' ');
            a[i] = int.Parse(str[0])-1;
            b[i] = int.Parse(str[1])-1;
        }
    }    
}