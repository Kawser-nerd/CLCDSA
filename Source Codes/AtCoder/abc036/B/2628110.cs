using System;
public class Hello{
    public static void Main(){
        int n = int.Parse(Console.ReadLine());
        string[] s = new string[n];
        string ans = "";
        
        for(var i = 0;i < n;i++){
            s[i] = Console.ReadLine();
        }
        
        for(var j = 0;j < n;j++){
            for(var k = n - 1;k >= 0;k--){
                ans += s[k][j].ToString();
            }
            ans += "\n";
        }
        Console.WriteLine(ans);
    }
}