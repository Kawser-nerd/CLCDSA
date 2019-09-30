using System;

class Program
{
  static void Main(string[] args)
  {
    int a = int.Parse(Console.ReadLine());
    int b = int.Parse(Console.ReadLine());
    int c = int.Parse(Console.ReadLine());
    
    int ansa = 1;
    int ansb = 1;
    int ansc = 1;
    
    if(a<b) ansa++;
    if(a<c) ansa++;
    if(b<a) ansb++;
    if(b<c) ansb++;
    if(c<a) ansc++;
    if(c<b) ansc++;
    
    Console.WriteLine(ansa);
    Console.WriteLine(ansb);
    Console.WriteLine(ansc);
  }
}