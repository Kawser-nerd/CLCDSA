using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace B
{
    class Program
    {
        static int ConvertLetterNumber(char a)
        {
            return (int)a - (int)'a';
        }

        class Train
        {
            public int trainId;

            public int front;
            public int back;

            public bool IsFreeTrain() { return front == back; }
        }

        static ulong ModedPermCount(ulong a)
        {
            if (a <= 1)
            {
                return 1;
            }
            return ModedMult(a, ModedPermCount(a - 1));
        }

        static ulong ModedMult(ulong a, ulong b)
        {
            return (a * b) % 1000000007;
        }

        static void Main(string[] args)
        {
            using (FileStream fileInputStream = new FileStream("B-large.in", FileMode.Open, FileAccess.Read))
            using (TextReader fileInputReader = new StreamReader(fileInputStream))
            using (FileStream fileOutputStream = new FileStream("output.txt", FileMode.Create, FileAccess.Write))
            using (TextWriter fileOutputWriter = new StreamWriter(fileOutputStream))
            {
                int caseNumber = int.Parse(fileInputReader.ReadLine());

                for (int caseCounter = 1; caseCounter <= caseNumber; ++caseCounter)
                {
                    int n = int.Parse(fileInputReader.ReadLine());
                    string[] trainTokens = fileInputReader.ReadLine().Split(' ');

                    List<List<int>> rawTrains = new List<List<int>>();
                    for (int i = 0; i < n; ++i)
                    {
                        List<int> currentRawTrain = new List<int>();
                        for (int j = 0; j < trainTokens[i].Length; ++j)
                        {
                            currentRawTrain.Add(ConvertLetterNumber(trainTokens[i][j]));
                        }
                        rawTrains.Add(currentRawTrain);
                    }

                    List<Train> trains = new List<Train>();

                    int[] isolatedLetters = new int[26];
                    int[] frontLetters = new int[26];
                    int[] backLetters = new int[26];
                    int[] freeLetters = new int[26];
                    for (int i = 0; i < 26; ++i)
                    {
                        isolatedLetters[i] = 0;
                        frontLetters[i] = 0;
                        backLetters[i] = 0;
                        freeLetters[i] = 0;
                    }

                    bool isImpossible = false;

                    for (int i = 0; i < n; ++i)
                    {
                        List<int> currentRawTrain = rawTrains[i];
                        trains.Add(new Train() { trainId = i, front = currentRawTrain.First(), back = currentRawTrain.Last() });

                        if (currentRawTrain.First() == currentRawTrain.Last())
                        {
                            if (currentRawTrain.Exists(x => x != currentRawTrain.First()))
                            {
                                isImpossible = true;
                                break;
                            }
                            freeLetters[currentRawTrain.First()] += 1;
                        }
                        else
                        {
                            frontLetters[currentRawTrain.First()] += 1;
                            backLetters[currentRawTrain.Last()] += 1;

                            bool isFrontChain = true;
                            int lastChar = currentRawTrain.First();
                            for (int j = 1; j < currentRawTrain.Count - 1; ++j)
                            {
                                if (currentRawTrain[j] == currentRawTrain.First())
                                {
                                    if (isFrontChain)
                                    {
                                        lastChar = currentRawTrain[j];
                                        continue;
                                    }
                                    else
                                    {
                                        isImpossible = true;
                                        break;
                                    }
                                }
                                else if (currentRawTrain[j] == currentRawTrain.Last())
                                {
                                    for (int k = j + 1; k < currentRawTrain.Count; ++k)
                                    {
                                        if (currentRawTrain[k] != currentRawTrain[j])
                                        {
                                            isImpossible = true;
                                            break;
                                        }
                                    }
                                    break;
                                }
                                else
                                {
                                    isFrontChain = false;
                                    if (lastChar != currentRawTrain[j])
                                    {
                                        isolatedLetters[currentRawTrain[j]] += 1;
                                    }
                                    lastChar = currentRawTrain[j];
                                }
                            }
                        }

                        if (isImpossible)
                        {
                            break;
                        }
                    }

                    for (int i = 0; i < 26; ++i)
                    {
                        if (isolatedLetters[i] > 0)
                        {
                            if (isolatedLetters[i] > 1)
                            {
                                isImpossible = true;
                                break;
                            }
                            if (frontLetters[i] > 0 || backLetters[i] > 0 || freeLetters[i] > 0)
                            {
                                isImpossible = true;
                                break;
                            }
                        }
                        if (frontLetters[i] > 1 || backLetters[i] > 1)
                        {
                            isImpossible = true;
                            break;
                        }
                    }

                    if (isImpossible)
                    {
                        fileOutputWriter.WriteLine(string.Format("Case #{0}: 0", caseCounter));
                        continue;
                    }

                    // Collect Free Trains
                    List<Train> nonFreeTrains = new List<Train>();
                    List<Train>[] freeTrains = new List<Train>[26];
                    bool[] isFreeTrainExists = new bool[26];
                    for (int i = 0; i < 26; ++i)
                    {
                        freeTrains[i] = new List<Train>();
                        isFreeTrainExists[i] = false;
                    }
                    foreach (Train currentTrain in trains)
                    {
                        if (currentTrain.IsFreeTrain())
                        {
                            freeTrains[currentTrain.front].Add(currentTrain);
                            isFreeTrainExists[currentTrain.front] = true;
                        }
                        else
                        {
                            nonFreeTrains.Add(currentTrain);
                        }
                    }

                    // Merge Constrainted Trains
                    List<ulong> cyclicMultipliers = new List<ulong>();
                    HashSet<int> collectedTrains = new HashSet<int>();
                    int bunchCount = 0;
                    foreach (Train currentTrain in nonFreeTrains)
                    {
                        if (collectedTrains.Contains(currentTrain.trainId))
                        {
                            continue;
                        }
                        collectedTrains.Add(currentTrain.trainId);
                        ++bunchCount;

                        Train connectedFrontTrain = null;
                        int currentFront = currentTrain.front;
                        ulong cycleLength = 1;
                        bool isCycle = false;
                        do
                        {
                            if (isFreeTrainExists[currentFront])
                            {
                                cycleLength += 1;
                                isFreeTrainExists[currentFront] = false;
                            }
                            connectedFrontTrain = nonFreeTrains.FirstOrDefault(x => x.back == currentFront);
                            if (connectedFrontTrain != null)
                            {
                                if (collectedTrains.Contains(connectedFrontTrain.trainId))
                                {
                                    cyclicMultipliers.Add(cycleLength);
                                    isCycle = true;
                                    break;
                                }
                                cycleLength += 1;
                                collectedTrains.Add(connectedFrontTrain.trainId);
                                currentFront = connectedFrontTrain.front;
                            }
                        } while (connectedFrontTrain != null);
                        if (isCycle)
                        {
                            continue;
                        }

                        Train connectedBackTrain = null;
                        int currentBack = currentTrain.back;
                        do
                        {
                            isFreeTrainExists[currentBack] = false;
                            connectedBackTrain = nonFreeTrains.FirstOrDefault(x => x.front == currentBack);
                            if (connectedBackTrain != null)
                            {
                                collectedTrains.Add(connectedBackTrain.trainId);
                                currentBack = connectedBackTrain.back;
                            }
                        } while (connectedBackTrain != null);
                    }
                    for (int i = 0; i < 26; ++i)
                    {
                        if (isFreeTrainExists[i])
                        {
                            ++bunchCount;
                        }
                    }

                    // Cycle Means IMPOSSIBLE!!!
                    if (cyclicMultipliers.Count > 0)
                    {
                        fileOutputWriter.WriteLine(string.Format("Case #{0}: 0", caseCounter));
                        continue;
                    }

                    // Calculate Permutation
                    ulong res = 1;
                    for (int i = 0; i < 26; ++i)
                    {
                        if (freeTrains[i].Count > 0)
                        {
                            res = ModedMult(res, ModedPermCount((ulong)freeTrains[i].Count));
                        }
                    }
                    res = ModedMult(res, ModedPermCount((ulong)bunchCount));
                    foreach (ulong cyclicMultiplier in cyclicMultipliers)
                    {
                        res = ModedMult(res, cyclicMultiplier);
                    }

                    fileOutputWriter.WriteLine(string.Format("Case #{0}: {1}", caseCounter, res));
                }

                fileOutputWriter.Close();
                fileOutputStream.Close();

                fileInputReader.Close();
                fileInputStream.Close();
            }
        }
    }
}
