using System;
using System.Collections.Generic;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var Houi = new List<string> { "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW" };

            var data = Console.ReadLine().Split(' ');
            var Deg = Convert.ToInt32(data[0]);
            var Dis = Convert.ToInt32(data[1]);

            var FouSoku = Math.Round(Dis / 60.0, 1, MidpointRounding.AwayFromZero);

            var FouRyoku = 0;
            if( 0.0 <= FouSoku && FouSoku <= 0.2) { FouRyoku = 0; }
            else if (0.3 <= FouSoku && FouSoku <= 1.5) { FouRyoku = 1; }
            else if (1.6 <= FouSoku && FouSoku <= 3.3) { FouRyoku = 2; }
            else if (3.4 <= FouSoku && FouSoku <= 5.4) { FouRyoku = 3; }
            else if (5.5 <= FouSoku && FouSoku <= 7.9) { FouRyoku = 4; }
            else if (8.0 <= FouSoku && FouSoku <= 10.7) { FouRyoku = 5; }
            else if (10.8 <= FouSoku && FouSoku <= 13.8) { FouRyoku = 6; }
            else if (13.9 <= FouSoku && FouSoku <= 17.1) { FouRyoku = 7; }
            else if (17.2 <= FouSoku && FouSoku <= 20.7) { FouRyoku = 8; }
            else if (20.8 <= FouSoku && FouSoku <= 24.4) { FouRyoku = 9; }
            else if (24.5 <= FouSoku && FouSoku <= 28.4) { FouRyoku = 10; }
            else if (28.5 <= FouSoku && FouSoku <= 32.6) { FouRyoku = 11; }
            else { FouRyoku = 12; }

            var Hougaku = Houi[0];
            if(FouRyoku == 0)
            {
                Hougaku = "C";
            }
            else
            {
                for (int i = 1; i < Houi.Count; i++)
                {
                    if (-112.5 + 225 * i <= Deg && Deg < 112.5 + 225 * i)
                    {
                        Hougaku = Houi[i];
                        break;
                    }

                }
            }

            Console.WriteLine("{0} {1}", Hougaku, FouRyoku);
        }
    }
}