using System;
using System.Collections.Generic;
using System.Linq;
class P{
    static void Main(){
        int[] hw = Console.ReadLine().Split().Select(int.Parse).ToArray();
        char[][] a = new char[hw[0]][];
        for (int i = 0;i < hw[0];i++)
            a[i] = Console.ReadLine().ToCharArray();
        var i1 = new SortedSet<int>();
        var i2 = new SortedSet<int>();
        for (int i = 0;i < hw[0];i++){
            for (int j = 0;j < hw[1];j++){
                if (a[i][j] == '#'){
                    i1.Add(i);
                    i2.Add(j);
                }
            }
        }
        foreach (var j1 in i1){
            foreach (var j2 in i2){
                Console.Write(a[j1][j2]);
            }
            Console.WriteLine();
        }
    }
}