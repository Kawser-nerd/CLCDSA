using System;
class Program{
    static void Main(){
        // Your code here!
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        int c = int.Parse(input[2]);
        Console.WriteLine(a+b >= c ? "Yes" : "No");
    }
}