using System;

namespace ARC050A{
    public class Program{
        public static void Main(string[] args){
            var sr = new StreamReader();
            //---------------------------------
            Console.WriteLine(sr.Next<char>() - sr.Next<char>() == -1 << 5? "Yes" : "No");
            //---------------------------------
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
    }
}