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
           for(int i=N-1; i>=0; i--){
               for(int j=0; j<=W; j++){
                   for(int k=K-1; k>=0; k--){
                       if(j<A[i]){
                           dp[i,j,k]=dp[i+1,j,k];
                       }else{
                           dp[i,j,k]=Math.Max(dp[i+1,j,k],dp[i+1,j-A[i],k+1]+B[i]);
                       }
                   }
               }
           }
           Console.WriteLine(dp[0,W,0]);
        }
    }   
}