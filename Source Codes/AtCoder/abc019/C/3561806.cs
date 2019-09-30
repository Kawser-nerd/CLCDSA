using System;
using System.Linq;
using System.Collections.Generic;
public class P{
public static void Main(){
int N=int.Parse(Console.ReadLine());
Console.WriteLine(Console.ReadLine().Split(' ').Select(x=>{int n=int.Parse(x);while(n%2==0)n/=2;return n;}).Distinct().Sum(y=>1));
}
}