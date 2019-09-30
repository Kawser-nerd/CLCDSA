using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamR1C1
{
    class Program
    {
        static void Main(string[] args)
        {


            StreamReader sr = new StreamReader(@"D:\codejam\A-small-attempt0.in");
            StreamWriter sw = new StreamWriter(@"D:\codejam\output.txt");

            int T = Int32.Parse(sr.ReadLine());

           

            for (int t = 0; t < T; t++)
            {
                int N = Int32.Parse(sr.ReadLine());

                Node[] nodes = new Node[N];
                int[] inD = new int[N];
                bool[] visited = new bool[N];

                for (int i = 0; i < N; i++)
                {
                    String[] temp = sr.ReadLine().Split(' ');
                    int Mi = Int32.Parse(temp[0]);


                    int[] father = new int[Mi];
                    for (int j = 0; j < Mi; j++)
                    {
                        father[j] = Int32.Parse(temp[j + 1]) - 1;
                        inD[father[j]]++;
                    }                 

                    nodes[i] = new Node(father,i,N);
                    visited[i] = false;
                }

                bool result=false;
                for (int i = 0; i < N; i++)
                {
                    int nid;
                    for (nid = 0; nid < N; nid++)
                        if (visited[nid] == false && inD[nid] == 0)
                            break;


                    foreach (int fid in nodes[nid].fathers)
                    {
                        for (int j = 0; j < N; j++)
                        {
                            if (nodes[nid].reach[j] && nodes[fid].reach[j])
                                result = true;

                            nodes[fid].reach[j] = (nodes[fid].reach[j] | nodes[nid].reach[j]);

                        }

                        inD[fid]--;
                       

                    }

                    visited[nid] = true;
                }

                if (result)
                    sw.WriteLine("Case #"+(t+1)+": Yes");
                else
                    sw.WriteLine("Case #" + (t + 1) + ": No");

            }

            sr.Close();
            sw.Close();
        }
    }

    class Node
    {
        public int[] fathers;

        public bool[] reach;


        public int id;

        public Node(int[] fathers,int now,int N)
        {
            this.fathers = fathers;
            this.id = now;

            reach = new bool[N];

            for (int i = 0; i < N; i++)
            {
                if (i == id)
                    reach[i] = true;
                else
                    reach[i] = false;
            }
        }
    }
}
