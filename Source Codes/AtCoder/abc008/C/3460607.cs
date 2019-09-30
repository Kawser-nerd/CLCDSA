using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace tes2
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] coin = new int[n];

            for(int i =0;i<n;i++)
            {
                coin[i] = int.Parse(Console.ReadLine());
            }

            coin = coin.OrderBy(x => x).ToArray(); //?????
            float answer = 0.0f;?//??


            for(int i = 0; i < coin.Count();i++)
            {
                float div = 0.0f; //????
                float rate; //??????

                div = coin
                    .Select((x,y) => new { item = x, index = y})
                    .Where(c => coin[i] % c.item == 0 && i != c.index)
                    .Count();

                rate = div % 2 == 1 ? 1f / 2f : (div + 2) / (2 * div + 2);

                answer += rate;
            }

            Console.WriteLine(answer);
        }
        
    }
}