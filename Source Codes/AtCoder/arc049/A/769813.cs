using System;
using System.Linq;

namespace ARC049A{
    public class Program{
        public static void Main(string[] args){
            var sr = new StreamReader();
            //---------------------------------
            var S = sr.Next<string>();
            var A = sr.Next<int>(4);

            Console.WriteLine(A.OrderByDescending(x => x).Aggregate(S, (c, a) => c.Insert(a, "\"")));
            //---------------------------------
        }
    }

    public class StreamReader{
        private readonly char[] _c = {' '};
        private int _index = -1;
        private string[] _input = new string[0];

        public T Next<T>(){
            if(_index == _input.Length - 1){
                _index = -1;
                while(true){
                    string rl = Console.ReadLine();
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
    }
}