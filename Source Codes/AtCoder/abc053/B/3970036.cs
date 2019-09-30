using System;
class B{
  static void Main(){
    var s = Console.ReadLine();
    Console.WriteLine(s.LastIndexOf('Z')-s.IndexOf('A')+1);
  }  
}