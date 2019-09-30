using System;
using System.IO;

namespace Manage_your_Energy
{
    class Program
    {
        private static int FullSearch(int index, int currentEnergy, int maxEnergy, int refilEnergy, int[] values)
        {
            if (index >= values.Length) return 0;

            int maxGain = 0;
            for (int i = 0; i <= currentEnergy; i++)
            {
                int tmpEnergy = currentEnergy;

                currentEnergy -= i;
                currentEnergy = Math.Min(maxEnergy, currentEnergy + refilEnergy);
                int gain = i*values[index];

                maxGain = Math.Max(maxGain, gain + FullSearch(index + 1, currentEnergy, maxEnergy, refilEnergy, values));

                currentEnergy = tmpEnergy;
            }

            return maxGain;
        }

        static void Main(string[] args)
        {
            try
            {
                int started = Environment.TickCount;
                string path = @"..\..\..\..\";
                string filenameIn = "B-small-attempt0.in";
                string filenameOut = "B-small-attempt0.out";

                StreamReader sr = new StreamReader(path + filenameIn);
                StreamWriter sw = new StreamWriter(path + filenameOut);

                int testCount = Convert.ToInt32(sr.ReadLine());

                for (int t = 0; t < testCount; t++)
                {
                    string[] splitted = sr.ReadLine().Split(' ');

                    int maxEnergy = Convert.ToInt32(splitted[0]);
                    int refilEnergy = Convert.ToInt32(splitted[1]);
                    int N = Convert.ToInt32(splitted[2]);

                    int[] values = new int[N];
                    splitted = sr.ReadLine().Split(' ');
                    for (int i = 0; i < N; i++)
                    {
                        values[i] = Convert.ToInt32(splitted[i]);
                    }
                    
                    string message = FullSearch(0, maxEnergy, maxEnergy, refilEnergy, values).ToString();
                    sw.WriteLine("Case #{0}: {1}", (t + 1), message);
                }

                sr.Close();
                sw.Close();

                int elapsed = Environment.TickCount - started;
                Console.WriteLine("Time elapsed: " + elapsed);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }

        }
    }
}
