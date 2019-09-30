using System;
using System.Collections.Generic;
public class Hello{
    public static void Main(){
        int n = int.Parse(Console.ReadLine());
        var Hash = new HashSet<int>();
        for(int i = 0;i < n;i++){
            int a = int.Parse(Console.ReadLine());
            Hash.Add(a);
        }
        Console.WriteLine(n - Hash.Count);
        
    }
}