using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;


class Program
{
    static void Main(string[] Args) {
        ReadLine(); //N
        var T = new List<string>(Console.ReadLine().Split(' ')).Select(ele => Int32.Parse(ele)).ToList();
        int M = Int32.Parse(ReadLine());
        List<KeyValuePair<int, int>> DrinkData = new List<KeyValuePair<int, int>>(); //Pi,Xi
        for(int Count = 0;Count < M; Count++) {
            var v = new List<string>(ReadLine().Split(' ')).Select(ele => Int32.Parse(ele)).ToArray();
            DrinkData.Add(new KeyValuePair<int, int>(v[0], v[1]));
        }

        List<int> Result = new List<int>();
        foreach(var ele in DrinkData) {
            int Result_Tmp = 0;
            for(int Count = 0;Count < T.Count(); Count++) {
                int Plus = 0;
                if (ele.Key - 1 == Count) Plus = ele.Value;
                else Plus = T[Count];
                Result_Tmp += Plus;
            }
            Result.Add(Result_Tmp);
        }

        foreach(var ele in Result) {
            WriteLine(ele);
        }

        ReadLine();
    }
}