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
           for(int i=0; i<=W; i++){
               for(int j=0; j<=K; j++){
                   for(int k=0; k<N; k++){
                       if(i<A[k] || j-1<0){
                           dp[k+1,i,j]=dp[k,i,j];
                       }else{
                           dp[k+1,i,j]=Math.Max(dp[k,i,j],dp[k,i-A[k],j-1]+B[k]);
                       }
                   }
               }
           }
           Console.WriteLine(dp[N,W,K]);
        }
    }   
}