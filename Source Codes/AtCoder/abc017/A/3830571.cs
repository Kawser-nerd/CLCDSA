using System;
class A{
  static void Main(){
    Console.WriteLine((m()+m()+m())/10);
    }
  static int m(){
    var s = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
    return s[0]*s[1];
  }
}