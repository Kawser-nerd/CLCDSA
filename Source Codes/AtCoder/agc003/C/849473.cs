using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


class contest
{
		static void Main(string[] args)
		{
			var num = int.Parse(Console.ReadLine());
            var input = new List<int>();

            var dicSorted = new Dictionary<int, int>();
            var dicOriginal = new Dictionary<int, int>();
            int count = 0;

            for (int i = 0; i < num; i++) input.Add(int.Parse(Console.ReadLine()));//dic.Add(int.Parse(Console.ReadLine()),i);
            List<int> clone = new List<int>(input);
            clone.Sort();

            for (int i = 0; i < num; i++) dicOriginal.Add(input[i], i);
            for (int i = 0; i < num; i++) dicSorted.Add(clone[i], i);


            for(int i =0; i< num; i+=2)
            {
                if (dicOriginal[input[i]] % 2 != dicSorted[input[i]] % 2) count++;
            }

            Console.WriteLine(count);     
		}
}