using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJamA
{
    class RPI
    {
        static void Main(string[] args)
        {
            var file = File.OpenText(args[0]);

            using (var outFile = new StreamWriter(File.Open("output.txt", FileMode.Create)))
            {
                int T = int.Parse(file.ReadLine());
                for (int i = 0; i < T; i++)
                {
                    var line = file.ReadLine();
                    int N = int.Parse(line);
                    
                    GameOutcome[][] gameWins = new GameOutcome[N][];
                    List<int>[] playedOpponents = new List<int>[N];
                    int[] wins = new int[N];
                    int[] matches = new int[N];

                    for (int j = 0; j < N; j++)
                    {
                        gameWins[j] = new GameOutcome[N];
                        playedOpponents[j] = new List<int>();
                    }


                    for (int j = 0; j < N - 1; j++)
                    {
                        string games = file.ReadLine();
                        
                        char game;
                        for(int k = j + 1; k < N; k++)
                        {
                            game = games[k];
                            gameWins[j][k] = ParseGame(game, false);
                            gameWins[k][j] = ParseGame(game, true);
                            if(game != '.')
                            {
                                playedOpponents[j].Add(k);
                                playedOpponents[k].Add(j);
                                matches[j]++;
                                matches[k]++;
                                
                                if (game == '1')
                                {
                                    wins[j]++;
                                }
                                else if (game == '0')
                                {
                                    wins[k]++;
                                }
                            }
                            
                        }
                    }
                    file.ReadLine();

                    double[] WP = new double[N];
                    for (int j = 0; j < N; j++)
                    {
                        WP[j] = ((double)wins[j]) / ((double)matches[j]);
                    }

                    double[] OWP = new double[N];
                    for (int j = 0; j < N; j++)
                    {
                        List<double> oppWps = new List<double>();
                        foreach (var opp in playedOpponents[j])
                        {
                            var oppWins = wins[opp];
                            if (gameWins[j][opp] == GameOutcome.Loss)
                                oppWins--;

                            oppWps.Add((double)oppWins / ((double)(matches[opp] - 1)));
                        }

                        OWP[j] = oppWps.Sum() / (float)(playedOpponents[j].Count);
                    }

                    double[] OOWP = new double[N];
                    for (int j = 0; j < N; j++)
                    {
                        List<double> oppOWps = new List<double>();
                        foreach (var opp in playedOpponents[j])
                        {
                            oppOWps.Add(OWP[opp]);
                        }

                        OOWP[j] = oppOWps.Sum() / (double)(playedOpponents[j].Count);
                    }

                    string answer = string.Format("Case #{0}: {1}", i, 1);
                    outFile.WriteLine(string.Format("Case #{0}:", (i+1)));
                    for (int j = 0; j < N; j++)
                    {
                        outFile.WriteLine(0.25 * WP[j] + 0.50 * OWP[j] + 0.25 * OOWP[j]);
                    }
                }
            }
        }

        static GameOutcome ParseGame(char game, bool flip)
        {
            if (game == '.')
                return GameOutcome.No;
            if (!flip)
            {
                if (game == '0')
                    return GameOutcome.Loss;
                else
                    return GameOutcome.Won;
            }
            else
            {
                if (game == '1')
                    return GameOutcome.Loss;
                else
                    return GameOutcome.Won;
            }
        }

        enum GameOutcome
        {
            No,
            Loss,
            Won
        }
    }
}
