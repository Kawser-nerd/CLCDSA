using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var p = new Program();
            p.Solve();
        }

        void Solve()
        {
            int[] input= Console.ReadLine().Split().Select(int.Parse).ToArray();
            int diff = input[0] - input[1];
            int ans = GetAns(diff);
            Console.WriteLine(ans);
        }

        private int GetAns(int num)
        {
            if (num == 0)
                return 0;
            int ans = 0;
            int x = Math.Abs(num);
            while (true)
            {
                if (x < 10)
                    break;

                x -= 10;
                ans++;
            }

            switch (x)
            {
                case 1:
                case 5:
                    ans++;
                    break;
                case 2:
                case 4:
                case 6:
                case 9:
                    ans += 2;
                    break;
                case 3:
                case 7:
                case 8:
                    ans += 3;
                    break;
                    
                default:
                    break;
            }
            return ans;
        }


    }
}