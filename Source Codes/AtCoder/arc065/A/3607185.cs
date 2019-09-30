using System.Collections.Generic;
 
using System.Linq;
using System;
 
namespace Application
{
	class Solution
	{
		static void Main(string[] args)
		{
			var answer = Console.ReadLine();
 
			//????????????????
 
 
			var words = new List<string>() { "dream", "dreamer", "erase", "eraser" };
 
			while (answer.Length > 0)
			{
				var beforeAnswerLength = answer.Length;
 
				foreach(var word in words)
				{
					if (answer.EndsWith(word))
					{
						answer = answer.Substring(0, answer.Length - word.Length);
					}
				}
 
				if (answer.Length == beforeAnswerLength)
					break;
			}
 
			var result = answer.Length == 0 ? "YES" : "NO";
 
			Console.WriteLine(result);
		}
	}
}