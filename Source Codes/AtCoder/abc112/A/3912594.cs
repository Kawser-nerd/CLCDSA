using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC112 {
	class ABC112_A {
		static void Main(string[] args) {
			int N = int.Parse(Console.ReadLine());
			if (N == 1) Console.WriteLine("Hello World");
			if (N == 2) Console.WriteLine("{0}", int.Parse(Console.ReadLine()) + int.Parse(Console.ReadLine()));
		}
	}
}