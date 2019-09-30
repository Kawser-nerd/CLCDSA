using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
	class Program
	{
		static void Main(string[] args)
		{
			var N = int.Parse(Console.ReadLine());
			var baseString = Console.ReadLine();

			var temp = baseString;
			var addL = new List<char>(N);
			var addR = new List<char>(N);
			for (int i = 0; i < N; i++)
			{
				temp = temp.Replace("()", "");
			}
			while (!(temp == "" || temp == "0"))
			{
				while (temp != "" && temp[0] == ')')
				{
					addL.Add('(');
					temp = temp.Remove(0, 1);
				}
				while (temp != "" && temp[temp.Length - 1] == '(')
				{
					addR.Add(')');
					temp = temp.Remove(temp.Length - 1, 1);
				}
			}
			for (int i = 0; i < addL.Count; i++)
			{
				Console.Write(addL[i]);
			}
			Console.Write(baseString);
			for (int i = 0; i < addR.Count; i++)
			{
				Console.Write(addR[i]);
			}
			Console.WriteLine();
		}
	}
}