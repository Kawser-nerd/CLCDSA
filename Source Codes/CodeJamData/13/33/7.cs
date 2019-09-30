using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
using System.Diagnostics;
using Wintellect.PowerCollections;

namespace CodeJamQualifications
{
    class Tribe : IComparable<Tribe>
    {
        public long day, numAttacks, westSide, eastSide, strength;
        public long dayDelta, distanceDelta, strengthDelta;

        #region IComparable<Employee> Members

        public int CompareTo(Tribe other)
        {
            if (this.day > other.day) return 1;
            else if (this.day < other.day) return -1;
            else return 0;
        }

        #endregion
    }

    struct Attack
    {
        public long westSide, eastSide, strength;
    }

    class Program
    {
        const string challenge = "Tribes";
        const string outputFolder = @"C:\Users\Arch\Documents\CodeJam\Output\";

        static void Main(string[] args)
        {
            List<Tribe> tribes = new List<Tribe>();
            Dictionary<long, long> wall = new Dictionary<long, long>();

            ClearFile();

            string[] lines = File.ReadAllLines(args[0]);
            int count = int.Parse(lines[0]);
            int cursor = 1;

            for (int i = 0; i < count; i++)
            {
                tribes.Clear();
                wall.Clear();

                int tribeCount = int.Parse(lines[cursor++]);
                for (int t = 0; t < tribeCount; t++)
                {
                    Tribe tribe = new Tribe();
                    string[] info = lines[cursor++].Split(new char[] { ' ' });
                    tribe.day = long.Parse(info[0]);
                    tribe.numAttacks = long.Parse(info[1]);
                    tribe.westSide = long.Parse(info[2]);
                    tribe.eastSide = long.Parse(info[3]);
                    tribe.strength = long.Parse(info[4]);
                    tribe.dayDelta = long.Parse(info[5]);
                    tribe.distanceDelta = long.Parse(info[6]);
                    tribe.strengthDelta = long.Parse(info[7]);

                    tribes.Add(tribe);
                }

                tribes.Sort(delegate(Tribe t1, Tribe t2)
                {
                    return t1.day.CompareTo(t2.day);
                });

                long attacks = 0;
                List<Attack> toBuild = new List<Attack>();

                while (tribes.Count > 0)
                {
                    if (tribes[0].numAttacks <= 0)
                    {
                        tribes.RemoveAt(0);
                    }
                    else
                    {
                        if (tribes[0].strength > 0)
                        {
                            bool broken = false;
                            for (long p = tribes[0].westSide * 2; p <= tribes[0].eastSide * 2; p++)
                            {
                                if (!wall.ContainsKey(p) || wall[p] < tribes[0].strength)
                                {
                                    attacks++;
                                    broken = true;
                                    break;
                                }
                            }
                            
                            if (broken)
                            {
                                Attack a = new Attack();
                                a.westSide = tribes[0].westSide;
                                a.eastSide = tribes[0].eastSide;
                                a.strength = tribes[0].strength;
                                toBuild.Add(a);
                            }
                                

                            if (tribes.Count <= 1 || tribes[1].day != tribes[0].day)
                            {
                                for (int b = 0; b < toBuild.Count; b++)
                                {
                                    for (long p = toBuild[b].westSide * 2; p <= toBuild[b].eastSide * 2; p++)
                                    {
                                        wall[p] = Math.Max((wall.ContainsKey(p) ? wall[p] : 0), toBuild[b].strength);
                                    }
                                }

                                toBuild.Clear();
                            }
                        }

                        tribes[0].strength += tribes[0].strengthDelta;
                        tribes[0].westSide += tribes[0].distanceDelta;
                        tribes[0].eastSide += tribes[0].distanceDelta;
                        tribes[0].numAttacks--;
                        tribes[0].day += tribes[0].dayDelta;

                        tribes.Sort(delegate(Tribe t1, Tribe t2)
                        {
                            return t1.day.CompareTo(t2.day);
                        });
                    }
                }

                Save("Case #" + (i + 1) + ": " + attacks + "\n");
            }
            Console.ReadKey();
        }

        private static void Save(string toSave)
        {
            File.AppendAllText(outputFolder + challenge + ".out", toSave);
        }

        private static void ClearFile()
        {
            File.WriteAllText(outputFolder + challenge + ".out", "");
        }
    }
}