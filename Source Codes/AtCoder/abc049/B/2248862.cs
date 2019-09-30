using System;
public class Hello{
    public static void Main(){
        string[] input = Console.ReadLine().Split(' ');
        int N = int.Parse(input[0]);
        string[] s = new string[N];
        for(int i = 0;i < N;i++){
            s[i] = Console.ReadLine();
        }
        for(int i = 0;i < N;i++){
            Console.WriteLine(s[i]);
            Console.WriteLine(s[i]);
        }
    }
}