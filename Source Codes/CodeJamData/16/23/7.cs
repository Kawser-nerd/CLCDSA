using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.IO;

namespace CodeJam
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			string[] input = File.ReadAllLines (args [0]);
			int cases = int.Parse (input [0]);
			int read = 1;
			for (int c = 1; c <= cases; c++) {
				Console.Write ("Case #" + c + ": ");
				int words = int.Parse (input [read++]);
				List<Topic> topics = new List<Topic>();
				fraud = 0;
				for (int j = 0; j < words; j++)
					topics.Add (new Topic (input [read++]));
				foreach (Topic t in topics) {
					t.CollideFirst.AddRange (topics.Where (x => x != t && x.First == t.First));
					t.CollideLast.AddRange (topics.Where (x => x != t && x.Last == t.Last));
					if (t.CollideFirst.Count == 0 || t.CollideLast.Count == 0)
						t.State = 0;
				}
				Solve (topics, 0);
				Console.WriteLine (fraud);
			}
		}

		static int fraud = 0;
		static void Solve(List<Topic> topics, int index) {
			if (index == topics.Count) {
				fraud = Math.Max (fraud, topics.Count (x => x.State == 1));
				return;
			}
			if (topics [index].State == 0) {
				Solve (topics, index + 1);
				return;
			}
			Topic t = topics [index];
			t.State = 0;
			Solve (topics, index + 1);
			if (t.CanBeFake ()) {
				t.State = 1;
				Solve (topics, index + 1);
			}
			t.State = -1;
		}
	}

	class Topic {
		public string First;
		public string Last;
		public List<Topic> CollideFirst = new List<Topic> ();
		public List<Topic> CollideLast = new List<Topic> ();
		public int State = -1; //0=real, 1=fake, -1=dont know

		public Topic(string s) {
			First = s.Split (' ') [0];
			Last = s.Split (' ') [1];
		}

		public bool MustBeFake() {
			return CollideFirst.Any (c => c.State == 0) && CollideLast.Any (c => c.State == 0);
		}

		public bool CanBeFake() {
			return CollideFirst.Any (c => c.State == -1 ||  c.State == 0) && CollideLast.Any (c => c.State == -1 ||  c.State == 0);
		}
	}
}
