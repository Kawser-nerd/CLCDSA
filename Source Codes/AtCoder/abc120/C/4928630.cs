using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC120C
{
    class MainClass
    {

        static int[] s;
        static int[] n;

        public static void Main(string[] args)
        {

            string str = Console.ReadLine();
            int cnt = 0;
            int l = str.Length;
            for (int i = 0; i < l; i++)
            {
                if (str[i] == '1')
                {
                    cnt++;
                }
            }
            cnt = Math.Min(cnt, l - cnt);
            int ans = cnt * 2;
            Console.WriteLine(ans);


        }
    }
}