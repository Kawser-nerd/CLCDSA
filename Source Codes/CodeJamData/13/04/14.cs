using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO; //for StreamReader & Writer

namespace GoogleCodeJam
{
    class GoogleCodeJam_2013_QR_D
    {
        static void Main(string[] args)
        {
            TextReader reader = new StreamReader("../../input_D_sm.txt");
            TextWriter writer = new StreamWriter("../../output_D_sm.txt");

            int T = int.Parse(reader.ReadLine());

            for (int tc = 1; tc <= T; tc++)
            {

                string[] s = reader.ReadLine().Split();
                int K = int.Parse(s[0]);
                int N = int.Parse(s[1]);

                Console.WriteLine("K N = " + K + " " + N);

                s = reader.ReadLine().Split();
                List<int> keysHave = new List<int>();
                int[] keysAvailable = new int[201];
                int[] keysNeeded = new int[201];

                int i = 0;
                for (i = 0; i < K; i++)
                {
                    keysHave.Add(int.Parse(s[i]));
                    keysAvailable[int.Parse(s[i])]++;
                }

                bool[] openedChest = new bool[N];
                bool[] skipChest = new bool[N];
                int[] keyTypeToOpenChest = new int[N];
                int[] numKeysInChest = new int[N];
                List<int>[] keysInChest = new List<int>[N];
                i = 0;
                for (i = 0; i < N; i++)
                {
                    s = reader.ReadLine().Split();
                    keyTypeToOpenChest[i] = int.Parse(s[0]);
                    keysNeeded[keyTypeToOpenChest[i]]++;
                    numKeysInChest[i] = int.Parse(s[1]);
                    keysInChest[i] = new List<int>();

                    for (int j = 0; j < numKeysInChest[i]; j++)
                    {
                        keysInChest[i].Add(int.Parse(s[2 + j]));
                        keysAvailable[int.Parse(s[2 + j])]++;
                    }
                }

                int numClosed = N;
                List<int> chestOpened = new List<int>();

                bool goodNumOfKeys = true;
                for (i = 1; i <= 200; i++)
                    if (keysAvailable[i] < keysNeeded[i])
                        goodNumOfKeys = false;
                
                if (goodNumOfKeys)
                {
                    i = 0;
                    numClosed = 0;
                    int start = 0;
                    bool tryAgain = true;

                    while (tryAgain)
                    {
                        for (i = start; i < N; i++)
                        {
                            if (!openedChest[i])
                            {
                                //Check if last key of type and other chest requires
                                //same key and contains same key type
                                bool trouble = false;
                                int cntKeys = 0;
                                for (int j = 0; j < keysHave.Count; j++)
                                    if (keysHave[j] == keyTypeToOpenChest[i])
                                        cntKeys++;
                                for (int j = 0; j < keysInChest[i].Count; j++)
                                    if (keysInChest[i][j] == keyTypeToOpenChest[i])
                                        cntKeys++;

                                if (cntKeys == 1 
                                    && (keysNeeded[keyTypeToOpenChest[i]] > 1))
                                {
                                    //Check if keyNeeded is matched with a different key
                                    //and that we have another key (anykey).
                                    trouble = true;
                                    if (keysHave.Count > 1 || keysInChest[i].Count > 0)
                                        for (int j = 0; j < N; j++)
                                            if (j != i && !openedChest[j]
                                               && keyTypeToOpenChest[j] != keyTypeToOpenChest[i])
                                                for (int k = 0; k < keysInChest[j].Count; k++)
                                                    if (keysInChest[j][k] == keyTypeToOpenChest[i])
                                                        trouble = false;

                                    //for (int j = 0; j < N; j++)
                                    //    if (j != i && !openedChest[j]
                                    //        && keyTypeToOpenChest[j] == keyTypeToOpenChest[i])
                                    //        for (int k = 0; k < keysInChest[j].Count; k++)
                                    //            if (keysInChest[j][k] == keyTypeToOpenChest[j])
                                    //                trouble = true; 
                                }

                                if (keysHave.Contains(keyTypeToOpenChest[i]) && !trouble)
                                {
                                    keysHave.Remove(keyTypeToOpenChest[i]);
                                    keysAvailable[keyTypeToOpenChest[i]]--;
                                    keysNeeded[keyTypeToOpenChest[i]]--;
                                    for (int j = 0; j < keysInChest[i].Count; j++)
                                    {
                                        keysHave.Add(keysInChest[i][j]);
                                        keysAvailable[keysInChest[i][j]]++;
                                    }
                                    openedChest[i] = true;
                                    chestOpened.Add(i);
                                    i = -1;  //Start at beginning
                                    numClosed = 0;
                                }
                                else numClosed++;
                            }
                        }

                        //Should be done; if not remove last move and try next

                        if (numClosed > 0 && chestOpened.Count > 0)
                        {
                            //undo action
                            int chestNum = chestOpened[chestOpened.Count - 1];
                            for (int j = 0; j < keysInChest[chestNum].Count; j++)
                            {
                                keysHave.Remove(keysInChest[chestNum][j]);
                                keysAvailable[keysInChest[chestNum][j]]--;
                            }
                            keysHave.Add(keyTypeToOpenChest[chestNum]);
                            keysAvailable[keyTypeToOpenChest[chestNum]]++;
                            keysNeeded[keyTypeToOpenChest[chestNum]]++;
                            openedChest[chestNum] = false;
                            chestOpened.Remove(chestNum);
                            start = chestNum + 1;
                        }
                        else
                            tryAgain = false;
                    }
                }
            

                StringBuilder ans = new StringBuilder();
                if (numClosed > 0)
                    ans.Append("IMPOSSIBLE");
                else
                    for (i = 0; i < N; i++)
                    {
                        ans.Append(chestOpened[i]+1);
                        if (i < N - 1) ans.Append(" ");
                    }

                Console.WriteLine("Case #" + tc + ": " + ans);
                writer.WriteLine("Case #" + tc + ": " + ans);
            }

            reader.Close();
            writer.Close();
        }

    }
}
