using System;
using System.Collections.Generic;
using System.IO;

namespace ARC065D{
    public class Program{
        public static void Main(string[] args){
            var sr = new StreamReader();
            var sw = new StreamWriter(Console.OpenStandardOutput()){AutoFlush = false};
            //---------------------------------
            var N = sr.Next<int>();
            var K = sr.Next<int>();
            var L = sr.Next<int>();

            var qf = new QuickFind[2];
            qf[0] = new QuickFind(N);
            qf[1] = new QuickFind(N);

            for(var i = 0; i < K; i++){
                var p = sr.Next<int>() - 1;
                var q = sr.Next<int>() - 1;
                qf[0].Merge(p, q);
            }

            for(var i = 0; i < L; i++){
                var r = sr.Next<int>() - 1;
                var s = sr.Next<int>() - 1;
                qf[1].Merge(r, s);
            }

            Func<int, int, long> hash = (x, y) => x * 1000000L + y; 
            var dic = new Dictionary<long, int>();
            for(var i = 0; i < N; i++){
                var h = hash(qf[0].Group[i], qf[1].Group[i]);
                if(dic.ContainsKey(h))dic[h]++;
                else dic.Add(h, 1);
            }

            for(var i = 0; i < N; i++){
                var h = hash(qf[0].Group[i], qf[1].Group[i]);
                sw.Write(dic[h] + " ");
            }
            sw.WriteLine();
            //---------------------------------
            sw.Flush();
        }
    }

    public class Ex{
        public static void Swap<T>(ref T left, ref T right){
            var tmp = left;
            left = right;
            right = tmp;
        }

        public static void Fill<T>(ref T[] src, T val){
            for(var i = 0; i < src.Length; i++){
                src[i] = val;
            }
        }
    }

    public class QuickFind{
        //?????????????????
        public readonly int[] Group;
        public readonly List<int>[] Items;

        public QuickFind(int n){
            Group = new int[n];
            Items = new List<int>[n];
            for(var i = 0; i < n; i++){
                Group[i] = i;
                Items[i] = new List<int>{i};
            }
        }

        public void Merge(int x, int y){
            if(Items[Group[x]].Count < Items[Group[y]].Count) Ex.Swap(ref x, ref y);

            var gx = Group[x];
            var gy = Group[y];
            if(gx == gy) return;

            foreach(var iy in Items[gy]){
                Group[iy] = gx;
                Items[gx].Add(iy);
            }
        }

        public List<int> SameGroupItems(int x){
            return Items[Group[x]];
        }

        public bool IsSameGroup(int x, int y){
            return Group[x] == Group[y];
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