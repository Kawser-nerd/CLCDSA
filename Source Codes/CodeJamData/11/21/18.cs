using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace codejam_2011_round1B_A
{
    class Program
    {
        static void Main(string[] args)
        {
            // Checks
            if (args.Length != 1)
            {
                Console.WriteLine("Specify input file");
                Console.ReadLine();
                return;
            }

            StreamReader reader = new StreamReader(args[0]);
            int t = int.Parse(reader.ReadLine());
            for (int current = 1; current <= t; ++current)
            {
                int n = int.Parse(reader.ReadLine());
                bool?[][] games = new bool?[n][];
                for (int lineNumber = 0; lineNumber < n; ++lineNumber)
                {
                    string line = reader.ReadLine();
                    games[lineNumber] = line.Select(x => x == '1' ? new bool?(true) : x == '.' ? null : new bool?(false)).ToArray();
                }

                double[] wpMatrix = new double[n];
                int[] totalGamesMatrix = new int[n];
                int[] totalWinsMatrix = new int[n]; 
                for (int a = 0; a < n; ++a)
                {
                    int totalGames = 0;
                    int wins = 0;
                    for (int b = 0; b < n; ++b)
                    {
                        if (games[a][b].HasValue)
                        {
                            ++totalGames;
                            if (games[a][b].Value == true)
                            {
                                ++wins;
                            }
                        }
                    }
                    wpMatrix[a] = wins / (double)totalGames;
                    totalGamesMatrix[a] = totalGames;
                    totalWinsMatrix[a] = wins;
                }

                double[] opwMatrix = new double[n];
                for (int a = 0; a < n; ++a)
                {
                    double owpTotal = 0;
                    for (int b = 0; b < n; ++b)
                    {
                        if (games[a][b].HasValue)
                        {
                            int opWins = totalWinsMatrix[b];
                            if (games[a][b].Value == false)
                            {
                                opWins -= 1;
                            }
                            owpTotal += opWins / (double)(totalGamesMatrix[b] - 1);
                        }
                    }
                    owpTotal /= totalGamesMatrix[a];
                    opwMatrix[a] = owpTotal;
                }

                double[] rpiMatrix = new double[n];
                for (int a = 0; a < n; ++a)
                {
                    double wp = wpMatrix[a];
                    double owp = opwMatrix[a];
                    double oowp = 0;
                    for (int b = 0; b < n; ++b)
                    {
                        if (games[a][b].HasValue)
                        {
                            oowp += opwMatrix[b];
                        }
                    }
                    oowp /= totalGamesMatrix[a];
                    rpiMatrix[a] = 0.25 * wp + 0.50 * owp + 0.25 * oowp;
                }

                Console.WriteLine("Case #{0}:", current);
                for (int a = 0; a < n; ++a)
                {
                    Console.WriteLine(rpiMatrix[a]);
                }
            }
        }
    }
}

