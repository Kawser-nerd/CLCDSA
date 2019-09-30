using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Problem3
    {
        static StreamReader Input;
        static StreamWriter Output;

        static void Main(string[] args)
        {
            string classname = MethodBase.GetCurrentMethod().DeclaringType.Name;
            string testcase = Console.ReadLine();

            Input = new StreamReader("input/" + classname + "-" + testcase + ".txt");
            Output = new StreamWriter("output/" + classname + "-" + testcase + ".txt");

            int testcases = Convert.ToInt32(Input.ReadLine());

            for (int t = 1; t <= testcases; t++)
            {
                int n = Convert.ToInt32(Input.ReadLine());
                List<Tribe> tribes = new List<Tribe>();
                int[] wall = new int[2000];

                for (int i = 0; i < n; i++)
                {
                    string input = Input.ReadLine();

                    Tribe tribe = new Tribe(input);

                    tribes.Add(tribe);
                }

                int success = 0;
                while (tribes.Count > 0)
                {
                    tribes = tribes.OrderBy(x => x.NextAttack).ToList();

                    Tribe next = tribes[0];
                    int time = next.NextAttack;

                    foreach (Tribe tr in tribes.Where(x => x.NextAttack == time))
                    {
                        if (tr.DoAttack(wall))
                            ++success;
                    }

                    foreach (Tribe tr in tribes.Where(x => x.NextAttack == time))
                    {
                        tr.BuildWall(wall);
                        tr.Move();
                    }

                    List<Tribe> toRemove = new List<Tribe>();
                    foreach (Tribe tr in tribes.Where(x => x.AttacksLeft == 0))
                    {
                        toRemove.Add(tr);
                    }
                    foreach (Tribe tr in toRemove)
                    {
                        tribes.Remove(tr);
                    }
                }                

                Output.WriteLine("Case #{0}: {1}", t, success);
            }

            Output.Close();
        }
    }

    class Tribe
    {
        public int NextAttack { get; set; }
        public int AttacksLeft { get; set; }
        public int West { get; set; }
        public int East { get; set; }
        public int Strength { get; set; }

        private int deltaDays;
        private int deltaDistance;
        private int deltaStrength;

        public Tribe(string line)
        {
            string[] splitted = line.Split(' ');

            NextAttack = Convert.ToInt32(splitted[0]);
            AttacksLeft = Convert.ToInt32(splitted[1]);
            West = Convert.ToInt32(splitted[2]);
            East = Convert.ToInt32(splitted[3]);
            Strength = Convert.ToInt32(splitted[4]);
            deltaDays = Convert.ToInt32(splitted[5]);
            deltaDistance = Convert.ToInt32(splitted[6]);
            deltaStrength = Convert.ToInt32(splitted[7]);
        }

        internal bool DoAttack(int[] wall)
        {
            for (double i = West; i <= East; i += 0.5)
            {
                if (wall[Convert.ToInt32(i * 2) + 1000] < Strength)
                {
                    return true;
                }                
            }

            return false;
        }

        internal void BuildWall(int[] wall)
        {
            for (double i = West; i <= East; i += 0.5)
            {
                wall[Convert.ToInt32(i * 2) + 1000] = Math.Max(wall[Convert.ToInt32(i * 2) + 1000], Strength);
            }
        }

        internal void Move()
        {
            NextAttack += deltaDays;
            AttacksLeft -= 1;
            West += deltaDistance;
            East += deltaDistance;
            Strength += deltaStrength;
        }
    }
}
