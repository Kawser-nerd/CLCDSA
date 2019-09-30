import java.io.*;
import java.util.*;
public class b {
public static void main(String[] args) throws IOException {
	input.init(System.in);
	PrintWriter out = new PrintWriter(System.out);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		String s = input.next()+"+";
		int res = 0;
		for(int i = 0; i<s.length()-1; i++) if(s.charAt(i) != s.charAt(i+1)) res++;
		out.println("Case #" + (t+1)+": "+res);
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

