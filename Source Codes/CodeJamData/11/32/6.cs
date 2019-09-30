using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Bsp2
{
    class Program
    {
        private const string _fileIn = @"C:\Users\Peter\Documents\Google Code Jam\2011\Round1c\Bsp2\Bsp2\B-large.in";
        private const string _fileOut = @"C:\Users\Peter\Documents\Google Code Jam\2011\Round1c\Bsp2\Bsp2\B-large.out";

        static void Main(string[] args)
        {
            int caseCount = 1;
            StreamReader sr = new StreamReader(_fileIn);
            StreamWriter sw = new StreamWriter(_fileOut);

            sr.ReadLine();

            string line;
            string[] lineParts;

            int L, N, C;
            long t;
            int[] distancees;
            List<long> longestDistances = new List<long>();;
            Dictionary<long, int> setDistances = new Dictionary<long, int>();

            long curPosition, tmpVal;
            bool boosterFinished;

            while (!sr.EndOfStream)
            {
                line = sr.ReadLine();
                lineParts = line.Split(' ');
                // L, t, N and C, followed by C integers ai,

                L = int.Parse(lineParts[0]);
                t = long.Parse(lineParts[1]);
                N = int.Parse(lineParts[2]);
                C = int.Parse(lineParts[3]);
                distancees = new int[N];
                curPosition = 0;
                boosterFinished = false;

                for (int i = 0; i < distancees.Length; i++)
                {
                    if (i < C)
                    {
                        distancees[i] = int.Parse(lineParts[i + 4]);
                    }
                    else
                    {
                        distancees[i] = distancees[i % C];
                    }
                }

                for (int i = 0; i < distancees.Length; i++)
                {
                    if (!boosterFinished)
                    {
                        curPosition += (distancees[i] * 2);

                        if (curPosition >= t)
                        {
                            boosterFinished = true;

                            longestDistances.Clear();

                            for (int j = i + 1; j < distancees.Length; j++)
                                longestDistances.Add(distancees[j]);

                            tmpVal = (curPosition - t) / 2;
                            longestDistances.Add(tmpVal);
                            longestDistances.Sort();
                            longestDistances.Reverse();

                            for (int j = 0; j < L && j < longestDistances.Count; j++)
                            {
                                if (setDistances.ContainsKey(longestDistances[j]))
                                    setDistances[longestDistances[j]]++;
                                else
                                    setDistances.Add(longestDistances[j], 1);
                            }

                            if (setDistances.ContainsKey(tmpVal))
                            {
                                setDistances[tmpVal]--;

                                if (setDistances[tmpVal] <= 0)
                                    setDistances.Remove(tmpVal);
                                
                                curPosition -= tmpVal;
                            }
                        }
                    }
                    else
                    {
                        if (setDistances.ContainsKey(distancees[i]))
                        {
                            curPosition += distancees[i];
                            setDistances[distancees[i]]--;

                            if (setDistances[distancees[i]] <= 0)
                                setDistances.Remove(distancees[i]);
                        }
                        else
                            curPosition += (distancees[i] * 2);
                    }
                }

                sw.WriteLine("Case #{0}: {1}", caseCount++, curPosition);
            }

            sw.Close();
        }
    }
}
