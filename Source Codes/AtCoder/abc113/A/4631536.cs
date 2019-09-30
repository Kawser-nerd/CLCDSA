using System;
class Program{
    static void Main(string[] args){
        // Your code here!
        string[] input = Console.ReadLine().Split(' ');
        int x = int.Parse(input[0]);
        int y = int.Parse(input[1]);
        Console.WriteLine(x+y/2);
    }
}