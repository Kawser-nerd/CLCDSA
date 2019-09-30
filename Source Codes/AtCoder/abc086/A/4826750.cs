using System;
class Pg{
  static void Main(string[] args){
    string[] sz = Console.ReadLine().Split(' ');
    int x = int.Parse(sz[0]);
    int y = int.Parse(sz[1]);
    string kk = (x * y) % 2 == 0 ? "Even" : "Odd";
    Console.WriteLine(kk);
  }
}