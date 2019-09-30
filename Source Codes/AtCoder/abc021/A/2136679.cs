using System;
using System.Collections.Generic;
public class Hello{
    public static void Main(){
        int N = int.Parse(Console.ReadLine());
        int count = 0;
        var list = new List<int>();
        while(N > 0){
            if(N - 2 >= 1){
                list.Add(2);
            }else{
                list.Add(1);
            }
            count++;
            N -= 2;
        }
        Console.WriteLine(count);
        foreach(int i in list){
            Console.WriteLine(i);
        }
    }
}