using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Beg122D
{
    class Program
    {
        public static int N,mod;
        public static Dictionary<Tuple<string, int>, int> memo;
        static void Main(string[] args)
        {
            N = int.Parse(Console.ReadLine());
            mod = 1000000000 + 7;
            memo = new Dictionary<Tuple<string, int>, int>();
            Console.WriteLine(dfs(0, "TTT"));


        }
        public static int dfs(int cur, string last3)
        {
            var pair = new Tuple<string, int>(last3, cur);
            if (memo.Keys.Contains(pair))
                return memo[pair];
            var ret = 0;
            if (cur == N)
                return 1;
            foreach(var c in "AGCT")
            {
                if (strOK(last3 + c))
                    ret = (ret + dfs(cur + 1, last3.Substring(1) + c)) % mod;
            }
            memo.Add(new Tuple<string, int>(last3, cur), ret);
            return ret;
        }
        public static bool strOK(string last4)
        {
            if (last4.Contains("AGC"))
                return false;
            for(int i=0;i<3;i++)
            {
                var last4Array = last4.ToArray();
                last4Array[i] = last4.ElementAt(i + 1);
                last4Array[i + 1] = last4.ElementAt(i);
                var converted = new String(last4Array);
                if (converted.Contains("AGC"))
                    return false;
            }
            return true;
        }
        
    }
}