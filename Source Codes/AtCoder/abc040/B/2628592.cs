using System;
public class Hello{
    public static void Main(){
        int n = int.Parse(Console.ReadLine());
        int ans = n;
        for(var h = 1;h <= n;h++){
            int w = n / h;
            ans = Math.Min(ans,Math.Abs(h - w) + n - h * w);
        }
        Console.WriteLine(ans);
    
    }
}