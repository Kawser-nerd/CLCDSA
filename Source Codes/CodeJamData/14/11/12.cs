using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program
    {
        static string _folderPath = Directory.GetCurrentDirectory() + @"/../../Questions/";
        static string _question = "ChargingChaos";
        static string _dataSize = "L";   // T, S or L q

        static void Main(string[] args)
        {
            var data = File.ReadAllLines(_folderPath + _question + "_" + _dataSize + ".in");

            using (var outFile = File.CreateText(_folderPath + _question + "_" + _dataSize + ".out"))
            {
                Action<string> dualWriter = line =>
                {
                    Console.WriteLine(line);
                    outFile.WriteLine(line);
                };

                solve(data, dualWriter);
            }

            Console.WriteLine("Done!");
            Console.Read();
        }

        static void solve(IList<string> lines, Action<string> writeLine)
        {
            int numQs = int.Parse(lines[0]);

            int at = 1;

            for (int q = 0; q < numQs; q++)
            {
                var l1 = lines[at++].Split(new[] {' '}, StringSplitOptions.RemoveEmptyEntries).Select(s => int.Parse(s)).ToList();
                var n = l1[0];
                var l = l1[1];

                var flow = lines[at++].Split(new[] {' '}, StringSplitOptions.RemoveEmptyEntries).ToList();
                var dev = lines[at++].Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();

                string answer = solve1(n, l, flow, dev);
                writeLine(string.Format("Case #{0}: {1}", q + 1, answer));
            }
        }

        static string solve1(int n, int l, List<string> flow, List<string> dev)
        {
            flow.Sort();
            dev.Sort();

            int flipCt = 0;
            if (recur(n, l, flow, dev, 0, ref flipCt))
            {
                return flipCt.ToString();
            }

            return "NOT POSSIBLE";
        }

        static bool recur(int n, int l, List<string> flow, List<string> dev, int pos, ref int flipCt)
        {
            bool nonFlipOK = true;
            for (int i = 0; i < n; i++)
            {
                if (flow[i][pos] != dev[i][pos])
                {
                    nonFlipOK = false;
                    break;
                }
            }

            var flowFlip = flow.ToList();

            for (int i = 0; i < n; i++)
            {
                var sb = new StringBuilder(flowFlip[i]);
                sb[pos] = sb[pos] == '0' ? '1' : '0';
                flowFlip[i] = sb.ToString();
            }

            flowFlip.Sort();

            bool flipOK = true;
            for (int i = 0; i < n; i++)
            {
                if (flowFlip[i][pos] != dev[i][pos])
                {
                    flipOK = false;
                    break;
                }
            }

            if (pos == l - 1)
            {
                if (nonFlipOK)
                {
                    return true;
                }
                else if (flipOK)
                {
                    flipCt++;
                    return true;
                }

                return false;
            }
            else
            {
                int fp1 = int.MaxValue;
                int fp2 = int.MaxValue;
                if (nonFlipOK)
                {
                    int temp = flipCt;
                    if (recur(n, l, flow, dev, pos + 1, ref temp))
                    {
                        fp1 = temp;
                    }
                }
                if (flipOK)
                {
                    int temp = flipCt + 1;
                    if (recur(n, l, flowFlip, dev, pos + 1, ref temp))
                    {
                        fp2 = temp;
                    }
                }

                int minFp = Math.Min(fp1, fp2);

                if (minFp < int.MaxValue)
                {
                    flipCt = minFp;
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
}


// lines[at++].Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => double.Parse(s)).ToList();