using System.IO;

namespace Impl
{
	public abstract class ProblemBase
	{
		protected abstract bool SolveOne(TextReader input, TextWriter output, int testNumber);

		public void Solve(TextReader reader, TextWriter writer)
		{
			var n = int.Parse(reader.ReadLine());
			for (var i = 1; i <= n; ++i)
				SolveOne(reader, writer, i);
		}

		protected virtual bool Write(TextWriter writer, int testNumber, string result)
		{
			writer.WriteLine("Case #{0}: {1}", testNumber, result);
			return false;
		}
	}
}