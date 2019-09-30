using System;
using System.Collections.Generic;
using System.Linq;
 
namespace atcoder{
    class edge{
        public int to, rev, cap;
        public edge(int to_, int rev_, int cap_){
            to = to_;
            rev = rev_;
            cap = cap_;
        }
    }
 
    class prob10{
        static List<edge>[] G;
        static int[] level;
        static int n;
        readonly static int inf=1<<30;
 
        static bool levelize(int s, int t){
            var q = new Queue<int>();
            level = Enumerable.Repeat(-1, 105).ToArray();
            q.Enqueue(s);
            level[s] = 0;
            while(q.Any()){
                var now = q.Dequeue();
                foreach(var e in G[now]){
                    if(e.cap>0 && level[e.to]==-1){
                        level[e.to] = level[now]+1;
                        q.Enqueue(e.to);
                    }
                }
            }
            return level[t]!=-1;
        }
 
        static int flow(int s, int t, int lim){
            if(s==t)
                return lim;
            int total = 0;
            foreach(var e in G[s]){
                if(e.cap>0 && level[e.to]>level[s]){
                    int f = flow(e.to, t, Math.Min(lim, e.cap));
                    e.cap -= f;
                    G[e.to][e.rev].cap += f;
                    lim -= f;
                    total += f;
                    if(lim==0)
                        break;
                }
            }
            return total;
        }
 
        public static int Main(){
            var any = Console.ReadLine().Split().Select(x=>int.Parse(x)).ToArray();
            n = any[0];
            G = new List<edge>[105];
            foreach(var i in Enumerable.Range(0,n+1)){
                G[i] = new List<edge>();
            }
            var gs = Console.ReadLine();
            if(any[1]>0){
                foreach(var p in gs.Split().Select(x=>int.Parse(x))){
                    G[p].Add(new edge(n, G[n].Count, 1));
                    G[n].Add(new edge(p, G[p].Count-1, 0));
                }
            }
            foreach(var _ in Enumerable.Range(0, any[2])){
                var ab = Console.ReadLine().Split().Select(x=>int.Parse(x)).ToArray();
                G[ab[0]].Add(new edge(ab[1], G[ab[1]].Count, 1));
                G[ab[1]].Add(new edge(ab[0], G[ab[0]].Count-1, 1));
            }
 
            int res = 0;
            while(levelize(0, n)){
                /*
                Console.Write("?????");
                G[0].ForEach(e=>Console.Write(e.cap));
                Console.WriteLine();
                Console.WriteLine(res);
                Console.WriteLine(string.Join(",", level));
                */
                res += flow(0, n, inf);
            }
            Console.WriteLine(res);
 
            return 0;
        }
    }
}