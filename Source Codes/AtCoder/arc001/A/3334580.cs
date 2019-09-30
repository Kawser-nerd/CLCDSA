using System;
using System.Linq;

namespace KenshuContestA
{
    class Program
    {
        public static string Solve()
        {
            // ?????
            string[] num = { "1", "2", "3", "4" };

            // ???????
            string pCount = Console.ReadLine();
            string ansList = Console.ReadLine();

            // 1?4??????
            int[] count = { CountQuest(num[0], ansList), CountQuest(num[1], ansList), CountQuest(num[2], ansList), CountQuest(num[3], ansList) };

            // ????????
            string max = count.Max().ToString();
            string min = count.Min().ToString();


            return max + " " + min;
        }

        // ????????????????
        public static int CountQuest(string num, string ansList)
        {
            int count = 0;
            foreach (var item in ansList)
            {
                int index = num.IndexOf(item, 0);
                while (index != -1)
                {
                    count++;
                    index = num.IndexOf(item, index + item.ToString().Length);
                }
            }
            return count;
        }

        // ??????
        public static void Main(string[] args)
        {
            Console.WriteLine(Solve());
        }
    }
}