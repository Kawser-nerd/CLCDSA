using System;
class Program
{    static void Main(String[] args){
  
    string[] str = Console.ReadLine().Split(' ');
    int a = int.Parse(str[0]);
    int b = int.Parse(str[1]);
    if (a%b==0){
        Console.WriteLine("0");
        }else {
            Console.WriteLine("1");
        }
    }
}