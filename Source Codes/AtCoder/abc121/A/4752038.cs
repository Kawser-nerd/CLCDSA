using System;
class M{static void Main(string[] _) {
  var A = Console.ReadLine().Split(' ');
  var B = Console.ReadLine().Split(' ');
  var H = int.Parse(A[0]);
  var W = int.Parse(A[1]);
  var h = int.Parse(B[0]);
  var w = int.Parse(B[1]);
  Console.Write( ((H-h) * (W-w)) );
}}