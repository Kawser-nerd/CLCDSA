using System;
using System.Linq;
using System.Collections.Generic;

namespace Hello_World
{
    class Program
    {
        static private bool mask(int mask, int r){
            return (mask & 1<<r) != 0 ? true : false;  
        }
        static void Main(string[] args)
        {
            string S = Console.ReadLine();
            int n = S.Length-1;
            long sum=0;
            for(int i=0; i<(1<<n); i++){
                long temp=0;
                int l=0;
                int r=0;
                for(r=0; r<S.Length; r++){
                    if(mask(i, r)){
                        long add = long.Parse(S.Substring(l,r-l+1));
                        temp += add;
                        l=r+1;
                    }
                }
                temp += long.Parse(S.Substring(l));
                sum += temp;
            }
            Console.WriteLine(sum);
        }
    }
}