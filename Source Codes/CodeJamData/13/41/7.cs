using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace TicketSwapping
{
    class Tickets
    {
        public long HowOld;
        public long numPassengers;
    }

    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            StreamReader sr = new StreamReader("D:\\A-small-attempt0.in");
            StreamWriter sw = new StreamWriter("D:\\A-small-attempt0.out");

            //StreamReader sr = new StreamReader("D:\\D-large-practice.in");
            //StreamWriter sw = new StreamWriter("D:\\D-large-practice.out");

            int numTestCases = Convert.ToInt32(sr.ReadLine());

            for (int i = 0; i < numTestCases; i++)
            {
                Console.WriteLine(i);

                string[] str = sr.ReadLine().Split(' ');

                long numStations = Convert.ToInt64(str[0]);
                int M = Convert.ToInt32(str[1]);

                long[] startingPoints = new long[M];
                long[] endingPoints = new long[M];
                long[] numPassengers = new long[M];

                long totalActualCost = 0;
                List<long> stationsToConsider = new List<long>();

                for (int j = 0; j < M; j++)
                {
                    str = sr.ReadLine().Split(' ');

                    startingPoints[j] = Convert.ToInt64(str[0]);
                    endingPoints[j] = Convert.ToInt64(str[1]);
                    numPassengers[j] = Convert.ToInt64(str[2]);

                    totalActualCost += GetActualCost(endingPoints[j] - startingPoints[j]) * numPassengers[j];

                    if (stationsToConsider.Contains(startingPoints[j]) == false)
                    {
                        stationsToConsider.Add(startingPoints[j]);
                    }
                    if (stationsToConsider.Contains(endingPoints[j]) == false)
                    {
                        stationsToConsider.Add(endingPoints[j]);
                    }
                }

                stationsToConsider.Sort();

                long[] numGettingOn=new long[stationsToConsider.Count];
                long[] numGettingOff=new long[stationsToConsider.Count];
                
                for(int j=0;j<stationsToConsider.Count;j++)
                {
                    numGettingOn[j] = FindNumPassengersGettingOn(startingPoints, endingPoints, numPassengers, stationsToConsider[j]);
                    numGettingOff[j] = FindNumPassengersGettingOff(startingPoints, endingPoints, numPassengers, stationsToConsider[j]);
                }

                long totalCheatedCost = 0;

                List<Tickets> tickets = new List<Tickets>();
                long lastStation = -1;

                for(int j=0;j<stationsToConsider.Count;j++)
                {
                    long station = stationsToConsider[j];
                    long gettingOn = numGettingOn[j];
                    long gettingOff = numGettingOff[j];

                    if (j == 0)
                    {
                        Tickets temp=new Tickets();
                        temp.numPassengers = gettingOn;
                        temp.HowOld = 0;
                        tickets.Add(temp);

                        lastStation = station;
                        continue;
                    }
                    else
                    {
                        for (int k = 0; k < tickets.Count; k++)
                        {
                            tickets[k].HowOld += (station - lastStation);
                        }

                        if (gettingOn > gettingOff)
                        {
                            Tickets temp = new Tickets();
                            temp.numPassengers = gettingOn-gettingOff;
                            temp.HowOld = 0;
                            tickets.Insert(0,temp);
                        }
                        else if (gettingOn < gettingOff)
                        {
                            long toRemove = gettingOff - gettingOn;

                            while(toRemove>0)
                            {
                                if (tickets[0].numPassengers == toRemove)
                                {
                                    totalCheatedCost += GetActualCost(tickets[0].HowOld) * tickets[0].numPassengers;
                                    tickets.RemoveAt(0);
                                    toRemove = 0;
                                    break;
                                }
                                else if (tickets[0].numPassengers < toRemove)
                                {
                                    totalCheatedCost += GetActualCost(tickets[0].HowOld) * tickets[0].numPassengers; 
                                    toRemove -= tickets[0].numPassengers;
                                    tickets.RemoveAt(0);
                                    continue;
                                }
                                else if(tickets[0].numPassengers > toRemove)
                                {
                                    totalCheatedCost += GetActualCost(tickets[0].HowOld) * toRemove; 
                                    tickets[0].numPassengers -= toRemove;
                                    toRemove = 0;
                                    break;
                                }
                            } 
                        }

                        lastStation = station;
                    }
                }

                sw.Write("Case #{0}: ", i + 1);
                sw.Write(totalActualCost - totalCheatedCost);
                sw.WriteLine();

            }
            sw.Close();
        }

        static long GetActualCost(long numStations)
        {
            return -(numStations * (numStations - 1)) / 2;
        }

        static long FindNumPassengersGettingOn(long[] sp, long[] ep, long[] np,long stationNumber)
        {
            long num=0;
            for (int j = 0; j < sp.Length; j++)
            {
                if (sp[j] == stationNumber)
                    num += np[j];
            }

            return num;
        }

        static long FindNumPassengersGettingOff(long[] sp, long[] ep, long[] np, long stationNumber)
        {
            long num = 0;
            for (int j = 0; j < ep.Length; j++)
            {
                if (ep[j] == stationNumber)
                    num += np[j];
            }

            return num;
        }
    }
}
