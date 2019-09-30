using System;
using System.Linq;
namespace ABC144_C
{
    class Program
    {
        static long N;
        static void Main(string[] args)
        {
            N = long.Parse(Console.ReadLine());
            Console.WriteLine(Dfs("0"));
        }

        static long Dfs(string s){
            long ret = 0;

            if(long.Parse(s) > N){
                return 0L;
            }
            if(s.Contains("3") && s.Contains("5") && s.Contains("7")){
                ret = 1;
            }
            foreach(var i in new char[]{'3','5','7'}){
                ret += Dfs(s + i);
            }

            return ret;
        }
    }
}