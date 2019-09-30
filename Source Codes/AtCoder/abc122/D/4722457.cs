using System;
using System.Collections.Generic;
class Program
    {
        static int name2num(string s)
        {
            int ret = 0;
            foreach (char c in s)
            {
                ret *= 4;
                ret += "ATCG".IndexOf(c);
            }
            return ret;
        }
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int A = 0, T = 1, C = 2, G = 3;
            long[] arr = new long[64];
            arr[name2num("TTT")] = 1;
            for (int i=0; i<n; i++)
            {
               long[] buf = new long[64];
               for (int j=0; j<64; j++)
               {
                   if (j%16 == name2num("AAG"))
                   {
                       foreach(char c in "ATG") buf[name2num("AG" + c.ToString())] += arr[j]; 
                   }
                   else if (j%16 == name2num("AAC"))
                   {
                       foreach(char c in "ATC") buf[name2num("AT" + c.ToString())] += arr[j];
                   }
                   else if (j%16 == name2num("AGA"))
                   {
                       foreach(char c in "ATG") buf[name2num("GA" + c.ToString())] += arr[j];
                   }
                   else if (j/16 == A && j%4 == G)
                   {
                       foreach(char c in "ATG") buf[j*4%64 + name2num(c.ToString())] += arr[j]; 
                   }
                   else if (j/4 == name2num("AG"))
                   {
                       foreach(char c in "ATG") buf[j*4%64 + name2num(c.ToString())] += arr[j]; 
                   }
                   else
                   {
                       foreach(char c in "ATGC") buf[j*4%64 + name2num(c.ToString())] += arr[j];
                   }
               }
               arr = buf;
               for (int j=0; j<64; j++) buf[j] = buf[j] % 1000000007;
            }
            long ans = 0;
            foreach (long i in arr) ans = (ans + i) % 1000000007;
            Console.WriteLine(ans);
        }
    }
    //mcs Main.cs
    //mono Main.exe