using System;
class Program
{    static void Main(String[] args){
       double avg= 0;
		int a = int.Parse(Console.ReadLine());
        for(int i=0;i<=a;i++){
            avg += i;
        }
        Console.WriteLine(avg/a*10000);
    } 
}