using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace ARC063E{
    public class Program{
        //Atcoder Live ???????????
        public static void Main(string[] args){
            var sr = new StreamReader();
            //---------------------------------
            var N = sr.Next<int>();
            var dj = new Dijkstra(N + 1);
            for(var i = 0; i < N - 1; i++){
                var A = sr.Next<int>();
                var B = sr.Next<int>();
                dj.AddDirectedEdge(A, B, 1);
            }

            var K = sr.Next<int>();
            var dic = new Dictionary<int, int>();
            for(var i = 0; i < K; i++){
                var V = sr.Next<int>();
                var P = sr.Next<int>();
                dj.AddDirectedEdge(0, V, P);
                dic.Add(V, P);
            }

            var res = dj.Solve(0);
            if(dic.Keys.Any(v => res[v] != dic[v])){
                Console.WriteLine("No");
                return;
            }
            for(var i = 1; i <= N; i++){
                if(dj.Adj[i].Any(e => e.To != 0 && Math.Abs(res[i] - res[e.To]) != 1)){
                    Console.WriteLine("No");
                    return;
                }
            }

            Console.WriteLine("Yes");
            Console.WriteLine(string.Join("\n", res.Skip(1)));
            //---------------------------------
        }
    }

    public class Dijkstra{
        public class Edge{
            public int To;
            public int Cost;
        }

        public class Node : IComparable<Node>{
            public int Id;
            public int Cost;

            public int CompareTo(Node node){
                return Math.Sign(Cost - node.Cost);
            }
        }

        public readonly List<Edge>[] Adj;

        public Dijkstra(int v){
            Adj = new List<Edge>[v];
            for(var i = 0; i < v; i++) Adj[i] = new List<Edge>();
        }

        public void AddEdge(int from, int to, int cost){
            Adj[from].Add(new Edge{To = to, Cost = cost});
        }

        public void AddDirectedEdge(int v1, int v2, int cost){
            AddEdge(v1, v2, cost);
            AddEdge(v2, v1, cost);
        }

        public int[] Solve(int start){
            var v = Adj.Length;
            var dist = new int[v];

            for(var i = 0; i < v; i++) dist[i] = int.MaxValue;
            dist[start] = 0;

            var pq = new PriorityQueue<Node>();
            pq.Enqueue(new Node{Id = start, Cost = 0});

            while(pq.Count > 0){
                var node = pq.Dequeue();
                var from = node.Id;

                foreach(var edge in Adj[from]){
                    var to = edge.To;
                    var cost = node.Cost + edge.Cost;

                    if(cost >= dist[to]) continue;
                    dist[to] = cost;
                    pq.Enqueue(new Node{Id = to, Cost = cost});
                }
            }
            return dist;
        }
    }

    public class PriorityQueue<T> : IEnumerable<T> where T : IComparable<T>{
        private readonly List<T> _list = new List<T>();
        public int Count => _list.Count;

        IEnumerator<T> IEnumerable<T>.GetEnumerator(){
            return _list.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator(){
            return _list.GetEnumerator();
        }

        public void Clear(){
            _list.Clear();
        }

        public bool Contains(T value){
            return _list.Contains(value);
        }

        public T Peek(){
            return _list[0];
        }

        public void Enqueue(T value){
            _list.Add(value);
            PushHeap();
        }

        public T Dequeue(){
            var ret = _list[0];
            _list[0] = _list[Count - 1];
            _list.RemoveAt(Count - 1);
            PopHeap();
            return ret;
        }

        private void PushHeap(){
            var i = Count - 1;
            while(i != 0){
                var p = (i - 1) / 2;
                if(_list[i].CompareTo(_list[p]) > 0) return;

                SwapIndex(i, i = p);
            }
        }

        private void PopHeap(){
            var i = 0;
            while(true){
                var l = 2 * i + 1;
                var r = l + 1;

                var maxi = i;
                if(l < Count && _list[maxi].CompareTo(_list[l]) > 0) maxi = l;
                if(r < Count && _list[maxi].CompareTo(_list[r]) > 0) maxi = r;
                if(maxi == i) return;

                SwapIndex(i, i = maxi);
            }
        }

        private void SwapIndex(int left, int right){
            var tmp = _list[left];
            _list[left] = _list[right];
            _list[right] = tmp;
        }
    }

    public class StreamReader{
        private readonly char[] _c = {' '};
        private int _index = -1;
        private string[] _input = new string[0];
        private readonly System.IO.StreamReader _sr = new System.IO.StreamReader(Console.OpenStandardInput());

        public T Next<T>(){
            if(_index == _input.Length - 1){
                _index = -1;
                while(true){
                    string rl = _sr.ReadLine();
                    if(rl == null){
                        if(typeof(T).IsClass) return default(T);
                        return (T)typeof(T).GetField("MinValue").GetValue(null);
                    }
                    if(rl != ""){
                        _input = rl.Split(_c, StringSplitOptions.RemoveEmptyEntries);
                        break;
                    }
                }
            }
            return (T)Convert.ChangeType(_input[++_index], typeof(T), System.Globalization.CultureInfo.InvariantCulture);
        }

        public T[] Next<T>(int x){
            var ret = new T[x];
            for(var i = 0; i < x; ++i) ret[i] = Next<T>();
            return ret;
        }

        public T[][] Next<T>(int y, int x){
            var ret = new T[y][];
            for(var i = 0; i < y; ++i) ret[i] = Next<T>(x);
            return ret;
        }
    }
}