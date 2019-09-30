using System;
class Program
{    static void Main(String[] args){
  
    string[] str = Console.ReadLine().Split(' ');
    int a = int.Parse(str[0]);
    if (a%2==1){

        Console.WriteLine(a/2*(a/2+1));

    }else {
        Console.WriteLine(a/2*a/2);
        }   
    }   
}