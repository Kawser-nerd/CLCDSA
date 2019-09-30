using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp
{ 
    class Program
    {
        static void Main(string[] args)
        {
            int[] cnt = new int[] { 0, 0 };
            string s = Console.ReadLine();
            foreach (char ch in s)
            {
                cnt[ch - '0']++;
            }
            int ans = Math.Min(cnt[0], cnt[1]) * 2;
            Console.WriteLine(ans);
            //Console.ReadLine();
        }
    }
}