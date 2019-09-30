using System;


namespace _121_ABC
{
    class Program02
    {
        static void Main(string[] args)
        {
            string[] Input1 = Console.ReadLine().Split(' ');
            int N = int.Parse(Input1[0]);
            int M = int.Parse(Input1[1]);
            int C = int.Parse(Input1[2]);

            string[] Input2 = Console.ReadLine().Split(' ');
            int[] B = new int[M];

            int Ans = 0;

            for(int i = 0; i < Input2.Length; i++)
            {
                B[i] = int.Parse(Input2[i]);
            }

            for (int i = 0; i < N; i++)
            {
                int sum = 0;
                string[] Input3 = Console.ReadLine().Split(' ');

                for (int j = 0; j < M; j++)
                {
                    sum += B[j] * int.Parse(Input3[j]);
                }

                sum += C;

                if(sum > 0)
                {
                    Ans++;
                }
            }

            Console.WriteLine(Ans);

        }
    }
}