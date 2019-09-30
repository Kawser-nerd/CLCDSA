using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemC
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader(@"D:\temp\CodeJam\ProblemC\Inputs\C-small-attempt0.in"))
            {
                using (StreamWriter writer = new StreamWriter(@"D:\Temp\CodeJam\ProblemC\Outputs\C-small-attempt0.out"))
                {
                    int inputCount = Convert.ToInt32(reader.ReadLine());

                    for (int i = 0; i < inputCount; i++)
                    {
                        string[] integersStrings = reader.ReadLine().Split(' ');
                        int N = Convert.ToInt32(integersStrings[0]);
                        int L = Convert.ToInt32(integersStrings[1]);
                        int H = Convert.ToInt32(integersStrings[2]);

                        int[] frequencies = new int[N];
                        string[] frequenciesStrings = reader.ReadLine().Split(' ');
                        for (int j = 0; j < N; j++)
                        {
                            frequencies[j] = Convert.ToInt32(frequenciesStrings[j]);
                        }

                        bool harmonicWithAll = false;
                        int frequency = -1;
                        for (frequency = L; frequency <= H; frequency++)
                        {
                            harmonicWithAll = true;
                            for (int k = 0; k < N; k++)
                            {
                                if (((frequencies[k] % frequency) != 0) && ((frequency % frequencies[k]) != 0))
                                {
                                    harmonicWithAll = false;
                                    break;
                                }
                            }

                            if (harmonicWithAll)
                                break;
                        }

                        if (harmonicWithAll)
                        {
                            writer.WriteLine("Case #" + (i + 1).ToString() + ": " + frequency);
                        }
                        else
                        {
                            writer.WriteLine("Case #" + (i + 1).ToString() + ": " + "NO");
                        }
                        
                    }
                }
            }
        }
    }
}
