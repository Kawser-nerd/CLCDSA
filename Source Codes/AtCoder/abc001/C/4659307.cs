using System;
using System.Linq;

namespace BegginerContest_001_C
{
    class Program
    {
        static string Direction(double deg)
        {
            string direction = string.Empty;
            if (11.25 <= deg && deg < 33.75) direction = "NNE";
            else if (33.75 <= deg && deg < 56.25) direction = "NE";
            else if (56.25 <= deg && deg < 78.75) direction = "ENE";
            else if (78.75 <= deg && deg < 101.25) direction = "E";
            else if (101.25 <= deg && deg < 123.75) direction = "ESE";
            else if (123.75 <= deg && deg < 146.25) direction = "SE";
            else if (146.25 <= deg && deg < 168.75) direction = "SSE";
            else if (168.75 <= deg && deg < 191.25) direction = "S";
            else if (191.25 <= deg && deg < 213.75) direction = "SSW";
            else if (213.75 <= deg && deg < 236.25) direction = "SW";
            else if (236.25 <= deg && deg < 258.75) direction = "WSW";
            else if (258.75 <= deg && deg < 281.25) direction = "W";
            else if (281.25 <= deg && deg < 303.75) direction = "WNW";
            else if (303.75 <= deg && deg < 326.25) direction = "NW";
            else if (326.25 <= deg && deg < 348.75) direction = "NNW";
            else direction = "N";
            return direction;
        }

        static int Wind(double dis)
        {
            int wind = 0;
            if (0.0 <= dis && dis <= 0.2) wind = 0;
            else if (0.3 <= dis && dis <= 1.5) wind = 1;
            else if (1.6 <= dis && dis <= 3.3) wind = 2;
            else if (3.4 <= dis && dis <= 5.4) wind = 3;
            else if (5.5 <= dis && dis <= 7.9) wind = 4;
            else if (8.0 <= dis && dis <= 10.7) wind = 5;
            else if (10.8 <= dis && dis <= 13.8) wind = 6;
            else if (13.9 <= dis && dis <= 17.1) wind = 7;
            else if (17.2 <= dis && dis <= 20.7) wind = 8;
            else if (20.8 <= dis && dis <= 24.4) wind = 9;
            else if (24.5 <= dis && dis <= 28.4) wind = 10;
            else if (28.5 <= dis && dis <= 32.6) wind = 11;
            else wind = 12;
            return wind;
        }

        static void Main(string[] args)
        {
            double[] input = Console.ReadLine().Split(' ').Select(Double.Parse).ToArray();
            double deg = input[0] / 10;
            double dis = Math.Round(input[1] / 60, 1, MidpointRounding.AwayFromZero);

            Console.WriteLine("{0} {1}", Wind(dis) == 0 ? "C" : Direction(deg), Wind(dis));
        }
    }
}