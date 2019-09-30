using System;
using System.Linq;
using System.Collections.Generic;
public class Hello{
    public static void Main(){
        var line = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        var n = line[0];
        var p = line[1];
        var ans = 0L;
        var biscuits = Console.ReadLine().Split(' ').Select(long.Parse).ToList();
        
        if(biscuits.Count(x => x % 2 == 0) == n){
            if(p == 0){
                Console.WriteLine((long)Math.Pow(2,n));
            }else{
                Console.WriteLine(0);
            }
        }else{
            Console.WriteLine((long)Math.Pow(2,n - 1));
        }
    }
}