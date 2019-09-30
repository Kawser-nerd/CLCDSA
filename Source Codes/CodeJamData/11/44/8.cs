using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2P3
{
    class Program
    {
        class Planet
        {
            public int value=-1;
            public List<int> threaten = new List<int>();
            public List<int> wormholes = new List<int>();
        }
        static List<int> JoinThreats(List<int> one, List<int> two,int otha, int hole)
        {
            List<int> newList = new List<int>();
            for (int i = 0; i < one.Count; i++)
            {
                newList.Add(one[i]);
            }
            for (int i = 0; i < two.Count; i++)
            {
                if (newList.IndexOf(two[i]) == -1)
                    newList.Add(two[i]);
            }
            newList.Remove(otha);
            newList.Remove(hole);
            return newList;
        }
        static void Main(string[] args)
        {
            StreamReader input = new StreamReader("input.txt");
            StreamWriter output = new StreamWriter("output.txt");
            int T = Convert.ToInt32(input.ReadLine());
            for (int t = 0; t < T; t++)
            {
                string[] line = input.ReadLine().Split(' ');
                int p = Convert.ToInt32(line[0]);
                int w = Convert.ToInt32(line[1]);
                List<Planet> planets = new List<Planet>();
                //create planets, blank
                for (int i = 0; i < p; i++)
                {
                    planets.Add(new Planet());
                }
                //load wormholes
                string[] wormholes = input.ReadLine().Split(' ');
                for (int i = 0; i < w; i++)
                {
                    int one = Convert.ToInt32(wormholes[i].Split(',')[0]);
                    int two = Convert.ToInt32(wormholes[i].Split(',')[1]);
                    if (one != two)
                    {
                        planets[one].wormholes.Add(two);
                        planets[two].wormholes.Add(one);
                    }
                }
                List<Planet> openSet = new List<Planet>();
                openSet.Add(planets[0]);
                planets[0].value = 0;
                planets[0].threaten = planets[0].wormholes;
                //while (openSet.Count>0&&openSet[0] != planets[1])
                while (openSet[0] != planets[1])
                {
                    foreach (int hole in openSet[0].wormholes)
                    {
                        if (planets[hole].value == -1)
                        {
                            planets[hole].value = openSet[0].value + 1;//smallest path to the end
                            //search the planet's wormholes to see if there's a planet to it that threatens more planets
                            if (hole == 1)
                            {
                                int threaten = 0;
                                foreach (int otha in planets[hole].wormholes)
                                {
                                    if (planets[otha].value == openSet[0].value)
                                    {
                                        List<int> newThreat = planets[otha].threaten;
                                        if (newThreat.Count > threaten)
                                        {
                                            threaten = newThreat.Count;
                                            planets[hole].threaten = newThreat;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                int threaten = 0;
                                foreach (int otha in planets[hole].wormholes)
                                {
                                    if (planets[otha].value == openSet[0].value)
                                    {
                                        List<int> newThreat = JoinThreats(planets[otha].threaten, planets[hole].wormholes, otha, hole);
                                        if (newThreat.Count > threaten)
                                        {
                                            threaten = newThreat.Count;
                                            planets[hole].threaten = newThreat;
                                        }
                                    }
                                }
                            }
                            openSet.Add(planets[hole]);
                            //now we have threats and smallest path, we're good

                        }
                    }
                    openSet.RemoveAt(0);
                    openSet.Sort((x, y) => x.value.CompareTo(y.value));
                }
                output.WriteLine("Case #{0}: {1} {2}", t + 1, planets[1].value-1, planets[1].threaten.Count);
            }
            output.Close();
        }
    }
}
