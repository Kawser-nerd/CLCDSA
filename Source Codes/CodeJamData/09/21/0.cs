using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemA
{
	static void Main(string[] args)
	{
//		TextReader sr = new StreamReader(@"c:\temp\a.in");
//		TextReader sr = new StreamReader(@"c:\temp\a-small-attempt0.in");
		TextReader sr = new StreamReader(@"c:\temp\a-large.in");
//		TextReader sr = Console.In;
		
//		TextWriter sw = new StreamWriter(@"c:\temp\a-small.out");
		TextWriter sw = new StreamWriter(@"c:\temp\a-large.out");
//		TextWriter sw = Console.Out;

		int N = int.Parse(sr.ReadLine());
		for (int caseNo = 1; caseNo <= N; caseNo++)
		{
			sw.WriteLine("Case #" + caseNo + ":");
			Solve(sr, sw);
		}
		sw.Close();
	}

	private class Node
	{
		public double Weight;
		public string Feature;
		public Node Left, Right;

		public double Eval(HashSet<string> features)
		{
			double p = Weight;
			if (Feature == null)
				return p;
			if (features.Contains(Feature))
				p *= Left.Eval(features);
			else
				p *= Right.Eval(features);
			return p;
		}
	}

	private static void Solve(TextReader sr, TextWriter sw)
	{
		int L = int.Parse(sr.ReadLine());
		var sb = new StringBuilder();
		for (int i = 0; i < L; i++)
		{
			sb.Append(sr.ReadLine());
			sb.Append(' ');
		}
		string tree = sb.ToString();
		int pos = 0;
		Node root = Parse(tree, ref pos);
		int A = int.Parse(sr.ReadLine());
		for (int i = 0; i < A; i++)
		{
			string[] strings = sr.ReadLine().Split(' ');
			var features = new HashSet<string>();
			for (int j = 2; j < strings.Length; j++)
			{
				features.Add(strings[j]);
			}
			double prob = root.Eval(features);
			sw.WriteLine(prob.ToString("0.0000000", CultureInfo.InvariantCulture));
		}
	}

	private static Node Parse(string tree, ref int pos)
	{
		while (char.IsWhiteSpace(tree[pos])) pos++;
		if (tree[pos] != '(') throw new Exception();
		pos++;
		while (char.IsWhiteSpace(tree[pos])) pos++;
		int noStart = pos;
		while (!char.IsWhiteSpace(tree[pos]) && tree[pos] != ')') pos++;
		double w = double.Parse(tree.Substring(noStart, pos - noStart), CultureInfo.InvariantCulture);
		while (char.IsWhiteSpace(tree[pos])) pos++;
		Node node = new Node {Weight = w};
		if (tree[pos] == ')')
		{
			pos++;
			return node;
		}
		int featureStart = pos;
		while (char.IsLetter(tree[pos])) pos++;
		node.Feature = tree.Substring(featureStart, pos - featureStart);
		node.Left = Parse(tree, ref pos);
		node.Right = Parse(tree, ref pos);
		while (char.IsWhiteSpace(tree[pos])) pos++;
		if (tree[pos] != ')') throw new Exception();
		pos++;
		return node;
	}
}
