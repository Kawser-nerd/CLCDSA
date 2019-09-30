using System;
using System.Linq;
using System.Collections.Generic;

namespace Hello_World
{
    class Program
    {
        static int W, N, K;
        static int[] A = new int[51], B = new int[51];
        static int[,,] dp = new int[51,10001,51];
        static private int pic(int i, int j, int k){
            if(dp[i,j,k]>=0){
                return dp[i,j,k];
            }
            int res;
            if(i==N || k==K){
                res = 0;
            }else if(j<A[i]){
                res = pic(i+1,j,k);
            }else{
                res = Math.Max(pic(i+1,j,k), pic(i+1,j-A[i],k+1)+B[i]);
            }
            return dp[i,j,k] = res;
        }
        static void Main(string[] args){
           W = int.Parse(Console.ReadLine());
           var s = Console.ReadLine().Split(' ');
           N = int.Parse(s[0]);
           K = int.Parse(s[1]);
           for(int i=0; i<N; i++){
                s = Console.ReadLine().Split(' ');
                A[i] = int.Parse(s[0]);
                B[i] = int.Parse(s[1]);
           }
           for(int i=0; i<=N; i++)for(int j=0; j<=W; j++)for(int k=0; k<K; k++){
               dp[i,j,k]=-1;
           }
           Console.WriteLine(pic(0, W, 0));
        }
    }   
}