using System;
class A{
  static void Main(){
    var s = Console.ReadLine().Split();
    var n1 = int.Parse(s[0]);
    var n2 = int.Parse(s[2]); 
    Console.WriteLine(s[1] == "+"? n1+n2:n1-n2);
  }
}