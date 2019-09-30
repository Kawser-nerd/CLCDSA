using System;
public class P{
  public static void Main(){
    string a="";
    var s=Console.ReadLine().ToCharArray();
    foreach (char x in s){if(x!='B')a+=x;else if(a!="")a=a.Substring(0,a.Length-1);}
    Console.WriteLine(a);
  }
}