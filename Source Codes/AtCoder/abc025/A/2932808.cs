using System;
 
class Program
{
  static void Main(string[] args)
  {
    string s = Console.ReadLine();
    int n = int.Parse(Console.ReadLine());
    int count = 0;
    
    for(int i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++){
        count++;
        if(count == n)
        {
          Console.WriteLine("{0}{1}", s[i], s[j]);
        }
      }
    }
  }
}