using System;
using System.Collections.Generic;
using System.Linq;
public class Hello{
    public static void Main(){
        // Your code here!
        int N = int.Parse(Console.ReadLine());
        int[] array = Console.ReadLine().Split(' ').Select(x=>int.Parse(x)).ToArray();
        List<int> list = new List<int>();
        list.Add(0);
        list.AddRange(array);
        list.Add(0);
        var sum = 0;
        for(var i=1;i<N+2;i++){
            sum += Math.Abs(list[i] - list[i-1]);
        }
        int dif;
        for(var i=0;i<N;i++){
            dif = Math.Abs(list[i+1] - list[i]) + Math.Abs(list[i+2] - list[i+1]) - Math.Abs(list[i+2] - list[i]);
            Console.WriteLine(sum - dif);
        }
    }
}