using System;
using System.Collections.Generic;

namespace AtCoderBegginerContest121
{
    class Program
    {
        static void Main(string[] args)
        {
            var inptNM = Console.ReadLine().Split(' ');
            int N = int.Parse(inptNM[0]);
            int M = int.Parse(inptNM[1]);

            List<EneDri> EneDriList= new List<EneDri> { };

            for(int i = 0; i < N; i++)
            {
                var inpt = Console.ReadLine().Split(' ');
                EneDriList.Add(new EneDri(Int64.Parse(inpt[0]), Int64.Parse(inpt[1])));
            }
            EneDriList.Sort((a,b) => (int)(a.Price - b.Price));

            long stockSum = 0;
            long priceSum = 0;

            foreach(EneDri enedri in EneDriList)
            {
                if (stockSum + enedri.Stock < M)
                {
                    priceSum = priceSum + enedri.Price * enedri.Stock;
                    stockSum = stockSum + enedri.Stock;
                }
                else{
                    priceSum = priceSum + enedri.Price * (M - stockSum);
                    break;
                }
            }
            Console.Write(priceSum);
        }
    }
    class EneDri { 
        public long Price { get; set; }
        public long Stock { get; set; }
        public EneDri(long price,long stock)
        {
            this.Price = price;
            this.Stock = stock;
        }
    }
}