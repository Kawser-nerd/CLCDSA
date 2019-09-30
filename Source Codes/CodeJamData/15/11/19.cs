using System;
using System.IO;

class A
{
    public void Solve()
    {
        StreamReader reader = new StreamReader("A_in.txt");
        StreamWriter writer = new StreamWriter("A_out.txt");

        int T = Int32.Parse(reader.ReadLine());

        for (int t = 0; t < T; t++)
        {
            // Load the info
            int N = Int32.Parse(reader.ReadLine());

            int[] mushrooms = new int[N];
            string[] input = reader.ReadLine().Split();
            for (int n = 0; n < N; n++)
            {
                mushrooms[n] = Int32.Parse(input[n]);
            }

            // First pass: count the first case
            int answer1 = 0;
            for (int i = 1; i < N; i++)
            {
                if (mushrooms[i] < mushrooms[i - 1]) answer1 += mushrooms[i - 1] - mushrooms[i];
            }

            // Second pass: work out the max eating rate
            int rate = 0;
            for (int i = 1; i < N; i++)
            {
                if (mushrooms[i] < mushrooms[i - 1]) rate = Math.Max(rate, mushrooms[i - 1] - mushrooms[i]);
            }

            // Third pass: count mushrooms eaten
            int answer2 = 0;
            for (int i = 1; i < N; i++)
            {
                int eatenThisInterval = rate;
                int mushroomsAtStart = mushrooms[i - 1];
                answer2 += Math.Min(rate, mushroomsAtStart);
            }

            string answer = String.Format("Case #{0}: {1} {2}", (t + 1), answer1, answer2);
            writer.WriteLine(answer);
            Console.WriteLine(answer);
        }

        reader.Close();
        writer.Close();
    }
}

