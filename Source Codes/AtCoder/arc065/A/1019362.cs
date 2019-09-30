using System;
using System.Linq;

namespace ARC065C{
    public class Program{
        public static void Main(string[] args){
            var search = new[]{"dream", "dreamer", "erase", "eraser"};
            var S = Console.ReadLine();

            Func<string, int, bool> isOk = (s, x) =>{
                if(S.Length - x < s.Length) return false;
                var ret = true;
                for(var i = 0; i < s.Length; i++) ret &= S[i + x] == s[i];
                return ret;
            };

            Func<int, bool> dfs = null;
            dfs = x =>{
                if(x == S.Length) return true;
                var ret = false;
                foreach(var s in search) if(isOk(s, x)) ret |= dfs(x + s.Length);
                return ret;
            };

            Console.WriteLine(dfs(0) ? "YES" : "NO");
        }
    }
}