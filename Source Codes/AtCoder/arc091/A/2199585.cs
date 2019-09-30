using System.Linq;
using static System.Console;
using static System.Math;
class K
{
	static void Main()
	{
		var I = ReadLine().Split().Select(long.Parse).ToArray();
		WriteLine(Abs((I[0] - 2) * (I[1] - 2)));
	}
}