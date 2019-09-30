using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GCJ_2008
{
	class SavingTheUniverse: CommonProblem
	{
		public override void ProcessCase(TextReader reader, TextWriter writer)
		{
			int S;
			ParseInputLine<int>(reader, out S);
			Dictionary<string, int> engines = new Dictionary<string,int>();
			for (int i = 0; i < S; i++) {
				string engine = reader.ReadLine();
				engines.Add(engine, i);
			}

			int Q;
			ParseInputLine<int>(reader, out Q);
			int[] querys = new int[Q];
			for (int i = 0; i < Q; i++) {
				string q = reader.ReadLine();
				querys[i] = engines[q];
			}


			int switchCount = 0;
			Dictionary<int, bool> appears = new Dictionary<int,bool>();
			for (int i = 0; i < Q; i++) {
				int q = querys[i];
				appears[q] = true;
				if (appears.Count == S) {
					switchCount++;
					appears.Clear();
					appears[q] = true;
				}
			}

			Console.WriteLine("{0} {1} {2}", S, Q, switchCount);
			writer.WriteLine(switchCount);
		}
	}
}
