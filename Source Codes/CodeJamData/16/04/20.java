import java.io.*;
import java.util.*;
public class d {
public static void main(String[] args) throws IOException {
	input.init(System.in);
	PrintWriter out = new PrintWriter(System.out);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		int k = input.nextInt(), c = input.nextInt(), s = input.nextInt();
		out.print("Case #" + (t+1)+":");
		if(s*c < k)
		{
			out.println(" IMPOSSIBLE");
			continue;
		}
		HashSet<Long> set = new HashSet<Long>();
		for(int i = 0; i<s; i++)
		{
			int[] vals = new int[c];
			for(int j = 0; j<c; j++)
			{
				vals[j] = (i*c + j)%k;
			}
			long cur = 0;
			long max = 1;
			for(int x : vals)
			{
				cur *= k;
				max *= k;
				cur += x;
			}
			while(set.contains(cur)) cur = (cur+1)%max;
			set.add(cur);
			cur++;
			out.print(" "+cur);
		}
		out.println();
	}
	out.close();
}

public static class input {
	static BufferedReader reader;
	static StringTokenizer tokenizer;

	static void init(InputStream input) {
		reader = new BufferedReader(new InputStreamReader(input));
		tokenizer = new StringTokenizer("");
	}

	static String next() throws IOException {
		while (!tokenizer.hasMoreTokens())
			tokenizer = new StringTokenizer(reader.readLine());
		return tokenizer.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
}
}

