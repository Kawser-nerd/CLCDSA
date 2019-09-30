using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace AtCoder
{
    public class Code6
    {
        static void Main(string[] args)
        {
            string s1 = Console.ReadLine();
 
            Console.WriteLine(funcMain(s1));
        }
 
        static public string funcMain(string arg1)
        {
            string[] s = arg1.Split();
            int N, M;
            int ret = 0;
 
            N = int.Parse(s[0]);
            M = int.Parse(s[1]);
 
            var OnceTime = (N - M) * 100 + M * 1900;
            var Times = (int)Math.Pow(2,M);
            ret = OnceTime * Times;
 
            return ret.ToString();
        }
    }
}