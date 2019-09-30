using System;
using System.Text;

namespace AtCoder
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var input = Console.ReadLine();
            var inputSplitted = input.Split(' ');
            int A = int.Parse(inputSplitted[0]);
            int B = int.Parse(inputSplitted[1]);

            int diff = B - A;
            if (diff < 0) { diff = -diff; }

            if (diff == 0)
            {
                Console.WriteLine(0);
                return;
            }

            int cnt = 0;
            while (diff >= 3)
            {
                int diff_10 = diff - 10;
                int diff_05 = diff - 5;
                if (diff_10 < 0) { diff_10 = -diff_10; }

                if (diff_10 < diff_05)
                {
                    diff = diff_10;
                }
                else
                {
                    diff = diff_05;
                }
                cnt++;
            }
            cnt += Math.Abs(diff);

            Console.WriteLine(cnt);
        }
    }
}