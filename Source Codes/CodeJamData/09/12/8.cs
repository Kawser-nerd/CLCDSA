using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Round1A
{
    class ProblemB
    {
        static string[] text;
        static int at;
        static TextWriter output;
        static void Main(string[] args)
        {
            using (output = new StreamWriter("output.txt"))
            {
                text = File.ReadAllLines("B.in");
                at = 0;
                int n = ReadInt();
                for (int i = 0; i < n; i++)
                    Solve(i + 1);
            }
        }

        static void Solve(int caseNumber)
        {
            int min = FindMin();
            OutputLine("Case #" + caseNumber + ": "+min);
        }

        internal static int TimeIndex = 0;
        static int FindMin()
        {
            int[] size = ReadInts();
            int n = size[0]; //horizontal road count / rows
            int m = size[1]; //vertical road count / cols
            Light[,] lights=new Light[n,m];
            for (int r = 0; r < n; r++)
            {
                //0,0 has to go through intersection, 0,1 can see 0,2
                int[] data = ReadInts();
                for (int c = 0; c < m; c++)
                    lights[r,c]=new Light(data[3*c], data[3*c+1], data[3*c+2]);
            }

            Dictionary<int, bool[,]> reached=new Dictionary<int, bool[,]>();
            bool[,] origin=new bool[2*n,2*m];
            origin[2*n-1,0]=true;
            reached[0] = origin;

            for (int i = 1; ; i++)
            {
                TimeIndex = i;
                bool[,] current=new bool[2*n,2*m];
                bool[,] prev = reached[i - 1];
                //if we could get somewhere, we can wait there
                for (int r = 0; r < 2*n; r++)
                    for (int c = 0; c < 2*m; c++)
                        current[r, c] = prev[r, c];

                //we can cross lights by wasting only 1 minute, reusing prev
                for (int r = 0; r < n; r++)
                    for (int c = 0; c < m; c++)
                    {
                        int north=2*r;
                        int south = 2 * r + 1;
                        int west=2*c;
                        int east = west + 1;
                        Light light = lights[r, c];
                        if (light.SouthActiveAt(i-1))
                        {
                            current[north, east] |= prev[south, east];
                            current[south, east] |= prev[north, east];
                            current[north, west] |= prev[south, west];
                            current[south, west] |= prev[north, west];
                        }
                        else
                        {
                            current[north, east] |= prev[north, west];
                            current[south, east] |= prev[south, west];
                            current[north, west] |= prev[north, east];
                            current[south, west] |= prev[south, east];
                        }
                    }

                if (i >= 2)
                {
                    prev = reached[i - 2];
                    //we can walk along distance 2 paths
                    for (int r = 0; r < 2*n; r++)
                        for (int c = 0; c < 2*m; c++)
                        {
                            int nr = r%2 == 0 ? r - 1 : r + 1;
                            if (nr >= 0 && nr < 2 * n)
                                current[r, c] |= prev[nr, c];
                            int nc = c % 2 == 0 ? c - 1 : c + 1;
                            if (nc >= 0 && nc < 2 * m)
                                current[r, c] |= prev[r, nc];
                        }
                }
                reached[i] = current;
                if(current[0,2*m-1])
                    return i; //because we're working with indicies, and we want a length
            }
        }

        static int ReadInt()
        {
            return ReadInts()[0];
        }

        static int[] ReadInts()
        {
            string line = text[at++];
            string[] bits = line.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int[] ret=new int[bits.Length];
            for (int i = 0; i < bits.Length; i++)
                ret[i] = Int32.Parse(bits[i]);
            return ret;
        }

        static void OutputLine(string line)
        {
            Console.WriteLine(line);
            output.WriteLine(line);
        }

        static void Output(string line)
        {
            Console.Write(line);
            output.Write(line);
        }
    }

    class Light
    {
        private long ss, ww, tt, cycle;
        public Light(long s, long w, long t)
        {
            ss=s;
            ww=w;
            tt=t;
            cycle=ss+ww;
            tt %= cycle;
        }

        public bool SouthActiveAt(long i)
        {
            i-=tt;
            if(i<0)
                i+=cycle;
            long diff=i%cycle;
            return diff<ss;
        }

        public bool WestActiveAt(long i)
        {
            return !SouthActiveAt(i);
        }

        public override string ToString()
        {
            return "S: " + SouthActiveAt(ProblemB.TimeIndex);
        }
    }
}
