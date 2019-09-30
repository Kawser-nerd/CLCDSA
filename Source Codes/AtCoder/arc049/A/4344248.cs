using System;
using System.Collections.Generic;
using System.Linq;
public class Hello{
    public static void Main(){
        var s = Console.ReadLine();
        var nums = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var list = new List<char>();
        foreach(var i in s){
            list.Add(i);
        }
        for(var i = 0;i < nums.Length;i++){
            list.Insert(nums[i] + i,'"');
        }
        var ans = string.Join("",list);
        Console.WriteLine(ans);
        
    }
}