using System;

class Program
{
  static void Main(string[] args)
  {
    string str = Console.ReadLine();
    int n = int.Parse(str);

    int num = 0;
    for (int i=0; i<n; i++) {
      string[] str2 = Console.ReadLine().Split(' ');
      int l = int.Parse(str2[0]);
      int r = int.Parse(str2[1]);
      num += r - l + 1;
    }
    Console.WriteLine(num);
    return;
  }
}