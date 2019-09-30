using System;
using System.Collections.Generic;
using System.Linq;
public class Hello{
    public static void Main(){
        int N = int.Parse(Console.ReadLine());
        int[] array = Console.ReadLine().Split(' ').Select(x=>int.Parse(x)).ToArray();
        List<int> list = new List<int>();
        list.Add(0);//??
        list.AddRange(array);
        list.Add(0);//??
        var sum = list.Zip(list.Skip(1), (prev, next) => Math.Abs(prev - next)).Sum();
        int dif;
        for(var i=0;i<N;i++){
            //??i~i+2??????i?????????????????????????
            dif = Math.Abs(list[i+1] - list[i]) + Math.Abs(list[i+2] - list[i+1]) - Math.Abs(list[i+2] - list[i]);
            Console.WriteLine(sum - dif);
        }
    }
}