using System;
using System.Linq;

namespace ABC64_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var a = Console.ReadLine().Split().Select(int.Parse).ToArray();

            var cls = new bool[8];
            var master = 0;
            foreach (var i in a)
            {
                if (i < 400) cls[0] = true;
                else if (i < 800) cls[1] = true;
                else if (i < 1200) cls[2] = true;
                else if (i < 1600) cls[3] = true;
                else if (i < 2000) cls[4] = true;
                else if (i < 2400) cls[5] = true;
                else if (i < 2800) cls[6] = true;
                else if (i < 3200) cls[7] = true;
                else master++;
            }

            var sum = 0;
            for (int i = 0; i < cls.Length; i++)
            {
                if (cls[i]) sum++;
            }

            var min = 0;
            if (sum == 0 && master > 0)
            {
                min = 1;
            }
            else
            {
                min = sum;
            }


            Console.WriteLine(min + " " + (sum + master));


        }
    }
}