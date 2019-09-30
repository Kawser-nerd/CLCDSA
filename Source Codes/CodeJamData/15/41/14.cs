using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            var caseCount = int.Parse(Console.ReadLine());
            for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
            {
	            var dimensions = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
	            var rowCount = dimensions[0];
	            var columnCount = dimensions[1];

	            var field = new List<string>(rowCount);
				foreach (var rowIndex in Enumerable.Range(0, rowCount))
					field.Add(Console.ReadLine());

	            var result = Solve(field);

				Console.WriteLine("Case #{0}: {1}", caseNumber, result?.ToString() ?? "IMPOSSIBLE");
            }
        }


	    static int? Solve(List<string> field)
	    {
		    var result = 0;
		    foreach (var rowIndex in Enumerable.Range(0, field.Count))
		    {
			    foreach (var columnIndex in Enumerable.Range(0, field[0].Length))
			    {
				    switch (field[rowIndex][columnIndex])
				    {
						case '^':
						    if (!HasArrowUp(field, rowIndex, columnIndex))
						    {
							    if (HasArrowDown(field, rowIndex, columnIndex) || 
										HasArrowLeft(field, rowIndex, columnIndex) || 
										HasArrowRight(field, rowIndex, columnIndex))
								    result++;
							    else
								    return null;
						    }
						    break;

						case '>':
							if (!HasArrowRight(field, rowIndex, columnIndex))
							{
								if (HasArrowDown(field, rowIndex, columnIndex) ||
										HasArrowUp(field, rowIndex, columnIndex) ||
										HasArrowLeft(field, rowIndex, columnIndex))
									result++;
								else
									return null;
							}
							break;

						case 'v':
							if (!HasArrowDown(field, rowIndex, columnIndex))
							{
								if (HasArrowUp(field, rowIndex, columnIndex) ||
										HasArrowLeft(field, rowIndex, columnIndex) ||
										HasArrowRight(field, rowIndex, columnIndex))
									result++;
								else
									return null;
							}
							break;

						case '<':
							if (!HasArrowLeft(field, rowIndex, columnIndex))
							{
								if (HasArrowDown(field, rowIndex, columnIndex) ||
										HasArrowUp(field, rowIndex, columnIndex) ||
										HasArrowRight(field, rowIndex, columnIndex))
									result++;
								else
									return null;
							}
							break;
				    }
			    }
		    }
		    return result;
	    }

	    static bool HasArrowDown(List<string> field, int row, int column)
	    {
		    for (var currentRow = row + 1; currentRow < field.Count; currentRow++)
			    if (field[currentRow][column] != '.')
				    return true;
		    return false;
	    }

		static bool HasArrowUp(List<string> field, int row, int column)
		{
			for (var currentRow = row - 1; currentRow >= 0; currentRow--)
				if (field[currentRow][column] != '.')
					return true;
			return false;
		}

		static bool HasArrowLeft(List<string> field, int row, int column)
		{
			for (var currentColumn = column - 1; currentColumn >= 0; currentColumn--)
				if (field[row][currentColumn] != '.')
					return true;
			return false;
		}

		static bool HasArrowRight(List<string> field, int row, int column)
		{
			for (var currentColumn = column + 1; currentColumn < field[row].Length; currentColumn++)
				if (field[row][currentColumn] != '.')
					return true;
			return false;
		}
	}
}
