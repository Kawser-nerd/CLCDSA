using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using GCJ;
using System.Diagnostics;

namespace Mushroom
{
    class Program
    {
        static void Main(string[] args)
        {
            Scanner s = new Scanner(File.ReadAllLines(args[0]));
            StreamWriter fs = null;
            if (args.Length > 1)
            {
                File.Delete(args[1]);
                fs = new StreamWriter(File.OpenWrite(args[1]));
            }
            int testCount = s.ReadInt();
            for (int i = 0; i < testCount; ++i)
            {
                int roundCount = s.ReadInt();
                List<UInt64> rounds = new List<UInt64>(roundCount);
                UInt64 totalEat = 0;
                UInt64 maxEat = 0;
                for (int j = 0; j < roundCount; ++j)
                {
                    rounds.Add((UInt64)s.ReadInt());
                }
                for (int j = 1; j < roundCount; ++j)
                {
                    if (rounds[j] < rounds[j - 1])
                    {
                        UInt64 eat = rounds[j - 1] - rounds[j];
                        totalEat += eat;
                        maxEat = Math.Max(maxEat, eat);
                    }
                }
                UInt64 totalEat2 = 0;
                for (int j = 0; j < roundCount - 1; ++j)
                {
                    totalEat2 += Math.Min(maxEat, rounds[j]);
                }
                string str = string.Format("Case #{0}: {1} {2}", i + 1, totalEat, totalEat2);
                Debug.WriteLine(str);
                if (fs != null)
                    fs.WriteLine(str);
            }
            if (fs != null)
                fs.Close();
        }
    }
}
