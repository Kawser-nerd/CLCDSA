using System;
using System.Collections.Generic;
using System.Text;

namespace codeajm2010
{
    class SnapperChain
    {
        private static string solve(int N,int k)
        {
            ++k;
            int p =Convert.ToInt32(Math.Pow(2, N));
            if( k/p*p==k){
                return "ON";
            }else{
                return "OFF";
            }
        }
        public static void Main(string[] args)
        {
            int cases = Convert.ToInt32(System.Console.In.ReadLine().Trim());
            for (int i = 0; i < cases; i++) {
                string s = System.Console.In.ReadLine();
                string[] v = s.Split(' ');
                int n = Convert.ToInt32(v[0].Trim());
                int k = Convert.ToInt32(v[1].Trim());
                System.Console.Out.WriteLine(string.Format("Case #{0}: {1}", i + 1, solve(n, k)));
            }
        }
    }
}
