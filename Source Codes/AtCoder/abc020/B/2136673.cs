using System;
public class Hello{
    public static void Main(){
        string[] input = Console.ReadLine().Split(' ');
        int ans = int.Parse(input[0] + input[1]);
        ans *= 2;
        Console.WriteLine(ans);
    }
}