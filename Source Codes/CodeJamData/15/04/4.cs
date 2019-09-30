using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2015_0_D
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var parts = Console.ReadLine().Split().Select(int.Parse).ToList();
                var nominoSize = parts[0];
                var R = parts[1];
                var C = parts[2];
                var victory = true;
                if (nominoSize < 7 && (R * C) % nominoSize == 0)
                {
                    switch (nominoSize)
                    {
                        case 1:
                        case 2:
                            victory = false;
                            break;
                        case 3:
                            if (R > 1 && C > 1)
                                victory = false;
                            break;
                        case 4:
                            if (R > 2 && C > 2 && (R >= 4 || C >= 4))
                                victory = false;
                            break;
                        case 5:
                            if (R > 2 && C > 2 && R * C > 15)
                                victory = false;
                            break;
                        case 6:
                            if ((R >= 6 || C >= 6) && R > 3 && C > 3)
                                victory = false;
                            break;
                    }
                }
                Console.WriteLine("Case #{0}: {1}", testN, victory ? "RICHARD" : "GABRIEL");
            }
        }
    }
}
