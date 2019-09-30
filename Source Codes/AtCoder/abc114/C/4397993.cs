using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;


class Program
{
    static bool isUsedAll(List<int> value) {
        bool[] result = { false, false, false };
        foreach(int x in value) {
            result[x] = true;
        }
        return result[0] && result[1] && result[2];
    }

    static int[] sins = { 3, 5, 7 };

    static int Result_Count = 0;
    static int N = 0;

    static void DFS(int target_depth,int depth,List<int> value) {
        if(target_depth == depth) {
            if (!isUsedAll(value)) return;
            long Val = 0;
            for(int c = 0;c < value.Count; c++) {
                Val += sins[value[c]] * (int)Math.Pow(10, c);
            }
            if (Val <= N && Val >= 0) {
                Result_Count++;
            }
            return;
        }
        for(int i = 0;i < 3; i++) {
            List<int> clone = new List<int>(value.ToArray());
            clone.Add(i);
            DFS(target_depth, depth + 1, clone);
        }
    }

    static void Main(string[] Args) {
        N = Int32.Parse(ReadLine());

        for(int Depth = 1 ; Depth <= 10; Depth++) {
            DFS(Depth, 0, new List<int>());
        }

        WriteLine(Result_Count);

        ReadLine();
    }
}