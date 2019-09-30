using System;
class A{
  public static void Main(){
    var s = System.Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
    Console.WriteLine(s[0] + s[1] >= s[2]? "Yes": "No");
  }
}