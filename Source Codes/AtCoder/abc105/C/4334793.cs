using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    { 
        static void Main(string[] args)
        {
            //[summary]C - Base -2 Number
            int n = int.Parse(Console.ReadLine());

            string minus2Str = ConvertBaseNumber(n, -2);
            Console.WriteLine(minus2Str);
        }

        static string ConvertBaseNumber(int sourceNum, int n)
        {
            //[summary]10??????n?????
            //??????????????????????
            //http://manabi.matiralab.com/binary/

            var mods = new List<int>();
            int num = sourceNum;

            //?????"n"?????????????
            while (num != 0 && num != 1)
            {
                if(num <0 && num % n != 0)
                {
                    mods.Add(1);
                    num = (num - 1) / n;
                }
                else
                {
                    mods.Add(num % n);
                    num /= n;
                }                
            }

            mods.Add(num);

            //???????????????
            mods.Reverse();

            //List?????
            return string.Join("", mods);
        }
    }
}