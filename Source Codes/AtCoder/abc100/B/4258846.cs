using System;
using System.Linq;

public class Test
{
	public static void Main()=> Console.WriteLine(Console.ReadLine().Split(' ').Select(i=>int.Parse(i)).Select((v,i)=>i==0?Math.Pow(100,v):(v==100?101:v)).Aggregate((calc,val)=>calc*val));
}