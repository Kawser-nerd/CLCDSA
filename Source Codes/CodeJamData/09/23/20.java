import java.io.*;
import java.util.*;

public class SquareMath
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int tests = Integer.parseInt(in.readLine());
		for (int test = 1; test <= tests; test++)
		{
			String line = in.readLine();
			int w = Integer.parseInt(line.substring(0, line.indexOf(' ')));
			int q = Integer.parseInt(line.substring(line.indexOf(' ')+1));
			String[] square = new String[w];
			for (int i=0; i<w; i++)
				square[i] = in.readLine();
			int[] queries = splitInts(in.readLine());
			if (queries.length != q)
				System.err.println("Wrong number of queries?");
			String[] answers = new String[queries.length];
			Map<Integer,String>[][] state = null;
			do
			{
				state = next(state, square);
				for (int i=0; i<w; i++)
					for (int j=0; j<w; j++)
						if (state[i][j] != null)
							for (int k=0; k<q; k++)
								if (state[i][j].containsKey(queries[k]))
								{
									String temp = state[i][j].get(queries[k]);
									if (answers[k] == null || (temp.length() == answers[k].length() && temp.compareTo(answers[k]) < 0))
										answers[k] = temp;
								}
			}
			while (!allAnswered(answers));
			System.out.println("Case #" + test + ":");
			for (String a : answers)
				System.out.println(a);
		}
	}
	
	public static Map<Integer,String>[][] next(Map<Integer,String>[][] input, String[] square)
	{
		Map<Integer,String>[][] output = new Map[square.length][square.length];
		if (input == null)
		{
			for (int i=0; i<square.length; i++)
				for (int j=0; j<square[i].length(); j++)
					if ("-+".indexOf(square[i].charAt(j)) < 0)
					{
						output[i][j] = new HashMap<Integer,String>();
						output[i][j].put(square[i].charAt(j)-'0', square[i].substring(j, j+1));
					}
		}
		else
		{
			final int[] di = {-1, 1, 0, 0};
			final int[] dj = {0, 0, -1, 1};
			for (int i=0; i<square.length; i++)
				for (int j=0; j<square[i].length(); j++)
					if (input[i][j] != null)
						output[i][j] = new HashMap<Integer,String>();
			for (int i=0; i<square.length; i++)
				for (int j=0; j<square[i].length(); j++)
					if (input[i][j] != null)
					{
						for (int k=0; k<di.length; k++)
						{
							for (int l=0; l<di.length; l++)
							{
								int signi = i+di[k];
								int signj = j+dj[k];
								int nexti = signi+di[l];
								int nextj = signj+dj[l];
								if (nexti >= 0 && nextj >= 0 && nexti < square.length && nextj < square[nexti].length() && signi >= 0 && signj >= 0 && signi < square.length && signj < square[signi].length())
								{
									for (int start : input[i][j].keySet())
									{
										if (square[signi].charAt(signj) == '+')
										{
											int newval = start + square[nexti].charAt(nextj)-'0';
											String newexp = input[i][j].get(start) + "+" + square[nexti].charAt(nextj);
											if (!output[nexti][nextj].containsKey(newval) || newexp.compareTo(output[nexti][nextj].get(newval)) < 0)
												output[nexti][nextj].put(newval, newexp);
										}
										if (square[signi].charAt(signj) == '-')
										{
											int newval = start - (square[nexti].charAt(nextj)-'0');
											String newexp = input[i][j].get(start) + "-" + square[nexti].charAt(nextj);
											if (!output[nexti][nextj].containsKey(newval) || newexp.compareTo(output[nexti][nextj].get(newval)) < 0)
												output[nexti][nextj].put(newval, newexp);
										}
									}
								}
							}
						}
						
					}
		}
		return output;
	}
	
	public static boolean allAnswered(String[] ans)
	{
		for (int i=0; i<ans.length; i++)
			if (ans[i] == null)
				return false;
		return true;
	}
	
	public static int[] splitInts(String s)
	{
		String[] parts = s.split(" ");
		int[] ret = new int[parts.length];
		for (int i=0; i<ret.length; i++)
			ret[i] = Integer.parseInt(parts[i]);
		return ret;
	}
}
