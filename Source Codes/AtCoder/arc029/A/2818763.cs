using System;

namespace ARC029
{
    class A
    {
        static void Main(string[] args)
        {
            var N = ReadInt();
            var ts = new int[N];
            for (int i = 0; i < ts.Length; i++)
                ts[i] = ReadInt();

            if(ts.Length == 1)
            {
                Console.WriteLine(ts[0]);
                return;
            }

            Array.Sort(ts);
            Array.Reverse(ts);

            var tSum1 = ts[0];
            var tSum2 = ts[1];
            for (int i = 2; i < ts.Length; i++)
            {
                if (tSum1 < tSum2) tSum1 += ts[i];
                else tSum2 += ts[i];
            }

            Console.WriteLine(Math.Max(tSum1,tSum2));
        }

        static int ReadInt()
        {
            return int.Parse(Console.ReadLine());
        }
    }
}