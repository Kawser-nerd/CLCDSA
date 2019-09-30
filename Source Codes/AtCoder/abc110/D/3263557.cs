using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;
using System.Diagnostics;
using System.Globalization;
using static System.Console;
using static System.Math;

namespace abc110_d
{
    class Program
    {
        static long mod = 1000000007;
        static void Main(string[] args)
        {
            int[] input = ReadLine().Split().Select(int.Parse).ToArray();
            int N = input[0];
            int M = input[1];
            int m = M;
            long ans = 1;
            for (int i = 2; i*i <= m; i++){
                if(m % i == 0){
                    int cnt=0;
                    while(m % i == 0){
                        cnt++; m /= i;
                    }
                    ans *= calcComb(N+cnt-1, cnt);
                    ans %= mod;
                }
            }
            if (m != 1) {
	            ans *= calcComb(N, N-1);
	            ans %= mod;
	        }
            WriteLine(ans);
        }

        static long modpow(long a, long p){
          if (p == 0) return 1;
          if (p % 2 == 0) {
            int halfP = (int)p/2;
            long half = modpow(a, halfP);
            return half * half % mod;
          } else {
            return a * modpow(a, p-1) % mod;
          }
        }

        static long calcComb(int a, int b){
            if(b > a-b) return calcComb(a, a-b);

            long ansMul = 1;
	        long ansDiv = 1;

            for (int i = 0; i < b; i++)
            {
                ansMul *= (a-i);
                ansDiv *= (i+1);
                ansMul %= mod;
                ansDiv %= mod;
            }

            long ans = ansMul * modpow(ansDiv, mod-2) % mod;
            return ans;

        }
    }
}