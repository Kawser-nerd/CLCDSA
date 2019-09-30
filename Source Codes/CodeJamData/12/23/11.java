package round1B;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class C
{
	static class GotOne extends Exception
	{
		Set<Long> one;
		Set<Long> another;

		GotOne(Set<Long> one, Set<Long> another)
		{
			this.one = one;
			this.another = another;
		}
	}

	public static void main(String[] args) throws Exception
	{
		final String round = "1B";
		final String file = "C-large";
		BufferedReader br = new BufferedReader(new FileReader("round" + round + "/" + file + ".in"));
		PrintWriter writer = new PrintWriter(new FileWriter("round" + round + "/" + file + ".out." + System.currentTimeMillis()));

		final int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++)
		{
			String[] line = br.readLine().split("\\s");
			final int N = Integer.parseInt(line[0]);
			long[] set = new long[N];
			for (int n = 0; n < N; n++)
				set[n] = Long.parseLong(line[n + 1]);

			try
			{
				Map<Long, Set<Long>> map = new HashMap<Long, Set<Long>>();
				for (int n = 1; n < N; n++)
					registerSubsets(n, set, map);

				System.out.println("Case #" + t + ":");
				System.out.println("Impossible");
				writer.println("Case #" + t + ":");
				System.out.println("Impossible");
			}
			catch (GotOne e)
			{
				System.out.println("Case #" + t + ":");
				System.out.println(stringify(e.one));
				System.out.println(stringify(e.another));
				writer.println("Case #" + t + ":");
				writer.println(stringify(e.one));
				writer.println(stringify(e.another));
			}
		}
		writer.close();
	}

	static String stringify(Set<Long> set)
	{
		StringBuilder builder = new StringBuilder();
		for (Long i : set)
		{
			if (builder.length() > 0)
				builder.append(" ");
			builder.append(i);
		}
		return builder.toString();
	}

	static void registerSubsets(int size, long[] set, Map<Long, Set<Long>> map) throws GotOne
	{
		registerSubsets(size, 0, 0, new HashSet<Long>(), set, map);
	}

	static void registerSubsets(int size, int index, long subtotal, Set<Long> partial, long[] set, Map<Long, Set<Long>> map) throws GotOne
	{
		if (size == 0)
		{
			if (map.get(subtotal) != null)
				throw new GotOne(partial, map.get(subtotal));
			map.put(subtotal, new HashSet<Long>(partial));
		}
		else
		{
			for (int i = index; i < set.length; i++)
			{
				partial.add((long)set[i]);
				registerSubsets(size - 1, i + 1, subtotal + set[i], partial, set, map);
				partial.remove((long)set[i]);
			}
		}
	}
}
