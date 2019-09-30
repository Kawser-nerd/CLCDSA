using System;
using System.Linq;

class A{
  static void Main(){
    Console.WriteLine(string.Join("",Console.ReadLine().OrderBy(x => x))=="  557"?"YES":"NO");
  }
}