using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace ManageYourEnergy
{
    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            StreamReader sr = new StreamReader("D:\\B-small-attempt1.in");
            StreamWriter sw = new StreamWriter("D:\\B-small-attempt1.out");

            //StreamReader sr = new StreamReader("D:\\B-large.in");
            //StreamWriter sw = new StreamWriter("D:\\B-large.out");

            int numTestCases = Convert.ToInt32(sr.ReadLine());


            for (int i = 0; i < numTestCases; i++)
            {
                Console.WriteLine(i);

                string[] str = sr.ReadLine().Split(' ');

                int maximumEnergy = Convert.ToInt32(str[0]);
                int energyRegained = Convert.ToInt32(str[1]);
                int numActivities = Convert.ToInt32(str[2]);

                str = sr.ReadLine().Split(' ');

                int[] activityValues = new int[numActivities + 1];

                for (int j = 1; j <= numActivities; j++)
                {
                    activityValues[j] = Convert.ToInt32(str[j - 1]);
                }


                int[,] Opt = new int[numActivities + 1, maximumEnergy + 1];

                for (int k = 0; k < maximumEnergy + 1; k++)
                {
                    Opt[numActivities, k] = 0;
                }

                for (int j = numActivities - 1; j >= 0; j--)
                {
                    for (int k = 0; k <= maximumEnergy; k++)
                    {
                        int max = 0;
                        for (int energyUsed = 0; energyUsed <= k; energyUsed++)
                        {
                            int newEnergy = k - energyUsed + energyRegained;
                            if (newEnergy > maximumEnergy) newEnergy = maximumEnergy;

                            int opt = Opt[j + 1, newEnergy] + activityValues[j + 1] * energyUsed;

                            if (opt > max) max = opt;
                        }

                        Opt[j, k] = max;
                    }
                }

                
                sw.Write("Case #{0}: ", i + 1);
                sw.Write(Opt[0, maximumEnergy]);
                sw.WriteLine();

            }
            sw.Close();
        }
    }
}
