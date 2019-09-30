using System;
using System.Linq;

public class Test
{
	public static void Main(){
var p = Console.ReadLine().ToCharArray();
var s = Console.ReadLine();
Console.WriteLine(s.ToCharArray().Where(i=>{
p = p.Skip(1).Concat(p.Take(1)).ToArray();
return String.Join("",p)==s;
}).Count()==0?"No":"Yes");
}
}