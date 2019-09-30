using System;
 
class Program
{
  static void Main(string[] args)
  {
    string[] str = Console.ReadLine().Split(' ');
    int[] age = new int[3];
    for(int i = 0; i < 3; i++){
      age[i] = int.Parse(str[i]);
    }
    Array.Sort(age);
    Console.WriteLine(age[1]);
  }
}