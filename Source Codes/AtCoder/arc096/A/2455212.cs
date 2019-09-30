using System;
namespace AtCoder.ARC096
{
    public class ARC096A
    {
        public static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int priceA = int.Parse(input[0]);
            int priceB = int.Parse(input[1]);
            int priceC = int.Parse(input[2]);
            int requiredA = int.Parse(input[3]);
            int requiredB = int.Parse(input[4]);

            int max = Math.Max(requiredA, requiredB);
            int min = GetPrice(priceA, priceB, priceC, requiredA, requiredB, 0);
            int price = 0;
            int numA = 0, numB = 0;
            for (int numC = 0; numC <= max * 2; numC += 2)
            {
                numA = Math.Max(requiredA - numC / 2, 0);
                numB = Math.Max(requiredB - numC / 2, 0);
                price = GetPrice(priceA, priceB, priceC, numA, numB, numC);
                if (price < min)
                {
                    min = price;
                }
            }
            Console.WriteLine(min);
        }

        private static int GetPrice(int priceA, int priceB, int priceC, int numA, int numB, int numC)
        {
            return priceA * numA + priceB * numB + priceC * numC;
        }
    }
}