using System;
using System.Collections.Generic;
using System.IO;

namespace _2016RoundOneC
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader inputFileReader = new StreamReader(args[0]))
            {
                using (StreamWriter outFileWriter = new StreamWriter("output.txt"))
                {
                    int count = int.Parse(inputFileReader.ReadLine());
                    for (int index = 0; index < count; ++index)
                    {
                        int kidCount = int.Parse(inputFileReader.ReadLine());
                        string[] kidsBffsInput = inputFileReader.ReadLine().Split(' ');

                        int[] kidsBffs = new int[kidCount + 1];
                        for (int index2 = 0; index2 < kidCount; ++index2)
                        {
                            kidsBffs[index2 + 1] = int.Parse(kidsBffsInput[index2]);
                        }

                        int maxSize = 0;
                        for (int index2 = 1; index2 <= kidCount; ++index2)
                        {
                            bool[] kidsAdded = new bool[kidCount + 1];

                            int kidCurrent = index2;
                            kidsAdded[index2] = true;
                            maxSize = Math.Max(maxSize, GetLongestKidChain(index2, 0, index2, kidsAdded, kidsBffs));
                        }

                        outFileWriter.WriteLine("Case #" + (index + 1) + ": " + maxSize);
                    }
                }
            }
        }

        private static int GetLongestKidChain(int firstKid, int previousKidAdded, int kidBeingAdded, bool[] kidsAdded, int[] kidsBffs)
        {
            if (kidsBffs[kidBeingAdded] == previousKidAdded)
            {
                int maxValue = 1;
                for (int index = 1; index < kidsBffs.Length; ++index)
                {
                    if (!kidsAdded[index])
                    {
                        kidsAdded[index] = true;
                        maxValue = Math.Max(maxValue, 1 + GetLongestKidChain(firstKid, kidBeingAdded, index, kidsAdded, kidsBffs));
                        kidsAdded[index] = false;
                    }
                }
                return maxValue;
            }
            else
            {
                int BffOfkidBeingAdded = kidsBffs[kidBeingAdded];
                if (kidsAdded[BffOfkidBeingAdded])
                {
                    if (BffOfkidBeingAdded == firstKid)
                    {
                        return 1;
                    }
                    else
                    {
                        return int.MinValue;
                    }
                }
                else
                {
                    kidsAdded[BffOfkidBeingAdded] = true;
                    int toReturn = 1 + GetLongestKidChain(firstKid, kidBeingAdded, BffOfkidBeingAdded, kidsAdded, kidsBffs);
                    kidsAdded[BffOfkidBeingAdded] = false;
                    return toReturn;
                }
            }
        }
    }
}
