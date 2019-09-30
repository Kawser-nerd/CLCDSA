using System;

namespace AtCoderBC113B_Palace
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());

            string[] s = Console.ReadLine().Split(' ');
            int T = int.Parse(s[0]) - int.Parse(s[1]);

            string[] hs = Console.ReadLine().Split(' ');

            float[] Temp = new float[N];

            for (int i = 0; i < N; i++)
            {
                Temp[i] = Math.Abs((float)T - 0.006F * int.Parse(hs[i]));
            }

            int index = 0;
            float min = float.MaxValue;

            for(int i = 0; i < N;i++)
            {
                if(Temp[i] < min)
                {
                    min = Temp[i];
                    index = i + 1;
                }
            }

            Console.WriteLine(index.ToString());
        }
    }
}