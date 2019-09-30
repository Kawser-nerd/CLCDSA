using System;
 
namespace Application
{
	class Solution
	{
		static void Main(string[] args)
		{ 
			var currentTime = 0;
			var currentX = 0;
			var currentY = 0;
 
			var stepCount = int.Parse(Console.ReadLine());
 
			var result = "Yes";
 
			for (var i = 0; i < stepCount; i++)
			{
				var inputWords = Console.ReadLine().Split(' ');
				var nextTime = int.Parse(inputWords[0]);
				var nextX = int.Parse(inputWords[1]);
				var nextY = int.Parse(inputWords[2]);
 
				var diffTime = nextTime - currentTime;
				var diffX = Math.Abs(nextX - currentX);
				var diffY = Math.Abs(nextY - currentY);
 
				var move = diffTime - (diffX + diffY);
 
				// ????
				if (move >= 0
					&& move % 2 == 0)
				{
					currentTime = nextTime;
					currentX = nextX;
					currentY = nextY;
				}
				else
				{
					result = "No";
					break;
				}
			}
 
			Console.WriteLine(result);
		}
	}
}