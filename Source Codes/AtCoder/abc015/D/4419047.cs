using System;
using System.Linq;
using System.Collections.Generic;

namespace Hello_World
{
    class Program
    {
        static void Main(string[] args){
           var W = int.Parse(Console.ReadLine());
           var s = Console.ReadLine().Split(' ');
           var N = int.Parse(s[0]);
           var K = int.Parse(s[1]);
           var A = new int[51];
           var B = new int[51];
           var dp = new int[51,10001,51];
           for(int i=0; i<N; i++){
                s = Console.ReadLine().Split(' ');
                A[i] = int.Parse(s[0]);
                B[i] = int.Parse(s[1]);
           }
           for(int i=0; i<N; i++){
               for(int j=0; j<=W; j++){
                   for(int k=0; k<=K; k++){
                       if(j<A[i] || k-1<0){
                           dp[i+1,j,k]=dp[i,j,k];
                       }else{
                           dp[i+1,j,k]=Math.Max(dp[i,j,k],dp[i,j-A[i],k-1]+B[i]);
                       }
                   }
               }
           }
           Console.WriteLine(dp[N,W,K]);
        }
    }   
}