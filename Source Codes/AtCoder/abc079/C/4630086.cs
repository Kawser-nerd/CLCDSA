using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        List<int> abcd = Console.ReadLine().ToCharArray().Select((c) => int.Parse(c.ToString())).ToList();

        for(byte i = 0; i < 8; i++) //000~111
        {
            bool[] pm =
            {
                ((i & 1) == 1),
                ((i & 2) == 2),
                ((i & 4) == 4),
            };
            int culc = abcd[0] + (pm[0] ? 1 : -1) * abcd[1] + (pm[1] ? 1 : -1) * abcd[2] + (pm[2] ? 1 : -1) * abcd[3];
            if(culc == 7)
            {
                string ans = "";
                for(int j = 0; j < 4; j++)
                {
                    ans += abcd[j];
                    if (j < 3) ans += (pm[j]) ? "+" : "-";
                }
                ans += "=7";
                Console.WriteLine(ans);
                return;
            }
        }
    }
}