using System;
using System.Collections.Generic;

namespace codejam2014
{

    public class problemc{
        public int n,m;
        public bool [,] conn;
        public string[] zip;
        public int[] zipx;

        public int [] parent;
        public int start ,current;

        bool [] visited;
      

        public void visit(int node)
        {
            visited[node] = true;
            for(int i = 0; i<n; i++)
            {
                if (conn[node, i] && visited[i] == false)
                    visit(i);
            }
        }

        bool valid()
        {
    
            if (visited == null)
                visited = new bool[n];
            else
                for(int i = 0; i<n; i++)
                    visited[i] = parent[i] != -1;

            for(int i = current; i != -1; i = parent[i])
                visited[i] = true;
                
            for(int i = current; i != -1; i = parent[i])
                visit(i);

            for(int i = 0; i<n; i++)
                if (visited[i] == false) 
                    return false;

            return true;
        }

        public string solve()
        {
            parent = new int[n];
            zipx = new int[n];
            for(int i = 0;i<n;i++)
            {
                parent[i] = -1;
                zipx[i] = int.Parse(zip[i]);
            }

            start = 0;
            for(int i = 1; i<n; i++)
                if (zipx[i] < zipx[start])
                    start = i;

            current = start;

            string ret = zip[start];

            while (ret.Length < 5 * n)
            {
                int oldcurrent = current;
                int best = -1;
                int besti = -1;

                for(int i = current; i != -1; i = parent[i])
                {
                    for(int j = 0; j<n; j++)
                    {
                        if (parent[j] != -1 || j == start) continue;
                        if (conn[i,j] == false) continue;

                        parent[j] = i;
                        current = j;
                        bool isvalid = valid();
                        current = oldcurrent;
                        parent[j] = -1;

                        if (isvalid && (best == -1 || zipx[j] < zipx[best]))
                        {
                            best = j;
                            besti = i;
                        }
                    }
                }

                current = best;
                parent[best] = besti;
                ret = ret + zip[best];
            }



            return ret;
        }
    }

    class MainClass
    {


        public static void Main(string[] args)
        {

            System.IO.TextReader r = new System.IO.StreamReader(args[0]);

            int t = int.Parse(r.ReadLine());

            for(int c = 1; c<=t; c++)
            {
                problemc p = new problemc();
                string [] x = r.ReadLine().Split(' ');
                p.n = int.Parse(x[0]);
                p.m = int.Parse(x[1]);

                p.zip = new string[p.n];



                for(int i =0 ; i<p.n; i++)
                    p.zip[i] = r.ReadLine();

                p.conn = new bool[p.n, p.n];

                for(int i = 0; i<p.m; i++)
                {
                    x = r.ReadLine().Split(' ');
                    int a = int.Parse(x[0])-1;
                    int b = int.Parse(x[1])-1;
                    p.conn[a,b] = p.conn[b,a] = true;
                }

                string ret = p.solve();
                Console.WriteLine("Case #{0}: {1}", c, ret);

            }

            r.Close();

        }
    }
}

