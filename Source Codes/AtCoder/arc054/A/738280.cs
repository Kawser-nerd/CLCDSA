using System; using System.Linq;
class A {
	static void Main() {
		var n = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray(); 
		int L = n[0], X = n[1], Y = n[2], S = n[3], D = n[4];
		var a = ((D-S+L)%L)/(double)(Y+X);
		Console.WriteLine((X<Y) ? Math.Min(a, ((S-D+L)%L)/(double)(Y-X)) : a);
	}
}