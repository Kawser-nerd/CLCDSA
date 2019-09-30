using System;
class Program
{    static void Main(String[] args){
  
    string[] str = Console.ReadLine().Split(' ');
    int a = int.Parse(str[0]);
    if (a<1200){
        Console.WriteLine("ABC");
        }else if(a<2800){
            Console.WriteLine("ARC");
        }else {
            Console.WriteLine("AGC");
        }
    }
}