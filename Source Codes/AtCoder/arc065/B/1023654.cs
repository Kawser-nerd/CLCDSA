using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Numerics;




namespace contest
{

    class contest
    {


        static void Main(string[] args)
        {
            //int n = int.Parse(Console.ReadLine());
            //var input = Console.ReadLine().Split().Select(int.Parse).ToArray();

            //var num = Console.ReadLine().Split().Select(int.Parse).ToArray();



            //int n = int.Parse(Console.ReadLine());


            //int n = int.Parse(Console.ReadLine());
            //var array = Console.ReadLine().Split().Select(int.Parse).ToArray();



            var num = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int n = num[0];
            int k = num[1];
            int l = num[2];

            var path = new Dictionary<int, HashSet<int>>();
            var rail = new Dictionary<int, HashSet<int>>();
            


            for (int i = 0; i < k; i++)
            {
                var tmp = Console.ReadLine().Split().Select(int.Parse).ToArray();
                int a = tmp[0];
                int b = tmp[1];

                if (!path.Keys.Contains(a)) path[a] = new HashSet<int>();
                if (!path.Keys.Contains(b)) path[b] = new HashSet<int>();

                path[a].Add(b);
                path[b].Add(a);
            }

            for (int i = 0; i < l; i++)
            {
                var tmp = Console.ReadLine().Split().Select(int.Parse).ToArray();
                int a = tmp[0];
                int b = tmp[1];

                if (!rail.Keys.Contains(a)) rail[a] = new HashSet<int>();
                if (!rail.Keys.Contains(b)) rail[b] = new HashSet<int>();
                
                rail[a].Add(b);
                rail[b].Add(a);

            }

            var memo = new bool[n + 1];
            var memoR = new bool[n+1];
            
            var p_node = new UnionFind(n + 1);
            var r_node = new UnionFind(n + 1);


            for(int i = 1; i<= n; i++)
            {
                int cur = i;
                //if (memo[cur]) continue;
                if (!memo[cur])
                {
                    var st = new Stack<int>();
                    st.Push(cur);
                    memo[cur] = true;


                    while (st.Count() > 0)
                    {
                        int tmp = st.Pop();
                        if (!path.Keys.Contains(tmp)) continue;
                        foreach (int item in path[tmp])
                        {

                            if (!memo[item])
                            {
                                st.Push(item);
                                p_node.unite(item, tmp);
                                memo[item] = true;
                            }
                        }

                    }
                }

                if(!memoR[cur])
                {

                    var st = new Stack<int>();
                    st.Push(cur);
                    memoR[cur] = true;


                    while (st.Count() > 0)
                    {
                        int tmp = st.Pop();
                        if (!rail.Keys.Contains(tmp)) continue;
                        foreach (int item in rail[tmp])
                        {
                            if (!memoR[item])
                            {
                                st.Push(item);
                                r_node.unite(item, tmp);
                                memoR[item] = true;

                            }


                        }

                    }
                }

            }


            



            //var pathRoot = new Dictionary<int, HashSet<int>>();
            //var rootDic = new Dictionary<int, List<int>>();
            var pairDic = new Dictionary<Tuple<int, int>, int>();
            var mm = new Tuple<int, int>[n+1];

            for (int i = 1; i < n + 1; i++)
            {                

                int cur = r_node.path[i];
                //if (!rootDic.Keys.Contains(cur)) rootDic[cur] = new List<int>();
                //rootDic[cur].Add(i);

                int tmp = p_node.path[i];
                if (!pairDic.Keys.Contains(Tuple.Create(tmp, cur))) pairDic[Tuple.Create(tmp, cur)] = 1;
                else pairDic[Tuple.Create(tmp, cur)]++;
                mm[i] = Tuple.Create(tmp,cur);
            }

            

            for(int i=1; i<n+1; i++)
            {
                //int a = p_node.path[i];
                //int b = r_node.path[i];
                //Console.Write(pairDic[Tuple.Create(a,b)]+" ");
                Console.Write(pairDic[mm[i]] + " ");
            }

            


 
        }




    }




    class UnionFind
    {
        public int[] path;
        

        public UnionFind(int n)
        {
            path = new int[n];
            
            for (int i = 0; i < n; i++)
            {
                path[i] = i;               
            }

        }

        private int root(int i)
        {
            while (i != path[i])
            {
                path[i] = path[path[i]];
                i = path[i];
            }
            return i;
        }

        

        public bool find(int p, int q)
        {
            return root(p) == root(q);
        }
              


        public void unite(int p, int q)
        {
            int i = root(p);
            int j = root(q);
            path[i] = j;
        }

       
    }
}