using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class AtCodeeeeeeeeeeeeeeeeeeeer
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            string s = Console.ReadLine();
            int ans = 0;
            for (int i = 0; i < s.Length; i++)
            {
                string X = s.Substring(0, i);
                string Y = s.Substring(i, s.Length - i);
                if (Func(X,Y)>ans)
                {
                    ans = Func(X, Y);
                }
            }
            Console.WriteLine(ans);

        }
        static int Func(string x,string y)
        {
            int ans = 0;
            for (char i = 'a'; i <= 'z'; i++)
            {
                if (x.Contains(i)&&y.Contains(i))
                {
                    ans++;
                }
            }
            return ans;
        }
    }
}