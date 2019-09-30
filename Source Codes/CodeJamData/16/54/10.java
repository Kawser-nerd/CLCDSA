import java.io.*;
import java.util.*;
public class d {
public static void main(String[] args) throws IOException {
	input.init(System.in);
	PrintWriter out = new PrintWriter(new File("d1.out"));
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		int n = input.nextInt(), l = input.nextInt();
		String[] good = new String[n];
		for(int i = 0; i<n; i++) good[i] = input.next();
		String bad = input.next();
		int[] a = new int[n];
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<l; j++) if(good[i].charAt(j) == '0') a[i]++;
		}
		Arrays.sort(a);
		out.print("Case #" + (t+1)+": ");
		if(a[0] == 0)
		{
			out.println("IMPOSSIBLE");
		}
		else
		{
			String res1 = "";
			for(int i = 0; i<l-1; i++) res1+="1";
			String res0 = "";
			for(int i = 0; i<l; i++)
			{
				res0 += "0";
				if(i == l-1 && res1.length() == 0) res1 += "?";
				else res0 += "?";
			}
			out.println(res0+" "+res1);
		}
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

