/// <summary>
///	https://code.google.com/codejam/contest/3264486/dashboard#s=p3
/// </summary>


using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace FashionShow
{

	public class Position
	{
		public int Row { get; set; }
		public int Col { get; set; }

	}


	public class CaseInfo
	{
		public int StageSize { get; set; }
		public List<Position> ModelsX { get; set; }
		public List<Position> ModelsP { get; set; }

		public List<Position> ModelsModified { get; set; }

		private CaseInfo()
		{
			ModelsModified = new List<Position>();
		}

		public void AddModelX(Position p)
		{
			ModelsX.Add(p);
			ModelsModified.Add(p);
		}

		public void AddModelP(Position p)
		{
			ModelsP.Add(p);
			ModelsModified.Add(p);
		}


		public static CaseInfo Parse(StreamReader inStream)
		{

			string line1 = inStream.ReadLine();
			string[] line1Parts = line1.Split();
			int stageSize = int.Parse(line1Parts[0]);
			int modelsCount = int.Parse(line1Parts[1]);

			List<Position> modelsX = new List<Position>();
			List<Position> modelsP = new List<Position>();

			for (int i = 0; i < modelsCount; i++)
			{
				string line = inStream.ReadLine();
				string[] lineParts = line.Split();
				string model = lineParts[0];
				int row = int.Parse(lineParts[1]);
				int col = int.Parse(lineParts[2]);

				Position p = new Position()
				{
					Row = row,
					Col = col
				};

				if (model == "x" || model == "o")
				{
					modelsX.Add(p);
				}

				if (model == "+" || model == "o")
				{
					modelsP.Add(p);
				}
			}

			CaseInfo result = new CaseInfo();
			result.StageSize = stageSize;
			result.ModelsX = modelsX;
			result.ModelsP = modelsP;
			return result;
		}


		public string Solve()
		{
			fillX();
			fillP();
			return formatOutput();
		}

		private void fillX()
		{
			HashSet<int> freeCols = new HashSet<int>();
			for (int i = 0; i < StageSize; i++)
			{
				freeCols.Add(i);
			}

			HashSet<int> freeRows = new HashSet<int>();
			for (int i = 0; i<StageSize; i++)
			{
				freeRows.Add(i);
			}

			foreach (Position p in ModelsX)
			{
				freeCols.Remove(p.Col - 1);
				freeRows.Remove(p.Row - 1);
			}

			int len = freeRows.Count;

			while (freeRows.Count > 0)
			{
				int freeRow = freeRows.First();
				int freeCol = freeCols.First();

				Position p = new Position()
				{
					Row = freeRow + 1,
					Col = freeCol + 1
				};

				AddModelX(p);
				freeRows.Remove(freeRow);
				freeCols.Remove(freeCol);
			}

		}

		private void fillP()
		{


			// count free positions on edges vertical and horizontal (-1)
			bool?[,] matrix = getMatrixP();

			if (StageSize == 1 && matrix[0, 0] == null)
			{
				Position p = new Position()
				{
					Row = 1,
					Col = 1
				};

				AddModelP(p);
				return;
			}

			int freeHorizontal = 0;
			int freeVertical = 0;

			for (int i = 0; i < StageSize - 1; i++)
			{
				bool? left = matrix[i, 0];
				bool? right = matrix[i, StageSize - 1];

				if (left != false)
				{
					freeVertical++;
				}

				if (right != false)
				{
					freeVertical++;
				}

			}




			for (int i = 0; i < StageSize - 1 ; i++)
			{
				bool? top = matrix[0, i];
				bool? bottom = matrix[StageSize - 1, i];

				if (top != false)
				{
					freeHorizontal++;
				}

				if (bottom != false)
				{
					freeHorizontal++;
				}

			}

			if (freeVertical > freeHorizontal)
			{
				for (int i = 0; i < StageSize - 1; i++)
				{
					bool? left = matrix[i, 0];
					bool? right = matrix[i, StageSize - 1];

					if (left == null)
					{
						Position pLeft = new Position()
						{
							Row = i + 1,
							Col = 1
						};

						AddModelP(pLeft);
					}

					if (right == null)
					{
						Position pRight = new Position()
						{
							Row = i + 1,
							Col = StageSize
						};

						AddModelP(pRight);
					}
				}
			}
			else
			{
				for (int i = 0; i<StageSize - 1; i++)
				{
					bool? top = matrix[0, i];
					bool? bottom = matrix[StageSize - 1, i];

					if (top == null)
					{
						Position pTop = new Position()
						{
							Row = 1,
							Col = i + 1
						};

						AddModelP(pTop);
					}

					if (bottom == null)
					{
						Position pBottom = new Position()
						{
							Row = StageSize,
							Col = i + 1
						};

						AddModelP(pBottom);
					}
				}

			}



		}

		private bool?[,] getMatrixX()
		{
			bool?[,] result = new bool?[StageSize, StageSize];

			foreach (Position p in ModelsX)
			{
				fillTangents(result, p);
			}


			return result;
		}

		private bool?[,] getMatrixP()
		{
			bool?[,] result = new bool?[StageSize, StageSize];
			foreach (Position p in ModelsP)
			{
				fillDiagonals(result, p);
			}

			return result;
		}

		private void fillDiagonals(bool?[,] matrix, Position p)
		{
			int x = p.Col - 1;
			int y = p.Row - 1;

			matrix[y, x] = true;

			x = p.Col - 2;
			y = p.Row - 2;
			while (x >= 0 && y >= 0)
			{
				matrix[y, x] = false;
				x--;
				y--;
			}

			x = p.Col - 2;
			y = p.Row;
			while (x >= 0 && y < StageSize)
			{
				matrix[y, x] = false;
				x--;
				y++;
			}

			x = p.Col;
			y = p.Row - 2;
			while (x < StageSize && y >= 0)
			{
				matrix[y, x] = false;
				x++;
				y--;
			}

			x = p.Col;
			y = p.Row;
			while (x < StageSize && y < StageSize)
			{
				matrix[y, x] = false;
				x++;
				y++;
			}

		}

		private void fillTangents(bool?[,] matrix, Position p)
		{
			int x = p.Col - 1;
			int y = p.Row - 1;
			matrix[y, x] = true;

			x = p.Col - 2;
			while (x >= 0)
			{
				matrix[y, x] = false;
				x--;
			}

			x = p.Col;
			while (x < StageSize)
			{
				matrix[y, x] = false;
				x++;
			}

			x = p.Col - 1;
			y = p.Row - 2;
			while (y >= 0)
			{
				matrix[y, x] = false;
				y--;
			}

			y = p.Row;
			while (y < StageSize)
			{
				matrix[y, x] = false;
				y++;
			}
		}


		private string formatOutput()
		{
			int stylePoints = ModelsX.Count + ModelsP.Count;

			//if (stylePoints != StageSize * 3 - 2 && StageSize > 1)
			//{
			//	throw new Exception("stylePoints != StageSize * 3 - 2");
			//}

			int modifiedModels = 0;

			bool?[,] matrixX = getMatrixX();
			bool?[,] matrixP = getMatrixP();



			List<string> modelsResult = new List<string>();
			foreach (Position pModified in ModelsModified)
			{
				bool p = matrixP[pModified.Row - 1, pModified.Col - 1] == true;
				bool x = matrixX[pModified.Row - 1, pModified.Col - 1] == true;

				string model = null;
				if (p && x)
				{
					model = "o";
				}
				else if (p)
				{
					model = "+";
				}
				else if (x)
				{
					model = "x";
				}
				else
				{
					continue;
				}

				modifiedModels++;
				matrixP[pModified.Row - 1, pModified.Col - 1] = false;
				matrixX[pModified.Row - 1, pModified.Col - 1] = false;
				modelsResult.Add(model + " " + pModified.Row + " " + pModified.Col);
			}

			StringBuilder result = new StringBuilder();
			result.AppendLine(stylePoints.ToString() + " " + modifiedModels.ToString());

			foreach (string m in modelsResult)
			{
				result.AppendLine(m);
			}

			return result.ToString().TrimEnd(null);

		}

	}


	class MainClass
	{

		public static void Main(string[] args)
		{
			Encoding encoding = new UTF8Encoding(false);
			string inFilePath = "/gcj/2017/d/in.txt";
			string outFilePath = "/gcj/2017/d/out.txt";

			List<string> resultLines = new List<string>();
			using (StreamReader inStream = new StreamReader(inFilePath, encoding))
			{
				int casesCount = int.Parse(inStream.ReadLine());
				for (int caseNumber = 1; caseNumber <= casesCount; caseNumber++)
				{

					CaseInfo c = CaseInfo.Parse(inStream);
					string solution = c.Solve();


					Console.WriteLine("Case #" + caseNumber + ": " + solution);
					resultLines.Add("Case #" + caseNumber + ": " + solution);

					//break;
				}
			}

			File.WriteAllLines(outFilePath, resultLines, encoding);

			Console.ReadKey();
		}
	}
}
