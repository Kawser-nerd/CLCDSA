using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ08_1A_C
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] ans = new string[] {
            "-1",
            "005",
            "027",
            "143",
            "751",
            "935",
            "607",
            "903",
            "991",
            "335",
            "047",
            "943",
            "471",
            "055",
            "447",
            "463",
            "991",
            "095",
            "607",
            "263",
            "151",
            "855",
            "527",
            "743",
            "351",
            "135",
            "407",
            "903",
            "791",
            "135",
            "647",
            "343"};
            int T = int.Parse(Console.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                int n = int.Parse(Console.ReadLine());
                Console.WriteLine("Case #{0}: {1}", i, ans[n]);
            }
        }
    }
}
