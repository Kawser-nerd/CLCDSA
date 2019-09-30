using System;
using System.Linq;
class A{
  static void Main(){
    var arr = new int[] { 4, 6, 9, 11 };
    var s = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
    Console.WriteLine(!s.Contains(2) && arr.Contains(s[0]) == arr.Contains(s[1])?"Yes":"No");
  }
}