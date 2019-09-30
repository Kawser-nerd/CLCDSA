using System;
public class Hello{
    public static void Main(){
        string s = Console.ReadLine();
        var ans = "";
        var i = 0;
        while(i < s.Length){
            var j = i;//????????
            while(i < s.Length && s[i] == s[j]){
                i++;
            }
            ans += s[j].ToString();
            ans += (i - j).ToString();
        }
        Console.WriteLine(ans);
        
    }
}