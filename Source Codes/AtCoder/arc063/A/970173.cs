using System;

namespace ARC063C{
    public class Program{
        public static void Main(string[] args){
            var S = Console.ReadLine();

            var res = 0;
            for(var i = 1; i < S.Length; i++){
                if(S[i - 1] != S[i]) res++;
            }

            Console.WriteLine(res);
        }
    }
}