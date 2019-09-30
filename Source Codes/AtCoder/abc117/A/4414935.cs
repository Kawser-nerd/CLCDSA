using System;
using System.Linq;

namespace EnEx
{
    class Program
    {
        public static void Main(string[] args)
        {
            double remnat;
            double oput;
            double[] tNumber = Console.ReadLine().Split().Select(double.Parse).ToArray();

            // 2.6666666667
            // 2.6666666666666665
            // 26666666666.766663
            // 2.6666666667666665
            // 2.6666666667
            var ans = tNumber[0] / tNumber[1];

            if (ans > 0.0)
            {
                var n = ans * 10000000000;
                // 1?????????
                remnat = n % 1;
                if (remnat !=0)
                {
                    var deci = 1 - remnat;

                    oput = (n + deci) / 10000000000;
                    Console.Write(oput);
                }
                else
                {
                    if (n > 0.0)
                    {
                        // 990000000000
                        // 0.0100000000
                        // 0.0100000000
                        oput = (n / 10000000000);
                       var strOput = string.Format("{0:0.0000000000}",oput);
                        Console.Write(strOput);
                    }
                }

            }

        }
    }
}