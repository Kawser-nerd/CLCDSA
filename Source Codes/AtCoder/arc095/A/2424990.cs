using System;
using System.Collections.Generic;

namespace ARC095_C
{
    class Program
    {
        static void Main(string[] args)
        {
            string inputStr;
            // N???
            inputStr = Console.ReadLine();
            var N = UInt64.Parse(inputStr.Trim());

            // X???
            inputStr = Console.ReadLine();
            var X = new List<UInt64>();
            foreach (var dat in inputStr.Trim().Split())
            {
                X.Add(UInt64.Parse(dat));
            }

            // ???????2?????
            var X2 = new List<UInt64>(X);
            X2.Sort();
            var mid1 = X2[(int)(X2.Count / 2) - 1];
            var mid2 = X2[(int)(X2.Count / 2)];

            // ???????????????
            for (var i=0; i<X2.Count; i++)
            {
                if (X[i] > mid1) Console.WriteLine(mid1);
                else Console.WriteLine(mid2);
            }
#if DEBUG
            Console.ReadLine();
#endif
        }
    }
}