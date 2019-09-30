using System.Linq;
using static System.Console;
class Z
{
	static void Main()
	{
		var I = ReadLine().Split().Select(int.Parse).ToArray();
		var t = 1800L * I[1] + 100 * I[0];
		WriteLine(t << I[1]);
	}
}