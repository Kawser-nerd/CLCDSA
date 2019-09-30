using System;
using System.Collections.Generic;

namespace GCJtest
{
    class Program
    {
        static void Main()
        {
            int numCases = int.Parse(Console.ReadLine());
            for (int i = 0; i < numCases; i++)
            {
                // Get the search engine names
                int numEngines = int.Parse(Console.ReadLine());
                string[] engines = new string[numEngines];
                for (int j = 0; j < numEngines; j++) {
                    engines[j] = Console.ReadLine().Trim();
                }

                // Get the search strings
                int numSearches = int.Parse(Console.ReadLine());
                string[] searches = new string[numSearches];
                for (int j = 0; j < numSearches; j++) {
                    searches[j] = Console.ReadLine().Trim();
                }

                // Simple greedy algorithm, just find the engine
                // that will get through the most searches starting now

                int currentIndex = 0;
                int numSwitches = -1;

                while (currentIndex < numSearches) {
                    int bestIndex = currentIndex;
                    for (int j = 0; j < numEngines; j++) {
                        for (int k = currentIndex; k <= numSearches; k++) {
                            if (k == numSearches) {
                                bestIndex = k;
                                break;
                            }
                            if (engines[j].Equals(searches[k])) {
                                if (k > bestIndex) {
                                    bestIndex = k;
                                }
                                break;
                            }

                        }
                        //Console.WriteLine("engine {0}", engines[j]);
                        //Console.WriteLine("startIndex {0}: {1}", currentIndex, searches[currentIndex]);
                        //if (bestIndex == numSearches) {
                        //    Console.WriteLine("bestIndex To End!");
                        //} else {
                        //    Console.WriteLine("bestIndex {0}: {1}", bestIndex, searches[bestIndex]);
                        //}
                    }
                        

                    currentIndex = bestIndex;
                    numSwitches++;
                }
                
                if (numSwitches < 0) {
                    numSwitches = 0;
                }

                Console.WriteLine("Case #{0}: {1}", i+1, numSwitches);
            }
        }
    }
}

