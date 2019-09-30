using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class CrossingTheRoad
    {



        public static void Main(String[] args)
        {
            int n = int.Parse(System.Console.In.ReadLine());


            for (int i = 0; i < n; i++)
            {

                string firstLine = System.Console.In.ReadLine();
                string[] firstLineS = firstLine.Split(new char[] { ' ' });
                int N = int.Parse(firstLineS[0]);
                int M = int.Parse(firstLineS[1]);

                Queue<int> data = new Queue<int>();
                for (int j = 0; j < N; j++)
                {
                    string rowLine = System.Console.In.ReadLine();
                    string[] rowLineS = rowLine.Split(new char[] { ' ' });
                    
                    foreach (string s in rowLineS)
                    {
                        data.Enqueue(int.Parse(s));
                    }
                }
                CrossingTheRoad c = new CrossingTheRoad(N, M, data);

                System.Console.Out.WriteLine("Case #{0}: {1}", i+1, c.solve());
            }

        }

        int N, M;
        int[,] S, W, T;
        int rows, cols;


        List<KeyValuePair<int, int>> nodesToInspect = new List<KeyValuePair<int,int>>();
        public CrossingTheRoad(int N, int M, Queue<int> data)
        {
            this.N = N;
            this.rows = N * 2;
            this.M = M;
            this.cols = M * 2;
            this.S = new int[N, M];
            this.W = new int[N, M];
            this.T = new int[N, M];



            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    S[i, j] = data.Dequeue();
                    W[i, j] = data.Dequeue();
                    T[i, j] = data.Dequeue();
                }
            }
        }


        //Vertices and distances
        List<KeyValuePair<int, Vertex>> frontier = new List<KeyValuePair<int, Vertex>>();
        List<Vertex> seenVertices = new List<Vertex>();

        public int solve()
        {

            //visit initial position
            frontier.Add(new KeyValuePair<int, Vertex>(0, new Vertex(rows - 1, 0)));
            

            exploreNext();

            return result;
        }

        int result;

        private void exploreNext()
        {
            

            //Find the closest node in frontier
            KeyValuePair<int, Vertex> minKvp = frontier[0];
            foreach (KeyValuePair<int, Vertex> kvp in frontier)
            {
                if(kvp.Key < minKvp.Key) {
                    minKvp = kvp;
                }
            }
            frontier.Remove(minKvp);
            Vertex minV = minKvp.Value;

            if (seenVertices.Contains(minV))
            {
                exploreNext();
                return;
            }
            else
            {
                seenVertices.Add(minV);
            }



            //Termination case: if this is destination, then we're done
            if (minV.row == 0 && minV.col == cols - 1)
            {
                result = minKvp.Key;
                return;
            }

            //Consider all directions around this vertex
            for (int i = 0; i < 4; i++)
            {
                Vertex nextVertex;
                if (i == 0)//North
                    nextVertex = new Vertex(minV.row - 1, minV.col);
                else if(i==1) //East
                    nextVertex = new Vertex(minV.row, minV.col+1);
                else if (i==2)//South
                    nextVertex = new Vertex(minV.row + 1, minV.col);
                else //West
                    nextVertex = new Vertex(minV.row, minV.col - 1);

                //Check if within bounds
                if (nextVertex.row < 0 || nextVertex.row >= rows || nextVertex.col < 0 || nextVertex.col >= cols)
                    continue;

            
                int vertexTime;
                //Check if we are crossing road or block

                if (i == 0 || i == 2) //North South
                {

                    if (Math.Min(minV.row, nextVertex.row) % 2 == 0)
                    { //Crossing road
                        vertexTime = crossNSCost(minV.row / 2, minV.col / 2, minKvp.Key);
                    }
                    else
                    {
                        //Cross along block
                        vertexTime = minKvp.Key + 2;
                    }

                }
                else //East west
                {
                    if (Math.Min(minV.col, nextVertex.col) % 2 == 0)
                    { //Crossing road
                        vertexTime = crossWECost(minV.row / 2, minV.col / 2, minKvp.Key);
                    }
                    else
                    {
                        //Cross along block
                        vertexTime = minKvp.Key + 2;
                    }
                }

                KeyValuePair<int, Vertex> nextKvp = new KeyValuePair<int, Vertex>(vertexTime, nextVertex);

                frontier.Add(nextKvp);

            }
            //Recurse
            exploreNext();
        }

        // Returns the time after which a north crossing can and has been made
        private int crossNSCost(int n, int m, int curTime)
        {
            int cycle = S[n, m] + W[n, m];

            int relTime = (curTime - T[n, m]) % cycle;
            while (relTime < 0)
                relTime = relTime + cycle;
            
            if (relTime < S[n, m]) //Can cross right now
                return curTime + 1;
            else {//Have to wait for light to change
                int timeToWait = cycle - relTime;
                return curTime + timeToWait + 1;
            }
        }

        // Returns the time after which a north crossing can and has been made
        private int crossWECost(int n, int m, int curTime)
        {
            int cycle = S[n, m] + W[n, m];

            int relTime = (curTime - T[n, m]) % cycle;
            while (relTime < 0)
                relTime = relTime + cycle;

            
            if (relTime < S[n, m]) {//Have to wait for EW to turn on
                int timeToWait = S[n,m] - relTime;
             
                return curTime + timeToWait + 1;
            }
            else //Cross now
                return curTime + 1;
        }
    }
    public class Vertex
    {
        public int row, col;

        public Vertex(int i, int j)
        {
            this.row = i;
            this.col = j;
        }

        public override bool Equals(object obj)
        {
            Vertex objV = (Vertex)obj;
            return (objV.col == this.col && objV.row == this.row);
        }
    }
}
