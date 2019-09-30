using System;
public class Hello{
    public static void Main(){
        var s = Console.ReadLine();
        long ans = 0;
        long cnt = 0;
        for(int i = 0;i < s.Length;i++){
            if(s[i] == 'W'){
                ans += i - cnt;
                cnt++;
            }
        }
        Console.WriteLine(ans);
    }
}