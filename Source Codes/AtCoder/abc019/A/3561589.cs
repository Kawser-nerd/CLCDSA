using System;
using System.Collections.Generic;
public class P{
public static void Main(){
var a=new List<int>();
var s=Console.ReadLine().Split(' ');
for(int i=0;i<3;i++)a.Add(int.Parse(s[i]));
a.Sort();
Console.WriteLine(a[1]);
}}