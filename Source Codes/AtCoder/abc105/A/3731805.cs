using System;
public class A{
  public static void Main(string[] args){
    string[] inputs = Console.ReadLine().Split(' ');
    var num1 = int.Parse(inputs[0]);
    var num2 = int.Parse(inputs[1]);
    Console.WriteLine(num1 % num2 == 0 ? "0" : "1");
    Console.ReadLine();
  }
}