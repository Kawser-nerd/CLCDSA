using System;
using System.Collections.Generic;
using System.Linq;

namespace at
{
    class Program
    {
        static void Main(string[] args)
        {
            string ditstr;
            string windstr;
            string[] str = Console.ReadLine().Split(' ');
            double dir = double.Parse(str[0]);
            double dis = double.Parse(str[1]);

            if(dir>=1687.5 && dir<1912.5)
            {
                ditstr = "S";
            }
            else if(dir>=1912.5 && dir<2137.5)
            {
                ditstr = "SSW";
            }
            else if(dir>=2132.5 && dir<2362.5)
            {
                ditstr = "SW";
            }
            else if(dir>=2587.5 && dir<2812.5)
            {
                ditstr = "W";
            }
            else if(dir>=2812.5 && dir<3037.5)
            {
                ditstr = "WNW";
            }
            else if(dir>=3037.5 && dir<3262.5)
            {
                ditstr = "NW";
            }
            else if(dir>=3262.5 && dir<3487.5)
            {
                ditstr = "NNW";
            }
            else if(dir>=112.5 && dir<337.5)
            {
                ditstr = "NNE";
            }
            else if(dir>=337.5 && dir<562.5)
            {
                ditstr = "NE";
            }
            else if(dir>=562.5 && dir<787.5)
            {
                ditstr = "ENE";
            }
            else if(dir>=787.5 && dir<1012.5)
            {
                ditstr = "E";
            }
            else if(dir>=1012.5 && dir<1237.5)
            {
                ditstr = "ESE";
            }
            else if(dir>=1237.5 && dir<1462.5)
            {
                ditstr = "SE";
            }
            else if(dir>=1462.5 && dir<1687.5)
            {
                ditstr = "SSE";
            }
            else if(dir>=2362.5 && dir<2587.5)
            {
                ditstr = "WSW";
            }
            else
            {
                ditstr = "N";
            }

            
            double wind1 = dis/60;
            string s = wind1.ToString("F1");
            double wind = double.Parse(s);


            if(wind<=0.2)
            {
                windstr = "0";
            }
            else if(wind>=0.3 && wind<=1.5)
            {
                windstr = "1";
            }
            else if(wind>=1.6 && wind<=3.3)
            {
                windstr = "2";
            }
            else if(wind>=3.4 && wind<=5.4)
            {
                windstr = "3";
            }
            else if(wind>=5.5 && wind<=7.9)
            {
                windstr = "4";
            }
            else if(wind>=8 && wind<=10.7)
            {
                windstr = "5";
            }
            else if(wind>=10.8 && wind<=13.8)
            {
                windstr = "6";
            }
            else if(wind>=13.9 && wind<=17.1)
            {
                windstr = "7";
            }
            else if(wind>=17.2 && wind<=20.7)
            {
                windstr = "8";
            }
            else if(wind>=20.8 && wind<=24.4)
            {
                windstr = "9";
            }
            else if(wind>=24.5 && wind<=28.4)
            {
                windstr = "10";
            }
            else if(wind>=28.5 && wind<=32.6)
            {
                windstr = "11";
            }
            else
            {
                windstr = "12";
            }

            if(windstr=="0")
            {
                Console.WriteLine("C 0");
            }
            else
            {
                Console.WriteLine(ditstr+" "+windstr);
            }
        }
    }
}