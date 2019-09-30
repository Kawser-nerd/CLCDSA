using System;
using System.Collections.Generic;
using System.IO;

namespace CodeJam
{
    public class ProbB
    {
        struct Choice
        {
            public int flav;
            public int malted;
            public bool satisfied;
        }

        public static void Solution()
        {
            FileStream fs = new FileStream("inputB.txt", FileMode.Open);
            StreamReader reader = new StreamReader(fs);

            int cases = Int32.Parse(reader.ReadLine());
            for (int i = 0; i < cases; i++)
            {
                int numFlavs = Int32.Parse(reader.ReadLine());
                int numCust = Int32.Parse(reader.ReadLine());
                Choice[][] custChoices = new Choice[numCust][];
                for (int j = 0; j < numCust; j++)
                {
                    List<Choice> custChoice = new List<Choice>();
                    string custFlavs = reader.ReadLine();
                    string[] splits = custFlavs.Split(' ');
                    int T = Int32.Parse(splits[0]);
                    for (int k = 1; k < T * 2; k += 2)
                    {
                        Choice c = new Choice();
                        c.flav = Int32.Parse(splits[k]);
                        c.malted = Int32.Parse(splits[k+1]);
                        c.satisfied = true;
                        custChoice.Add(c);
                        custChoices[j] = custChoice.ToArray();
                    }
                }
                Solve(numFlavs, numCust, custChoices);
            }

            Console.ReadLine();
        }

        static int caseNum = 0;

        static bool IsUnsatisfied(Choice[] custChoice)
        {
            foreach (Choice c in custChoice)
            {
                if (c.satisfied == true)
                    return false;
            }
            return true;
        }

        static int getNumSats(Choice[] custChoice)
        {
            int sats = 0;
            foreach (Choice c in custChoice)
            {
                if (c.satisfied == true)
                    sats+=1;
            }
            return sats;
        }

        static Choice getSatChoice(Choice[] custChoice)
        {
            foreach (Choice c in custChoice)
            {
                if (c.satisfied == true)
                    return c;
            }
            return new Choice();
        }

        static void Solve(int nF, int nC, Choice[][] custChoices)
        {
            caseNum++;
            int[] flavs = new int[nF];

            bool changed = true;
            while (changed)
            {
                changed = false;
                for (int i = 0; i < custChoices.GetLength(0); i++)
                {
                    if (getNumSats(custChoices[i]) == 1)
                    {
                        Choice c = getSatChoice(custChoices[i]);
                        if (c.malted == 1)
                        {
                            flavs[c.flav - 1] = 1;
                            for (int j = 0; j < custChoices.GetLength(0); j++)
                            {
                                for (int k = 0; k < custChoices[j].GetLength(0); k++)
                                {
                                    if (custChoices[j][k].flav == c.flav && custChoices[j][k].malted == 0 && custChoices[j][k].satisfied)
                                    {
                                        custChoices[j][k].satisfied = false;
                                        changed = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            
            for (int m = 0; m < custChoices.GetLength(0); m++)
            {
                if(IsUnsatisfied(custChoices[m]))
                {
                    Console.WriteLine("Case #{0}: IMPOSSIBLE", caseNum);
                    return;
                }
            }

            Console.Write("Case #{0}: ",caseNum);
            for (int g = 0; g < nF; g++)
            {
                Console.Write("{0} ", flavs[g]);
            }
            Console.WriteLine();
        }
    }
}
