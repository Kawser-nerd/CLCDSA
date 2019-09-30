using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
namespace R211A
{
    class Program
    {
        static List<string> outLines = new List<string>();

        static string file = "D-large";
        static void Main(string[] args)
        {
            StreamReader f = new StreamReader(file + ".in");
            string s = f.ReadLine();
            string[] subs = s.Split(' ');
            s = subs[0];
            int numCase = int.Parse(s);
            //s = subs[1];
            //int numSetup = int.Parse(s);
            //s = subs[2];
            //int someConstant = int.Parse(s);
            //for (int i = 0; i < numSetup; i++)
            //{
            ////create some sort of data structure to use
            //}
            for (int i = 0; i < numCase; i++)
            {
                subs = f.ReadLine().Split(' ');
                s = subs[0];
                int numPlanet = int.Parse(s);
                s = subs[1];
                int numHole = int.Parse(s);
                List<int>[] Planets = new List<int>[numPlanet];
                for(int j = 0; j < numPlanet; j++)
                    Planets[j] = new List<int>();
                subs = f.ReadLine().Split(' ');
                string[] sub2;
                for(int j = 0; j < numHole; j++)
                {
                    sub2 = subs[j].Split(',');
                    int a = int.Parse(sub2[0]);
                    int b = int.Parse(sub2[1]);
                    Planets[a].Add(b);
                    Planets[b].Add(a);
                }
                // get all the data for your case here
                computeCase(i + 1, numPlanet, numHole, Planets);
            }
            f.Close();



            StreamWriter output = new StreamWriter(file + ".out");
            foreach (string l in outLines)
            {
                output.WriteLine(l);
            }
            output.Close();
        }
        public static int Overlap(int a, int b, List<int>[] P)
        {
            int ret = 0;
            if (a < 0 || b < 0)
                return 1;
            foreach (int x in P[a])
            {
                if (P[b].Contains(x))
                    ret++;
            }
            return ret;
        }
        public static void computeCase(int c, int nP, int nH, List<int>[] Planets)
        {
            if (c == 19)
                c = 19;
            int[] distance = new int[nP];
            int[] visit = new int[nP];
            List<int>[] threats = new List<int>[nP];
            List<int>[] before = new List<int>[nP];
            for (int i = 0; i < nP; i++)
            {
                distance[i] = -1;
                visit[i] = 0;
                threats[i] = new List<int>();
                before[i] = new List<int>();
            }
            distance[0] = 0;
            threats[0].Add(Planets[0].Count - 1);
            before[0].Add(-1);
            int conquer = 0;
            int threaten = 0;
           
            int y = 0;
            while (distance[1] < 0 || distance[1] >= y)
            {
                int x = 0;
                y = nP + 2;
                for (int i = 0; i < nP; i++)
                {
                    if (distance[i] < y && distance[i] >= 0 && visit[i] < 1)
                    {
                        x = i;
                        y = distance[i];
                    }
                }
                visit[x] = 1;
                foreach (int i in Planets[x])
                {
                    if (distance[i] < 0 || distance[i] > distance[x] + 1 )
                    {
                        int a = 0;
                        int b = 0;
                        for(int q = 0; q < before[x].Count; q++)
                        {
                            int z = threats[x][q] + Planets[i].Count - 2 - Overlap(i, x, Planets) - Overlap(i, before[x][q], Planets) + 1;
                            if (z > a)
                            {
                                a = z;
                                b = q;
                            }
                        }
                        threats[i].Clear();
                        before[i].Clear();
                        threats[i].Add(a);
                        before[i].Add(x);
                        if (i == 1)
                            threaten = threats[x].Max() + 1;
                        distance[i] = distance[x] + 1;
                    }
                    else if (distance[i] == distance[x] + 1)
                    {
                        int a = 0;
                        int b = 0;
                        for (int q = 0; q < before[x].Count; q++)
                        {
                            int z = threats[x][q] + Planets[i].Count - 2 - Overlap(i, x, Planets) - Overlap(i, before[x][q], Planets) + 1;
                            if (z > a)
                            {
                                a = z;
                                b = q;
                            }
                        }
                        
                        threats[i].Add(a);
                        before[i].Add(x);
                        if (i == 1)
                            threaten = Math.Max(threaten, threats[x].Max() + 1);
                        distance[i] = distance[x] + 1;
                    }
                }
            }
            conquer = distance[1] - 1;
            

            
            outLines.Add("Case #" + c.ToString() + ": " + conquer.ToString() + " " + threaten.ToString());


        }
        
    }
    
}
