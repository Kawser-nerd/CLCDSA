using System;
class Program
{    static void Main(String[] args){
  
    string[] str = Console.ReadLine().Split(' ');
    int a = int.Parse(str[0]);
    int b = int.Parse(str[1]);

        Console.WriteLine((a-1)*(b-1));
    }
}