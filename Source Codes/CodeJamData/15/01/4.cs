using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2015_0_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var parts = Console.ReadLine().Split();
                var clapperCount = 0;
                var addedFriends = 0;
                var shynessLevel = 0;
                foreach (var digit in parts[1])
                {
                    var n = (int)(digit - '0');
                    if (clapperCount < shynessLevel)
                    {
                        var delta = shynessLevel - clapperCount;
                        clapperCount += delta;
                        addedFriends += delta;
                    }
                    clapperCount += n;
                    shynessLevel++;
                }
                Console.WriteLine("Case #{0}: {1}", testN, addedFriends);
            }
        }
    }
}
