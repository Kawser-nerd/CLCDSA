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
                int barberCount = s.ReadInt();
                UInt64 place = (UInt64)s.ReadInt();
                int result = 0;
                List<UInt64> barberTime = new List<UInt64>(barberCount);
                double perTime = 0;
                for (int j = 0; j < barberCount; ++j)
                {
                    UInt64 time = (UInt64)s.ReadInt();
                    barberTime.Add(time);
                    perTime += 1.0 / time;
                }
                if (place <= (UInt64)barberCount)
                {
                    result = (int)place-1;
                }
                else
                {
                    place -= (UInt64)barberCount;
                    UInt64 timeNeeded = (UInt64)Math.Ceiling(place / perTime);
                    bool resultFound = false;
                    do
                    {
                        List<UInt64> timeBeforeNext = new List<UInt64>(barberCount);
                        UInt64 totalClients = 0;
                        for (int j = 0; j < barberCount; ++j)
                        {
                            UInt64 clients = timeNeeded == 0 ? 0 : ((timeNeeded - 1) / barberTime[j]);
                            totalClients += clients;
                            UInt64 timeElapsed = timeNeeded % barberTime[j];
                            timeBeforeNext.Add(timeElapsed == 0 ? 0 : barberTime[j] - timeElapsed);
                        }
                        if (totalClients < place)
                        {
                            place -= totalClients;
                            UInt64 lastMin = 0;
                            do
                            {
                                UInt64 nextMin = UInt64.MaxValue;
                                for (int j = 0; j < barberCount; ++j)
                                {
                                    timeBeforeNext[j] -= lastMin;
                                    if (timeBeforeNext[j] == 0)
                                    {
                                        if (--place == 0)
                                        {
                                            result = j;
                                            resultFound = true;
                                            break;
                                        }
                                        else
                                        {
                                            timeBeforeNext[j] = barberTime[j];
                                        }
                                    }
                                    nextMin = Math.Min(nextMin, timeBeforeNext[j]);
                                }
                                lastMin = nextMin;
                            } while (!resultFound);
                        }
                        else
                        {
                            timeNeeded = (UInt64)(timeNeeded * .99);
                        }
                    } while (!resultFound);
                }
                string str = string.Format("Case #{0}: {1}", i + 1, result + 1);
                Debug.WriteLine(str);
                if (fs != null)
                    fs.WriteLine(str);
            }
            if (fs != null)
                fs.Close();
        }
    }
}
