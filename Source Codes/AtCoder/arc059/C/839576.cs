using System;

class Program{
    static void Main(string[] args){
        long M = 1000000007;
        
        string[] str = Console.ReadLine().Split(' ');
        int N = int.Parse(str[0]);
        int C = int.Parse(str[1]);
        str  = Console.ReadLine().Split(' ');
        long[] A = new long[N+1];
        long[] B = new long[N+1];
        for(int i=0;i<N;i++){
            A[i] = long.Parse(str[i]);
        }
        str  = Console.ReadLine().Split(' ');
        for(int i=0;i<N;i++){
            B[i] = long.Parse(str[i]);
        }
        
        int tableSize = 401;
        long[,] table = new long[tableSize,tableSize];
        for(int j=0;j<tableSize;j++){
            table[0,j] = 1;
            for(int i=1;i<tableSize;i++){
                table[i,j] = table[i-1,j] * ((long) j) % M;
            }
        }
        for(int i=0;i<tableSize;i++){
            for(int j=1;j<tableSize;j++){
                table[i,j] += table[i,j-1];
                table[i,j] %= M;
            }
        }
        
        
        
        long[,] dp = new long[N, C+1];
        for(int i=0;i<N;i++){
            for(int j=0;j<C+1;j++){
                dp[i,j] = 0;
            }
        }
        dp[N-1,0]=(table[0,B[N-1]]-table[0,A[N-1]-1])%M;
        for(int j=1;j<C+1;j++){
            dp[N-1,j] = (M+table[j,B[N-1]]-table[j,A[N-1]-1])%M;
        }
        
        for(int i=N-2;i>-1;i--){
            for(int j=0;j<C+1;j++){
                for(int k=0;k<=j;k++){
                    dp[i,j] += ((M+table[k,B[i]]-table[k,A[i]-1]) * dp[i+1,j-k] % M)% M;
                    dp[i,j] %= M;
                }
            }
        }
        Console.WriteLine(dp[0,C]%M);
    }
}