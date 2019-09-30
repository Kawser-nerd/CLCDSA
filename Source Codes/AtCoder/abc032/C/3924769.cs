using System;
using System.Collections.Generic;
using System.Linq;
public class Hello{
    public static void Main(){
        var input = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        var n = input[0];
        var k = input[1];
        var list = new List<long>();
        for(var i = 0;i < n;i++){
            list.Add(long.Parse(Console.ReadLine()));
        }
        
        if(list.Contains(0)){
            Console.WriteLine(n);
            return;
        }
        if(list.Count(x => x <= k) == 0){
            Console.WriteLine(0);
            return;
        }
        
        var r = 0;
        var l = 0;
        long temp = 1L;
        var ans = 0L;
        
        while(r < n){
            temp *= list[r];
            
            while(temp > k){
                temp /= list[l];
                l++;
            }
            ans = Math.Max(ans,r - l + 1);
            r++;
        }
        Console.WriteLine(ans);
    }
}