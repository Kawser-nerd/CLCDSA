using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Decision
{
	class Program
	{
		class Node
		{
			public double w;
			public string feature;
			public Node first, second;

			public Node(string def, ref int p)
			{
				while (def[p] != '(')
					p++;
				p++;

				while (def[p] == ' ')
					p++;

				string w_s = "";
				while (def[p] != ' ' && def[p] != ')')
				{
					w_s += def[p].ToString();
					p++;
				}

				w = double.Parse(w_s);

				while (def[p] == ' ')
					p++;

				if (def[p] == ')')
					return;

				string f_s = "";
				while (def[p] != ' ')
				{
					f_s += def[p].ToString();
					p++;
				}

				feature = f_s;

				first = new Node(def, ref p);
				second = new Node(def, ref p);
			}

			public double Calc(Dictionary<string, object> has, double p)
			{
				p *= w;
				if (first == null && second == null)
					return p;
				if (has.ContainsKey(feature))
					return first.Calc(has, p);
				else
					return second.Calc(has, p);
			}
		}

		static void Main(string[] args)
		{
			StreamReader sr = new StreamReader("A-large.in");
			StreamWriter sw = new StreamWriter("out.txt");

			//System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.GetCultureInfo("en-US");
			int tc = int.Parse(sr.ReadLine());
			for (int cc = 0; cc < tc; cc++)
			{
				int lines = int.Parse(sr.ReadLine());
				string treeDef = "";
				for (int i = 0; i < lines; i++)
					treeDef += sr.ReadLine() + " ";

				int p = 0;
				Node tree = new Node(treeDef.Replace('.', ','), ref p);

				int a = int.Parse(sr.ReadLine());

				sw.WriteLine("Case #{0}:", cc + 1);
				for (int i = 0; i < a; i++)
				{
					string[] spl = sr.ReadLine().Split(' ');
					string name = spl[0];
					Dictionary<string, object> has = new Dictionary<string, object>();
					for (int j = 2; j < spl.Length; j++)
						has.Add(spl[j], null);

					string o = tree.Calc(has, 1).ToString("f7").Replace(',', '.');
					sw.WriteLine("{0}", o);
				}
			}

			sr.Close();
			sw.Close();
		}
	}
}
