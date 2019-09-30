using System;
class Program{
    static void Main(string[] args){
        string str = Console.ReadLine();
        Console.WriteLine(str[0].ToString() + (str.Length-2).ToString() + str[str.Length - 1].ToString());
    }
}