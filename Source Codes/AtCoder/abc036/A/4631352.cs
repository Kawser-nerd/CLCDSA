using System;
class Program{
    static void Main(string[] args){
        // Your code here!
        string[] input = Console.ReadLine().Split(' ');
        float size = float.Parse(input[0]);
        float wantNumber = float.Parse(input[1]);
        float devided = wantNumber / size;
        Console.WriteLine(Math.Ceiling(devided));
    }
}