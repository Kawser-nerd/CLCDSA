using Combinatorics.Collections;
using ConsoleApplication1.DataTypes;
using ConsoleApplication1.Helpers;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1.OtherTasks.CodeJam2017
{
	public class FashionShow
	{
		public void Go(string[] args)
		{
			//Solve(".... .... ....");
			//Solve("... ... ...");
			//Solve("... ...");
			//Solve(".. ..");
			//Solve("... +++ x..");

			//Solve(".... .... .... ....".Split());
			Compare();
			//Performance();
			//SolveFile(args);

			//var board = new int[2, 1];
			//var i = 1;
			//foreach (var point in EnumerateCircle(board))
			//	board.Set(point, i++);
			//Console.WriteLine(board.ToStringData());
		}

		public void SolveFile(string[] args)
		{
			var task = File.ReadAllLines(args[0]);
			var sb = new StringBuilder();

			foreach (var line in SolveFullTask(task))
				sb.AppendLine(line);

			File.WriteAllText(args[1], sb.ToString());
		}

		public void SolveSample()
		{
			var answer = SolveFullTask(@"3
2 0
1 1
o 1 1
3 4
+ 2 3
+ 2 1
x 3 1
+ 2 2".SplitToLines());
			Console.WriteLine(answer.Join("\r\n"));
		}

		public void Performance()
		{
			var rnd = new Random(123);

			var N = 100;
			var M = rnd.Next(0, N * N);

			var board = ArrayHelper.Create(N, _ => new string('.', N).ToCharArray()).ToTwoDimesional();

			Console.WriteLine("Task: ");
			Console.WriteLine(board.ToStringData(""));

			var sol = Solve(board);
			Console.WriteLine();
			Console.WriteLine("Score: {0}", sol.Score);
			Console.WriteLine(sol.Board.ToStringData(""));
		}

		public void Compare()
		{
			var rnd = new Random(123);
			for (var t = 0; t < 200; t++)
			{
				var N = 4;
				var NN = 3;
				var M = rnd.Next(2, N * N);

				var board = ArrayHelper.Create(N, _ => new string('.', NN).ToCharArray()).ToTwoDimesional();

				for (var i = 0; i < M; i++)
					board[rnd.Next(0, N), rnd.Next(0, NN)] = "+xo".RandomElement(rnd);
				if (!IsBoardOk(board))
					continue;

				Console.WriteLine(new { t, N, M });

				var brute = SolveBrute(board.ShallowClone());
				var sol = Solve(board.ShallowClone());

				if (brute.Score != sol.Score)
				{
					Console.WriteLine("Original score {0}: ", Score(board));
					Console.WriteLine(board.ToStringData(""));
					Console.WriteLine();

					Console.WriteLine("Brute solution score {0}: ", brute.Score);
					Console.WriteLine(brute.Board == null ? "no solution" : brute.Board.ToStringData(""));
					Console.WriteLine();

					Console.WriteLine("Solve solution score {0}: ", sol.Score);
					Console.WriteLine(sol.Board.ToStringData(""));
					Console.WriteLine();

					Console.WriteLine(new { t });
					throw new InvalidOperationException();
				}
			}
		}

		public IEnumerable<string> SolveFullTask(string[] lines)
		{
			var result = new List<string>();

			var line = 0;
			var T = int.Parse(lines[line++]);
			for (var t = 0; t < T; t++)
			{
				var NM = lines[line++].Split();
				var N = int.Parse(NM[0]);
				var M = int.Parse(NM[1]);

				var board = ArrayHelper.Create(N, N, (i, j) => '.').ToTwoDimesional();

				for (var i = 0; i < M; i++)
				{
					var code = lines[line++].Split();
					board[int.Parse(code[1]) - 1, int.Parse(code[2]) - 1] = code[0][0];
				}

				var sol = Solve(board.ShallowClone());

				var changes = new List<string>();

				foreach (var point in board.ToPoints())
					if (board.Get(point) != sol.Board.Get(point))
						changes.Add($"{sol.Board.Get(point)} {point.X + 1} {point.Y + 1}");

				result.Add($"Case #{t + 1}: {sol.Score} {changes.Count}");
				result.AddRange(changes);

				{
					var checkBoard = board.ShallowClone();
					foreach (var change in changes)
					{
						var code = change.Split();
						var r = int.Parse(code[1]) - 1;
						var c = int.Parse(code[2]) - 1;
						var after = code[0][0];
						var before = checkBoard[r, c];
						checkBoard[r, c] = after;

						var isOk = (before == '.' && (after == 'x' || after == '+' || after == 'o'))
							|| (before == 'x' && after == 'o')
							|| (before == '+' && after == 'o');

						if (!isOk)
							throw new InvalidOperationException();
					}
					if (!IsBoardOk(checkBoard) || Score(checkBoard) != sol.Score)
						throw new InvalidOperationException();
				}
			}

			return result;
		}

		public void Solve(string boardStr)
		{
			var board = boardStr.Split().Select(s => s.ToCharArray()).ToArray().ToTwoDimesional();

			Console.WriteLine("Task: ");
			Console.WriteLine(board.ToStringData(""));

			var sol = Solve(board);
			Console.WriteLine("Score: {0}", sol.Score);
			Console.WriteLine(sol.Board.ToStringData(""));
			Console.WriteLine();
		}

		public Solution Solve(char[,] board)
		{
			var rows = board.GetLength(0);
			var cols = board.GetLength(1);

			var points = EnumerateCircle(board).ToArray();

			var diagsDR = Enumerable.Range(-rows + 1, rows + cols - 1).Select(diag => board.GetDiagonalPoints(new PointInt(0, diag), true).ToArray()).ToArray();
			var diagsUR = Enumerable.Range(0, rows + cols - 1).Select(diag => board.GetDiagonalPoints(new PointInt(0, diag), false).ToArray()).ToArray();
			var horizontals = Enumerable.Range(0, rows).Select(r => Enumerable.Range(0, cols).Select(c => new PointInt(r, c)).ToArray()).ToArray();
			var verticals = Enumerable.Range(0, cols).Select(c => Enumerable.Range(0, rows).Select(r => new PointInt(r, c)).ToArray()).ToArray();

			// Only +:
			{
				var busy = new bool[board.GetLength(0), board.GetLength(1)];

				foreach (var lineArray in new[] { diagsDR, diagsUR })
					foreach (var linePoints in lineArray)
						if (linePoints.Select(board.Get).Any(c => c == '+' || c == 'o'))
							foreach (var linePoint in linePoints)
								busy.Set(linePoint, true);

				foreach (var point in points)
				{
					var before = board.Get(point);
					if ((before == '.' || before == 'x') && !busy.Get(point))
					{
						board.Set(point, before == '.' ? '+' : 'o');
						foreach (var diagPoint in board.GetDiagonalPoints(point, true).Concat(board.GetDiagonalPoints(point, false)))
							busy.Set(diagPoint, true);
					}
				}
				//Console.WriteLine("After only +: ");
				//Console.WriteLine(board.ToStringData(""));
				//Console.WriteLine();
			}

			// Only x:
			{
				var busy = new bool[board.GetLength(0), board.GetLength(1)];

				foreach (var lineArray in new[] { horizontals, verticals })
					foreach (var linePoints in lineArray)
						if (linePoints.Select(board.Get).Any(c => c == 'x' || c == 'o'))
							foreach (var linePoint in linePoints)
								busy.Set(linePoint, true);

				foreach (var point in points)
				{
					var before = board.Get(point);
					if ((before == '.' || before == '+') && !busy.Get(point))
					{
						board.Set(point, before == '.' ? 'x' : 'o');
						foreach (var linePoint in horizontals[point.X].Concat(verticals[point.Y]))
							busy.Set(linePoint, true);
					}
				}
				//Console.WriteLine("After only x: ");
				//Console.WriteLine(board.ToStringData(""));
				//Console.WriteLine();
			}

			return new Solution { Score = Score(board), Board = board };
		}

		public Solution SolveBrute(char[,] board)
		{
			var changes = board.ToPoints().Where(p => board.Get(p) != 'o')
				.Select(p => (board.Get(p) == '.' ? ".+xo" : board.Get(p) == 'o' ? "o" : (board.Get(p) + "o")).Select(c => new { c, p }).ToArray())
				.ToArray();

			var bestScore = 0;
			var bestBoards = new List<char[,]>();

			foreach (var comb in CombinatoricsHelper.Selections(changes))
			{
				var resultBoard = board.ShallowClone();

				foreach (var change in comb)
					resultBoard.Set(change.p, change.c);

				if (!IsBoardOk(resultBoard))
					continue;

				var score = Score(resultBoard);

				if (score > bestScore)
				{
					bestScore = score;
					bestBoards.Clear();
					bestBoards.Add(resultBoard);
				}
				else if (score == bestScore)
					bestBoards.Add(resultBoard);
			}

			return new Solution { Score = bestScore, Board = bestBoards.Count == 0 ? null : bestBoards[0] };
		}

		public class Solution
		{
			public int Score;
			public char[,] Board;
		}

		private int Score(char[,] board)
		{
			return board.EnumerateFlat().Sum(c => c == '+' ? 1 : c == 'x' ? 1 : c == 'o' ? 2 : 0); ;
		}

		private bool IsBoardOk(char[,] board)
		{
			var rows = board.GetLength(0);
			var cols = board.GetLength(1);

			var isNotOk = Enumerable.Range(0, rows).Any(r => board.GetRow(r).Count(c => c != '.' && c != '+') > 1)
					|| Enumerable.Range(0, cols).Any(col => board.GetColumn(col).Count(c => c != '.' && c != '+') > 1)
					|| Enumerable.Range(-rows + 1, rows + cols - 1).Any(
						diag => board.GetDiagonalPoints(new PointInt(0, diag), true).Select(board.Get).Count(c => c != '.' && c != 'x') > 1)
					|| Enumerable.Range(0, rows + cols - 1).Any(
						diag => board.GetDiagonalPoints(new PointInt(0, diag), false).Select(board.Get).Count(c => c != '.' && c != 'x') > 1);

			return !isNotOk;
		}

		private IEnumerable<PointInt> EnumerateCircle<T>(T[,] board)
		{
			var rows = board.GetLength(0);
			var cols = board.GetLength(1);

			for (var d = 0; d < Math.Min(rows / 2, cols / 2); d++)
			{
				var r = d;
				var c = d;
				for (var i = 0; i < cols - 2 * d - 1; i++) yield return new PointInt(r, c++);
				for (var i = 0; i < rows - 2 * d - 1; i++) yield return new PointInt(r++, c);
				for (var i = 0; i < cols - 2 * d - 1; i++) yield return new PointInt(r, c--);
				for (var i = 0; i < rows - 2 * d - 1; i++) yield return new PointInt(r--, c);
			}
			if (cols >= rows && rows % 2 == 1)
				for (var i = 0; i < cols - rows + 1; i++)
					yield return new PointInt(rows / 2, rows / 2 + i);
			else if (rows >= cols && cols % 2 == 1)
				for (var i = 0; i < rows - cols + 1; i++)
					yield return new PointInt(cols / 2 + i, cols / 2);
		}
	}
}
