using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace CodeJam
{
    public struct Chest
    {
        public int RequiredKey;
        public int[] Keys;
        public bool Opened;

        public Chest(int requiredKey, int[] keys)
        {
            RequiredKey = requiredKey;
            Keys = keys;
            Opened = false;
        }
    }

    class Treasure
    {
        static void Main(string[] args)
        {
            using (TextReader input = new StreamReader("input.txt"))
            using (TextWriter output = new StreamWriter("output.txt"))
            //using (TextReader input = new StreamReader(Console.OpenStandardInput()))
            //using (TextWriter output = new StreamWriter(Console.OpenStandardOutput()))
            {
                Process(input, output);
            }
        }

        private static void Process(TextReader input, TextWriter output)
        {
            int numberOfCases = int.Parse(input.ReadLine());
            for (int currentCase = 0; currentCase < numberOfCases; currentCase++)
            {
                output.Write("Case #" + (currentCase + 1).ToString() + ": ");
                ProcessLine(input, output);
            }
        }

        private static void ProcessLine(TextReader input, TextWriter output)
        {
            int[] kn = ReadIntsLine(input);
            int numberOfKeys = kn[0];
            int numberOfChests = kn[1];
            int[] startKeys = ReadIntsLine(input);
            Chest[] chests = new Chest[numberOfChests];
            int[] availableKeys = new int[201];
            int[] requiredKeys = new int[201];
            for (int index = 0; index < numberOfChests; index++)
            {
                int[] chestInfo = ReadIntsLine(input);
                int[] keysInChest = new int[chestInfo.Length - 2];
                Array.Copy(chestInfo, 2, keysInChest, 0, chestInfo.Length - 2); 
                for (int keyIndex = 0; keyIndex < chestInfo.Length - 2; keyIndex++)
                {
                    availableKeys[keysInChest[keyIndex]]++;
                }
                chests[index] = new Chest(chestInfo[0], keysInChest);
                requiredKeys[chestInfo[0]]++;
            }
            for (int keyIndex = 0; keyIndex < startKeys.Length; keyIndex++)
            {
                availableKeys[startKeys[keyIndex]]++;
            }
            for (int index = 0; index < 201; index++)
            {
                if (requiredKeys[index] > availableKeys[index])
                {
                    output.WriteLine("IMPOSSIBLE");
                    return;
                }
            }
            int[] haveKeys = new int[201];
            for (int index = 0; index < numberOfKeys; index++)
            {
                haveKeys[startKeys[index]]++;
            }
            int[] openOrder = new int[numberOfChests];
            if (!OpenAChest(0, openOrder, haveKeys, chests))
            {
                output.WriteLine("IMPOSSIBLE");
            }
            else
            {
                for (int index = 0; index < numberOfChests; index++)
                {
                    output.Write(openOrder[index].ToString());
                    if (index < numberOfChests - 1)
                    {
                        output.Write(" ");
                    }
                }
                output.WriteLine();
            }
        }

        private static bool OpenAChest(int position, int[] openOrder, int[] haveKeys, Chest[] chests)
        {
            if (position == chests.Length)
            {
                return true;
            }
            if (!CheckPossible(haveKeys, chests))
            {
                return false;
            }
            for (int index = 0; index < chests.Length; index++)
            {
                if (!chests[index].Opened && haveKeys[chests[index].RequiredKey] > 0)
                {
                    int[] newHaveKeys = haveKeys.Clone() as int[];
                    Chest[] newChests = chests.Clone() as Chest[];
                    newHaveKeys[chests[index].RequiredKey]--;
                    newChests[index].Opened = true;
                    int[] addKeys = newChests[index].Keys;
                    for (int keyIndex = 0; keyIndex < addKeys.Length; keyIndex++)
                    {
                        newHaveKeys[addKeys[keyIndex]]++;
                    }
                    if (OpenAChest(position + 1, openOrder, newHaveKeys, newChests))
                    {
                        openOrder[position] = index + 1;
                        return true;
                    }
                }
            }
            return false;
        }

        private static bool CheckPossible(int[] haveKeys, Chest[] chests)
        {
            int[] availableKeys = haveKeys.Clone() as int[];
            int[] requiredKeys = new int[201];
            for (int index = 0; index < chests.Length; index++)
            {
                if (!chests[index].Opened)
                {
                    int[] chestKeys = chests[index].Keys;
                    requiredKeys[chests[index].RequiredKey]++;
                    for (int keyIndex = 0; keyIndex < chestKeys.Length; keyIndex++)
                    {
                        availableKeys[chestKeys[keyIndex]]++;
                    }
                }
            }
            for (int index = 0; index < 201; index++)
            {
                if (requiredKeys[index] > availableKeys[index])
                {
                    return false;
                }
            }
            for (int index = 0; index < chests.Length; index++)
            {
                if (!chests[index].Opened)
                {
                    int[] chestKeys = chests[index].Keys;
                    if (chestKeys.Contains(chests[index].RequiredKey))
                    {
                        if (availableKeys[chests[index].RequiredKey] == 1)
                        {
                            return false;
                        }
                        int count = 0;
                        for (int keyIndex = 0; keyIndex < chestKeys.Length; keyIndex++)
                        {
                            if (chestKeys[keyIndex] == chests[index].RequiredKey)
                            {
                                count++;
                            }
                        }
                        if (availableKeys[chests[index].RequiredKey] == count)
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }

        private static int[] ReadIntsLine(TextReader input)
        {
            string[] numbers = input.ReadLine().Split(' ');
            int[] result = new int[numbers.Length];
            for (int index = 0; index < numbers.Length; index++)
            {
                result[index] = int.Parse(numbers[index]);
            }
            return result;
        }

    }
}
