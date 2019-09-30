using System;
using System.IO;

delegate string myFuncDelegate();

class Program
{
	static myFuncDelegate feedAndRun;
	public static void Main(string[] args)
	{
		feedAndRun += ((new Snapper()).getInputsAndRun);

		genOutputFile();

		//Console.WriteLine((new SquareMath()).getInputsAndRun());

		/*AlienLanguage c = new AlienLanguage();
		for (int i = 0; i < c.N; ++i)
		{
			string pattern = Console.ReadLine();
			Console.WriteLine("Case #{0}: {1}", i + 1, c.solve(pattern));
		}
		*/
	}

	#region Output Generator Code - Author, Rajat Kansal ;)
	public static void genOutputFile()
	{
		//Declare Variables
		StringWriter inputs = new StringWriter();
		StringWriter outputs = new StringWriter();
		StreamReader stmrdr;
		StreamWriter stmwtr;
		string filename = "C:\\Users\\kansal\\Downlo~1\\";
		int i;

		// Save Standard Output Stream  to 'stdout'
		TextWriter stdout = Console.Out;
		TextReader stdin = Console.In;

		// Read Input Filename
		Console.Write("Enter input filename:");
		filename += Console.ReadLine();
		
		stdout.WriteLine("Input File: {0}", filename);

		// Open Input File Stream
		try
		{
			stmrdr = new StreamReader(filename);
		}
		catch
		{
			Console.WriteLine("Error opening input file!");
			return;
		}

		// Read Inputs from Disk Input File to StringWriter, 'inputs'
		string str;
		while ((str = stmrdr.ReadLine()) != null)
		{
			inputs.WriteLine(str);
		}

		// Initialise StringReader to read inputs from 'inputs'
		StringReader strrdr = new StringReader(inputs.ToString());
		Console.SetOut(outputs);    // Redirects Standard Output to StringWriter 'outputs'
		Console.SetIn(strrdr);      // Redirects Standard Input to StringReader 'strrdr'

		// Feed inputs to Solution Code and store output to StringWriter, outputs
		int N = int.Parse(strrdr.ReadLine());

		bool allOk = true;
		for (i = 1; i <= N; i++)
		{
			try
			{
				string res = "";
				res += feedAndRun();
				Console.WriteLine("Case #{0}: {1}", i, res);
				//Console.WriteLine("{1}", i, res);
				stdout.WriteLine("Case #{0}: {1}", i, res);
			}
			catch (Exception e)
			{
				allOk = false;
				Console.WriteLine("Case #{0}:CODE THREW EXCEPTION!!: {1}", i, e.Message);
			}
		}

		Console.SetIn(stdin);       // Reset direction of Standard Input
		Console.SetOut(stdout);     // Reset direction of Standard Output

		filename = filename.Substring(0, filename.LastIndexOf('.') + 1) + "out";

		// Open output file stream
		try
		{
			stmwtr = new StreamWriter(filename);
		}
		catch
		{
			Console.WriteLine("Error creating output filename!");
			return;
		}

		strrdr = new StringReader(outputs.ToString());  // Prepare to read & write outputs

		// Write outputs to Disk to output file
		while ((str = strrdr.ReadLine()) != null)
		{
			stmwtr.WriteLine(str);
		}

		stmwtr.Close();
		stmrdr.Close();

		Console.WriteLine("\nDone" + (allOk ? "." : ", but with Exceptions.") + "\n");
	}
	#endregion
}

class Input
{
	public static int readInt()
	{
		return int.Parse(readLine());
	}

	public static int[] readInts()
	{
		return Array.ConvertAll<string, int>(readStrings(), int.Parse);
	}

	public static double[] readDoubles()
	{
		return Array.ConvertAll<string, double>(readStrings(), double.Parse);
	}

	public static string[] readStrings()
	{
		return readLine().Split();
	}

	public static string readLine()
	{
		return Console.ReadLine();
	}
}
