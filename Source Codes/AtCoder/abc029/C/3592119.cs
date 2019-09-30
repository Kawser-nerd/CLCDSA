using System;
using System.Collections.Generic;
public class P{
  public static void Main(){
    int n=int.Parse(Console.ReadLine());
    List<string>[] a=new List<string>[n+1];
    for(int i=0;i<=n;i++)a[i]=new List<string>();
    a[0].Add("");
    for (int i=0;i<n;i++)foreach(string b in a[i]){
      a[i+1].Add(b+"a");
      a[i+1].Add(b+"b");
      a[i+1].Add(b+"c");
    }
    Console.Write(string.Join("\n",a[n])+"\n");
  }
}