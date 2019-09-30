using System;
using System.Collections.Generic;
using System.Linq;
public class Hello{
    public static void Main(){
        var nums = new List<int>();
        var sortedList= new List<int>();
        for(var i = 0;i < 3;i++){
            var n = int.Parse(Console.ReadLine());
            nums.Add(n);
            sortedList.Add(n);
        }
        sortedList.Sort();
        sortedList.Reverse();
        for(var i = 0;i < 3;i++){
            Console.WriteLine(sortedList.IndexOf(nums[i]) + 1);
        }
        
    }
}