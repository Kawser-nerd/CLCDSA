using System;
using System.Linq;
class A{
 public static void Main(){
   var arr = new char[] { 'a','i','u','e','o'};
   Console.WriteLine(arr.Contains(Console.ReadLine()[0])?"vowel":"consonant");
  }
}