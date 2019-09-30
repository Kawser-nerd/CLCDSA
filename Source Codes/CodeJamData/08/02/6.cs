using System;
using System.Collections.Generic;

namespace GCJtest
{
    class Program
    {
        
        static void Main()
        {
            int[,] leaveA = new int[24, 60];
            int[,] leaveB = new int[24, 60];
            int[,] readyA = new int[24, 60];
            int[,] readyB = new int[24, 60];
        
            char[] delim = {' ', '\t', ':'};
            int numCases = int.Parse(Console.ReadLine());
            string[] splits;

            for (int i = 0; i < numCases; i++)
            {
                for (int h = 0; h < 24; h++) {
                    for (int m = 0; m < 60; m++) {
                        leaveA[h, m] = 0;
                        readyA[h, m] = 0;
                        leaveB[h, m] = 0;
                        readyB[h, m] = 0;
                    }
                }

                int turnTime = int.Parse(Console.ReadLine());
                
                splits = Console.ReadLine().Split(delim, StringSplitOptions.RemoveEmptyEntries);
                int NA = int.Parse(splits[0]);
                int NB = int.Parse(splits[1]);

                for (int j = 0; j < NA; j++) {
                    splits = Console.ReadLine().Split(delim, StringSplitOptions.RemoveEmptyEntries);
                    int leaveHour  = int.Parse(splits[0]);
                    int leaveMin   = int.Parse(splits[1]);
                    int arriveHour = int.Parse(splits[2]);
                    int arriveMin  = int.Parse(splits[3]);
                    int[] ready = addTime(arriveHour, arriveMin, turnTime);

                    leaveA[leaveHour, leaveMin]++;
                    if (ready[0] < 24)
                        readyB[ready[0], ready[1]]++;
                }
                for (int j = 0; j < NB; j++) {
                    splits = Console.ReadLine().Split(delim, StringSplitOptions.RemoveEmptyEntries);
                    int leaveHour  = int.Parse(splits[0]);
                    int leaveMin   = int.Parse(splits[1]);
                    int arriveHour = int.Parse(splits[2]);
                    int arriveMin  = int.Parse(splits[3]);
                    int[] ready = addTime(arriveHour, arriveMin, turnTime);

                    leaveB[leaveHour, leaveMin]++;
                    if (ready[0] < 24)
                        readyA[ready[0], ready[1]]++;
                }

                int startA = 0;
                int startB = 0;
                int trainsA = 0;
                int trainsB = 0;

                for (int h = 0; h < 24; h++) {
                    for (int m = 0; m < 60; m++) {
                        
                        trainsA += readyA[h,m];
                        trainsA -= leaveA[h, m];
                        if (trainsA < 0) {
                            startA += -trainsA;
                            trainsA = 0;
                        }
                        trainsB += readyB[h, m];
                        trainsB -= leaveB[h, m];
                        if (trainsB < 0) {
                            startB += -trainsB;
                            trainsB = 0;
                        }
                    }
                }

                Console.WriteLine("Case #{0}: {1} {2}", i + 1, startA, startB);

            }
        }

        static int[] addTime(int startHour, int startMin, int addMin)
        {
            int[] ret = {startHour + (startMin + addMin) / 60, (startMin + addMin) % 60};
            return ret;
        }


    }
}

