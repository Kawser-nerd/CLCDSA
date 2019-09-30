using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder070_D_NoNeed
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputFirstLine = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            int N = inputFirstLine[0], K = inputFirstLine[1];
            var cards = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();

            Console.WriteLine(new NoNeed().GetNoNeedCardsCount(K, cards));
            //Console.ReadKey();
        }
    }

    class NoNeed
    {
        public int GetNoNeedCardsCount(int target, List<int> cards)
        {
            var orderCards = cards.OrderByDescending(x => x).ToArray();

            int sum = 0, index = -1;

            for (int i = 0; i < orderCards.Length; i++)
            {
                sum += orderCards[i];
                if (sum >= target)
                {
                    sum -= orderCards[i];
                    index = i;
                }
            }

            if (index == -1) return orderCards.Length;

            return orderCards.Length - index - 1;
        }
    }
}