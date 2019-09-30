using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class Atcoderrrrrr
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            List<int> s = new List<int>();
            int ans = 0;
            for (int i = 0; i < N; i++)
            {
                int obj = int.Parse(Console.ReadLine());
                if (s.Contains(obj)==false)
                {
                    s.Add(obj);
                    ans++;

                }
            }
            Console.WriteLine(ans);
        }
    }
}