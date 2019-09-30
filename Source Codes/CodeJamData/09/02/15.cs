using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2009
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] dx = new int[] { -1, 0, 0, 1 };
            int[] dy = new int[] { 0, -1, 1, 0 };
			string[] input = File.ReadAllLines("B-large.in");
            string output = "";
            int lineAt = 0;
            int T = int.Parse(input[lineAt++]);
            for (int i = 0; i < T; i++)
            {
                string[] dim = input[lineAt++].Split(' ');
                int H = int.Parse(dim[0]);
                int W = int.Parse(dim[1]);
                int[,] map = new int[H, W];
                int[,] basins = new int[H, W];
				char[,] res = new char[H, W];
                for (int j = 0; j < H; j++)
                {
                    string[] line = input[lineAt++].Split(' ');
                    for (int k = 0; k < W; k++)
                    {
                        map[j, k] = int.Parse(line[k]);
                        basins[j, k] = -1;
                    }
                }
                int nextBasin = 0;
				char[] basinLookup = new char[26];
				for(int p=0;p<26;p++) basinLookup[p] = '-';
                for (int h = 0; h <= 10000; h++)
                {
                    for (int j = 0; j < H; j++)
                    {
                        for (int k = 0; k < W; k++)
                        {
                            if (map[j,k] == h)
                            {
                                int lowest = h;
                                int label = nextBasin;
                                for (int p = 0; p < 4; p++)
                                {
                                    int jj = j + dx[p];
                                    int kk = k + dy[p];
                                    if(jj >= 0 && jj < H && kk >= 0 && kk < W)
                                    {
                                        if(map[jj,kk] < lowest)
                                        {
                                            lowest = map[jj,kk];
                                            label = basins[jj, kk];
                                        }
                                    }
                                }
                                if(label == nextBasin)
                                {
                                    basins[j, k] = nextBasin++;
                                }
                                else
                                {
                                    basins[j, k] = label;
                                }
                            }
                        }
                    }
                }
				char alpha = 'a';
                for (int j = 0; j < H; j++)
                {
                    for (int k = 0; k < W; k++)
                    {
						if(basinLookup[basins[j,k]] == '-')
						{
							basinLookup[basins[j,k]] = alpha++;
						}
						res[j, k] = basinLookup[basins[j, k]];
                    }
                }
                string ret = Environment.NewLine;
                for (int j = 0; j < H; j++)
                {
					for (int k = 0; k < W; k++)
					{
						ret += res[j, k];
						if (k < W - 1) ret += " ";
					}
                    ret += Environment.NewLine;
                }

                output += "Case #" + (i + 1) + ": " + ret;
            }
            File.WriteAllText("output.txt", output);
            Console.WriteLine(output);
        }
    }
}
