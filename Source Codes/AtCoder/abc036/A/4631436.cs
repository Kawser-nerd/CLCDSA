using System;
class Program{
    static void Main(string[] args){
        // Your code here!
        string[] input = Console.ReadLine().Split(' ');
        int size = int.Parse(input[0]);
        int wantNumber = int.Parse(input[1]);
        int devided = wantNumber / size;
        if(wantNumber % size != 0){devided++;}
        Console.WriteLine(devided);
    }
}