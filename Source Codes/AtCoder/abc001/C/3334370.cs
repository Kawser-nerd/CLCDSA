using System;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ???????
            string input = Console.ReadLine();

            // ??????????
            int deg = int.Parse(input.Split(' ')[0]);
            int dis = int.Parse(input.Split(' ')[1]);

            // ??
            double fuko = deg / 10.0;
            // ??
            double fusoku = Math.Round(dis / 60.0, 1, MidpointRounding.AwayFromZero);

            // ??
            string direction = string.Empty;
            // ??
            int windPower = 0;

            // ??????
            // ??
            // ??0
            if(fusoku >= 0.0 && fusoku <= 0.2)
            {
                windPower = 0;
            }
            // ??1
            else if(fusoku >= 0.3 && fusoku <= 1.5)
            {
                windPower = 1;
            }
            // ??2
            else if (fusoku >= 1.6 && fusoku <= 3.3)
            {
                windPower = 2;
            }
            // ??3
            else if (fusoku >= 3.4 && fusoku <= 5.4)
            {
                windPower = 3;
            }
            // ??4
            else if (fusoku >= 5.5 && fusoku <= 7.9)
            {
                windPower = 4;
            }
            // ??5
            else if (fusoku >= 8.0 && fusoku <= 10.7)
            {
                windPower = 5;
            }
            // ??6
            else if (fusoku >= 10.8 && fusoku <= 13.8)
            {
                windPower = 6;
            }
            // ??7
            else if (fusoku >= 13.9 && fusoku <= 17.1)
            {
                windPower = 7;
            }
            // ??8
            else if (fusoku >= 17.2 && fusoku <= 20.7)
            {
                windPower = 8;
            }
            // ??9
            else if (fusoku >= 20.8 && fusoku <= 24.4)
            {
                windPower = 9;
            }
            // ??10
            else if (fusoku >= 24.5 && fusoku <= 28.4)
            {
                windPower = 10;
            }
            // ??11
            else if (fusoku >= 28.5 && fusoku <= 32.6)
            {
                windPower = 11;
            }
            // ??12
            else if (fusoku >= 32.7)
            {
                windPower = 12;
            }

            // ????
            // ??0????C
            if(windPower == 0)
            {
                direction = "C";
            }
            // NNE?????
            else if (fuko >= 11.25 && fuko < 33.75)
            {
                direction = "NNE";
            }
            // NE????
            else if(fuko >= 33.75 && fuko < 56.25)
            {
                direction = "NE";
            }
            // ENE?????
            else if(fuko >= 56.25 && fuko < 78.75)
            {
                direction = "ENE";
            }
            // E???
            else if(fuko >= 78.75 && fuko < 101.25)
            {
                direction = "E";
            }
            // ESE?????
            else if(fuko >= 101.25 && fuko < 123.75)
            {
                direction = "ESE";
            }
            // SE????
            else if(fuko >= 123.75 && fuko < 146.25)
            {
                direction = "SE";
            }
            // SSE?????
            else if(fuko >= 146.25 && fuko < 168.75)
            {
                direction = "SSE";
            }
            // S???
            else if(fuko >= 168.75 && fuko < 191.25)
            {
                direction = "S";
            }
            // SSW?????
            else if(fuko >= 191.25 && fuko < 213.75)
            {
                direction = "SSW";
            }
            // SW????
            else if(fuko >= 213.75 && fuko < 236.25)
            {
                direction = "SW";
            }
            // WSW?????
            else if(fuko >= 236.25 && fuko < 258.75)
            {
                direction = "WSW";
            }
            // W???
            else if(fuko >= 258.75 && fuko < 281.25)
            {
                direction = "W";
            }
            // WNW?????
            else if(fuko >= 281.25 && fuko < 303.75)
            {
                direction = "WNW";
            }
            // NW????
            else if(fuko >= 303.75 && fuko < 326.25)
            {
                direction = "NW";
            }
            // NNW?????
            else if(fuko >= 326.25 && fuko < 348.75)
            {
                direction = "NNW";
            }
            // N???
            else
            {
                direction = "N";
            }

            // ???????
            Console.WriteLine(direction + " " + windPower);
        }
    }
}