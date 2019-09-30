using System;
using System.Linq;

public class Hello{
    public static void Main(){
        var n = int.Parse(Console.ReadLine());
        var arr = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var ans = 1L;
        var m = 1L;
        for(var i = 1;i < n;i++){
            if(arr[i - 1] < arr[i]){
                m++;
            }else{
                m = 1;
            }
            ans += m;
        }
        Console.WriteLine(ans);
    }
}