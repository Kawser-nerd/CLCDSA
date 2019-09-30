using System;
public class Hello{
    public static void Main(){
        string s = Console.ReadLine();
        int n = int.Parse(Console.ReadLine());
        string ans = s.Substring((n - 1)/ 5,1) + s.Substring((n - 1) % 5,1);
        Console.WriteLine(ans);
    }
}