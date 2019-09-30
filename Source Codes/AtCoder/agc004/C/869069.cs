using System;

namespace AGC004C{
    public class Program{
        public static void Main(string[] args){
            var sr = new StreamReader();
            //---------------------------------
            var H = sr.Next<int>();
            var W = sr.Next<int>();
            var A = sr.Next<string>(H);

            var rmap = new char[H, W].ToJaggedArray();
            var bmap = new char[H, W].ToJaggedArray();

            for(var i = 0; i < H; i++){
                for(var j = 0; j < W; j++){
                    if(A[i][j] == '#'){
                        rmap[i][j] = '#';
                        bmap[i][j] = '#';
                        continue;
                    }

                    if(i == 0 || (i != H - 1 && j % 2 == 0)){
                        rmap[i][j] = '#';
                    } else{
                        rmap[i][j] = '.';
                    }

                    if(i == H - 1 || (i != 0 && j % 2 == 1)){
                        bmap[i][j] = '#';
                    } else{
                        bmap[i][j] = '.';
                    }
                }
            }

            Array.ForEach(bmap, Console.WriteLine);
            Console.WriteLine();
            Array.ForEach(rmap, Console.WriteLine);
            //---------------------------------
        }
    }

    public static class ExMethod{
        public static T[][] ToJaggedArray<T>(this T[,] src){
            var x = src.GetLength(1);
            var y = src.GetLength(0);
            var ret = new T[y][];

            for(var i = 0; i < y; i++){
                ret[i] = new T[x];
                for(var j = 0; j < x; j++){
                    ret[i][j] = src[i, j];
                }
            }

            return ret;
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