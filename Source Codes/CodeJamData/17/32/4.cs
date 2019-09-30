using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2017_1C_B
{
    class Program
    {
        class Activity: IComparable<Activity>
        {
            public int start, end;
            public bool cameron;

            public int CompareTo(Activity other)
            {
                return start.CompareTo(other.start);
            }
        }

        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var input = Console.ReadLine().Split().Select(int.Parse).ToArray();
                var AC = input[0];
                var AJ = input[1];
                var A = AC + AJ;
                var list = new Activity[A];
                for (int i = 0; i < A; i++)
                {
                    var line = Console.ReadLine().Split().Select(int.Parse).ToArray();
                    list[i] = new Activity { start = line[0], end = line[1], cameron = i < AC };
                }
                Array.Sort(list);

                var camRests = new List<int>();
                var jamRests = new List<int>();
                var jamTime = 0;
                var camTime = 0;
                var allTime = 0;
                var switches = 0;

                var camActivityLast = list[A - 1].cameron;
                var lastTime = list[A - 1].end - 1440;
                for (int i = 0; i < A; i++)
                {
                    var preInterval = list[i].start - lastTime;
                    if (camActivityLast)
                    {
                        if (list[i].cameron)
                        {
                            jamRests.Add(preInterval);
                            jamTime += preInterval + list[i].end - list[i].start;
                        } else
                        {
                            allTime += preInterval;
                            camTime += list[i].end - list[i].start;
                            camActivityLast = false;
                            switches++;
                        }
                    }
                    else
                    {
                        if (!list[i].cameron)
                        {
                            camRests.Add(preInterval);
                            camTime += preInterval + list[i].end - list[i].start;
                        }
                        else
                        {
                            allTime += preInterval;
                            jamTime += list[i].end - list[i].start;
                            camActivityLast = true;
                            switches++;
                        }
                    }
                    lastTime = list[i].end;
                }
                var camResstSorted = camRests.OrderByDescending(r => r).ToList();
                var jamResstSorted = jamRests.OrderByDescending(r => r).ToList();
                if (camTime + allTime < 720)
                {
                    for (int i = 0; camTime + allTime < 720; i++)
                    {
                        camTime += jamResstSorted[i];
                        switches += 2;
                    }
                } else if (jamTime + allTime < 720)
                {
                    for (int i = 0; jamTime + allTime < 720; i++)
                    {
                        jamTime += camResstSorted[i];
                        switches += 2;
                    }
                }

                Console.WriteLine("Case #{0}: {1}", testN, switches);
            }
        }
    }
}
