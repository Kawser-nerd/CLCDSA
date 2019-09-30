using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KenshuContestA
{
    class Program
    {
        public static string Solve()
        {
            // ?????
            string eins = "1";
            string zwei = "2";
            string drei = "3";
            string vier = "4";

            // ???????
            string pCount = Console.ReadLine();
            string ansList = Console.ReadLine();

            // 1?4??????
            int[] count = { CountQuest(eins, ansList), CountQuest(zwei, ansList), CountQuest(drei, ansList), CountQuest(vier, ansList) };

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