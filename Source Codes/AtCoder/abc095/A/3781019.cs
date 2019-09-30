using System;
using System.Linq;
class A{
  public static void Main(){
    Console.WriteLine(700 + Console.ReadLine().Count( x => x == 'o')*100 );
  }
}