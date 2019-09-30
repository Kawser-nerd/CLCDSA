using System;
class Program
{    static void Main(String[] args){
  
    string[] str = Console.ReadLine().Split(' ');
    int a = int.Parse(str[0]);
    int b = int.Parse(str[1]);
    if (a%2==1){
        if (b%2==1){
          Console.WriteLine("Yes");
        }else {
            Console.WriteLine("No");
        }
    }else {
        Console.WriteLine("No");
        }   
    }   
}