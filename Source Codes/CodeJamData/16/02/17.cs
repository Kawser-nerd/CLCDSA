using System.IO;
// ReSharper disable AssignNullToNotNullAttribute
// ReSharper disable PossibleNullReferenceException

namespace ConsoleApplication2
{
	class B
	{
		public void Solve()
		{
			using (var sr = new StreamReader("B.in"))
			using (var sw = new StreamWriter("B.out"))
			{
				var t = int.Parse(sr.ReadLine());
				for (var testCase = 1; testCase <= t; ++testCase)
				{
					var s = sr.ReadLine();
					var diffPartCount = 1;
					for (var ind = 1; ind < s.Length; ++ind)
						if (s[ind - 1] != s[ind])
							++diffPartCount;
					var doesntNeedLastMotion = (diffPartCount%2 == 1 && s[0] == '+') || (diffPartCount%2 == 0 && s[0] == '-');
					sw.WriteLine("Case #{0}: {1}", testCase, diffPartCount - (doesntNeedLastMotion ? 1 : 0));
				}
			}
		}
	}
}
