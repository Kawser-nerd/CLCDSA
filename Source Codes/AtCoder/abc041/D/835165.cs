using System;

class Program{
    static void Main(string[] args){
        string[] str = Console.ReadLine().Split(' ');
        int N = int.Parse(str[0]), M = int.Parse(str[1]);
        
        int[] path = new int[N];
        for(long i=0;i<M;i++){
            str =  Console.ReadLine().Split(' ');
            int x = int.Parse(str[0])-1, y = int.Parse(str[1])-1;
            path[y] |= (1 << x);
        }
        
        long[] dp= new long[1<<N];
        dp[0] = 1;
        for(int S=0;S<(1<<N);S++){
            for(int i=0;i<N;i++){
                int b = 1<<i;
                if((b&S)==0 && (path[i]&S)==0) dp[S|b] += dp[S];
            }
        }
        Console.WriteLine(dp[(1<<N)-1]);
    }
}