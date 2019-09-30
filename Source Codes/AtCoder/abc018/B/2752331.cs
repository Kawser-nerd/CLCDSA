using System;
using System.Collections.Generic;
using System.Linq;
public class Hello{
    static string rev(string s){
        var ans = "";
        for(var i = s.Length - 1;i >= 0;i--){
            ans += s[i].ToString();
        }
        return ans;
    }
    public static void Main(){
        var s = Console.ReadLine();
        var n = int.Parse(Console.ReadLine());
        
        for(var i = 0;i < n;i++){
            var nums = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var temp = "";
            var start = nums[0] - 1;
            var end = nums[1] - 1;
            var len = end - start + 1;
            temp = rev(s.Substring(start,len));
            s = s.Substring(0,start) + temp + s.Substring(end + 1,s.Length - end - 1);
        }
        Console.WriteLine(s);
    }
}