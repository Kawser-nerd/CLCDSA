using System;
using System.Text;

namespace AtCoder
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            // ??????

            var N = int.Parse(Console.ReadLine());
            var answers = Console.ReadLine();

            var seikai = new int[4];
            for (int i = 0; i < answers.Length; ++i)
            {
                int index = ( answers[i] - 0x0030 ) - 1;
                ++seikai[index];
            }

            int seikaiMin = int.MaxValue;
            int seikaiMax = int.MinValue;
            for (int i = 0; i < seikai.Length; ++i)
            {
                if (seikai[i] < seikaiMin) { seikaiMin = seikai[i]; }
                if (seikai[i] > seikaiMax) { seikaiMax = seikai[i]; }
            }

            Console.WriteLine( seikaiMax + " " + seikaiMin );
        }
    }
}