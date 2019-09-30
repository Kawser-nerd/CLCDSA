import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.HashSet;
import java.util.Locale;
import java.util.Set;

// 1.6
public class A implements Runnable
{
	static final String NAME = "a-large";

	static class Tree
	{
		double w;

		String feature;

		Tree left;

		Tree right;

		public Tree()
		{
			w = 1;
			feature = null;
			left = null;
			right = null;
		}
	}

	public String parse(Tree tree, String s)
	{
		int pos = s.indexOf('(') + 1;
		while (Character.isSpaceChar(s.charAt(pos)))
			pos++;
		int newpos = pos;
		while (Character.isLetterOrDigit(s.charAt(newpos)) || s.charAt(newpos) == '.')
			newpos++;
		tree.w = Double.parseDouble(s.substring(pos, newpos));
		pos = newpos;
		while (Character.isSpaceChar(s.charAt(pos)))
			pos++;
		if (s.charAt(pos) == ')')
		{
			return s.substring(pos + 1);
		}
		newpos = pos;
		while (Character.isLetterOrDigit(s.charAt(newpos)))
			newpos++;
		tree.feature = s.substring(pos, newpos);
		pos = newpos;
		tree.left = new Tree();
		s = parse(tree.left, s.substring(pos));
		tree.right = new Tree();
		s = parse(tree.right, s);
		pos = s.indexOf(')');
		return s.substring(pos + 1);
	}

	public Tree parse(String s)
	{
		Tree root = new Tree();
		parse(root, s);
		return root;
	}

	public double calc(Tree tree, Set<String> featureSet)
	{
		double res = tree.w;
		if (tree.feature != null)
		{
			if (featureSet.contains(tree.feature))
			{
				res *= calc(tree.left, featureSet);
			}
			else
			{
				res *= calc(tree.right, featureSet);
			}
		}
		return res;
	}

	public void solve() throws Exception
	{
		DecimalFormat df = new DecimalFormat("###0.0000000");
		int tests = Integer.parseInt(stdin.readLine());
		for (int test = 1; test <= tests; test++)
		{
			stdout.write("Case #" + test + ":\n");
			int lines = Integer.parseInt(stdin.readLine());
			StringBuilder b = new StringBuilder();
			for (int i = 0; i < lines; i++)
			{
				b.append(stdin.readLine());
			}
			Tree root = parse(b.toString());
			int animals = Integer.parseInt(stdin.readLine());
			for (int i = 0; i < animals; i++)
			{
				String s = stdin.readLine().trim();
				String[] ss = s.split("\\s+");
				String name = ss[0];
				int features = Integer.parseInt(ss[1]);
				Set<String> featureSet = new HashSet<String>();
				for (int j = 0; j < features; j++)
				{
					featureSet.add(ss[j + 2]);
				}
				stdout.write(df.format(calc(root, featureSet)) + "\n");
			}

		}
	}

	static BufferedReader stdin;

	static BufferedWriter stdout;

	String readWord() throws Exception
	{
		StringBuilder b = new StringBuilder();
		int c;
		while (true)
		{
			c = stdin.read();
			if (c < 0)
			{
				return "";
			}
			if (c > 32)
			{
				break;
			}
		}
		while (true)
		{
			b.append((char) c);
			c = stdin.read();
			if (c <= 32)
			{
				break;
			}
		}
		return b.toString();
	}

	public void run()
	{
		try
		{
			stdin = new BufferedReader(new FileReader(NAME + ".in"));
			stdout = new BufferedWriter(new FileWriter(NAME + ".out"));
			solve();
			stdout.close();
			stdin.close();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}

	public static void main(String[] args)
	{
		try
		{
			Locale.setDefault(Locale.US);
		}
		catch (Throwable e)
		{
		}
		new Thread(new A()).start();
	}
}
