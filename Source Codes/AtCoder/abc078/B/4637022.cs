using System;
class Program{
    static void Main(string[] args){
        string[] num = Console.ReadLine().Split(' ');
        int x = int.Parse(num[0]); int y = int.Parse(num[1]); int z =int.Parse(num[2]);
        int reserve = x-z;
        Console.WriteLine(reserve / (y+z));
    }
}