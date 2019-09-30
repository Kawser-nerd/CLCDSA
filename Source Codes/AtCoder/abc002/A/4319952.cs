using System;
class c
{
  static void Main()
  {
    string[] a = Console.ReadLine().Split(' ');
    if(int.Parse(a[0])>int.Parse(a[1]))Console.WriteLine(a[0]);
    else Console.WriteLine(a[1]);
  }
}