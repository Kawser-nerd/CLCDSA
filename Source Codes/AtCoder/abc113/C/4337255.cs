using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC113_C{
    class Program{
        static void Main(string[] args){
            int[] s = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
            int[][] arr = new int[s[1]][];
            int[] h = new int[s[0] + 1];

            for(var i = 0;i < s[1];i++){
                arr[i] = Array.ConvertAll((Console.ReadLine() + " " + i.ToString()).Split(' '),int.Parse);
            }

            Array.Sort(arr,(u,v) => u[1] - v[1]);
            for(var i = 0;i < s[1];i++){
                h[arr[i][0]]++;
                arr[i][1] = h[arr[i][0]];
            }
            Array.Sort(arr,(u,v) => u[2] - v[2]);

            for(var i = 0;i < s[1];i++){
                Console.WriteLine("{2}{0}{3}{1}",arr[i][0],arr[i][1],new string('0',6 - arr[i][0].ToString().Length),new string('0',6 - arr[i][1].ToString().Length));
            }
        }
    }
}