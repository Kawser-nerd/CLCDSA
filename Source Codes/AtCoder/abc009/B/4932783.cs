using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp111 {
    class Program {
        static void Main(string[] args)
        {
            int inputNum = int.Parse(Console.ReadLine());
            int[] inputPrice = new int[inputNum];
            
            for(int i = 0; i < inputPrice.Length; i++)
            {
                inputPrice[i] = int.Parse(Console.ReadLine());
            }
            int[] prices = inputPrice.OrderByDescending(x => x).Distinct().ToArray();

            Console.WriteLine(prices[1]);
            
        }
    }
}