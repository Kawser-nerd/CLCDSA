using System;

namespace Practice0203
{
    class Program
    {
        static void Main(string[] args)
        {
            var Input = Console.ReadLine().Split(' ');
            var Deg = double.Parse(Input[0]) / 10;
            var Dis = double.Parse(Input[1]) / 60;
            string direction = "";
            int power = 0;
            Dis = Math.Round(Dis * 10, MidpointRounding.AwayFromZero);

            if (11.25 <= Deg && Deg < 33.75)
                direction = "NNE";
            else if (33.75 <= Deg && Deg < 56.25)
                direction = "NE";
            else if (56.25 <= Deg && Deg < 78.75)
                direction = "ENE";
            else if (78.75 <= Deg && Deg < 101.25)
                direction = "E";
            else if (101.25 <= Deg && Deg < 123.75)
                direction = "ESE";
            else if (123.75 <= Deg && Deg < 146.25)
                direction = "SE";
            else if (146.25 <= Deg && Deg < 168.75)
                direction = "SSE";
            else if (168.75 <= Deg && Deg < 191.25)
                direction = "S";
            else if (191.25 <= Deg && Deg < 213.75)
                direction = "SSW";
            else if (213.75 <= Deg && Deg < 236.25)
                direction = "SW";
            else if (236.25 <= Deg && Deg < 258.75)
                direction = "WSW";
            else if (258.75 <= Deg && Deg < 281.25)
                direction = "W";
            else if (281.25 <= Deg && Deg < 303.75)
                direction = "WNW";
            else if (303.75 <= Deg && Deg < 326.25)
                direction = "NW";
            else if (326.25 <= Deg && Deg < 348.75)
                direction = "NNW";
            else 
                direction = "N";

            if (0 <= Dis && Dis <= 2)
            {
                power = 0;
            }
            else if (3 <= Dis && Dis <= 15)
            {
                power = 1;
            }
            else if (16 <= Dis && Dis <= 33)
            {
                power = 2;
            }
            else if (34 <= Dis && Dis <= 54)
            {
                power = 3;
            }
            else if (55 <= Dis && Dis <= 79)
            {
                power = 4;
            }
            else if (80 <= Dis && Dis <= 107)
            {
                power = 5;
            }
            else if (108 <= Dis && Dis <= 138)
            {
                power = 6;
            }
            else if (139 <= Dis && Dis <= 171)
            {
                power = 7;
            }
            else if (172 <= Dis && Dis <= 207)
            {
                power = 8;
            }
            else if (208 <= Dis && Dis <= 244)
            {
                power = 9;
            }
            else if (245 <= Dis && Dis <= 284)
            {
                power = 10;
            }
            else if (285 <= Dis && Dis <= 326)
            {
                power = 11;
            }
            else
            {
                power = 12;
            }

            if (power == 0)
                direction = "C";
            Console.WriteLine("{0} {1}", direction, power);
        }
    }
}