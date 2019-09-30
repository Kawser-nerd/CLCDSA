using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace A
{
	public class Node
	{
		public double weight;
		
		public string feature;
		public Node left, right;
	}
	
	public class Program
	{
		static string tree;
		static int pos;
		
		static void Main(string[] args)
		{
			string[] input = File.ReadAllLines( "input.txt");
			int n = int.Parse(input[0]);
			int line = 1;
			List<string> output = new List<string>();
			for( int i = 1; i <= n; i++)
			{
				output.Add( "Case #"+i+":");
				int l = int.Parse(input[line++]);
				
				tree = "";
				while(l-- > 0)
					tree += input[line++];
					
				pos = 0;
				Node root = ParseTree();
					
				int a = int.Parse(input[line++]);
				while(a-- > 0)
				{
					string q = input[line++];
					string[] parts = q.Split( ' ', '\t');
					
					string name = parts[0];
					string[] features = parts.Skip(2).ToArray();
					
					double prob = FindProb( root, features);
					output.Add( string.Format( "{0:0.0000000}", prob));
				}
			}
			File.WriteAllLines( "output.txt", output.ToArray());
		}

		private static double FindProb(Node root, string[] features)
		{
			if( root.feature == null)
				return root.weight;
			else
				if( features.Contains( root.feature))
					return root.weight * FindProb( root.left, features);
				else
					return root.weight * FindProb( root.right, features);
		}
		
		private static void SkipSpace()
		{
			while( char.IsWhiteSpace( tree[pos]))
				pos++;
		}

		private static Node ParseTree()
		{
			Node node = new Node();
			
			SkipSpace();
			
			Debug.Assert( tree[pos] == '(');
			pos++;
			
			SkipSpace();
			
			int endpos = pos;
			while( tree[endpos] != ')' && tree[endpos] != '(' && !char.IsWhiteSpace(tree[endpos]))
				endpos++;
			node.weight = double.Parse( tree.Substring( pos, endpos-pos));
			pos = endpos;
			
			SkipSpace();
			
			if( tree[pos] == ')')
			{
				pos++;
				return node;
			}
				
			endpos = pos;
			while( tree[endpos] != '(' && !char.IsWhiteSpace(tree[endpos]))
				endpos++;
			node.feature = tree.Substring( pos, endpos-pos);	
			pos = endpos;
			
			node.left = ParseTree();
			node.right = ParseTree();
			
			SkipSpace();
			
			Debug.Assert( tree[pos] == ')');
			pos++;
			
			return node;
		}
	}
}
