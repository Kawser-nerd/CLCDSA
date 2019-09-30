using System;
using System.Collections.Generic;
using System.Linq;
using static System.Math;


namespace hogeeeee
{
    class hogehoge
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            int APlace = -1;
            int ZPlace = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == 'A' && APlace == -1)
                {
                    APlace = i;
                }
                if (s[i] == 'Z')
                {
                    ZPlace = i;
                }
            }
            Console.WriteLine(ZPlace - APlace +1);
        }
    }
}