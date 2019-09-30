import java.io.*;
import java.util.*;
public class a {
public static void main(String[] args) throws IOException {
	input.init(System.in);
	PrintWriter out = new PrintWriter(new File("a2.out"));
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		out.print("Case #" + (t+1)+": ");
		char[] s = input.next().toCharArray();
		int n = s.length;
		int[] pref =new int[n+1];
		pref[0] = 0;
		for(int i = 0; i<n; i++) pref[i+1] = pref[i] + (s[i] == 'C' ? 1 : 0);
		int res = 0;
		Stack<Character> stk = new Stack<Character>();
		for(int i = 0; i<n; i++)
		{
			if(!stk.isEmpty() && (stk.peek() == s[i]))
			{
				stk.pop();
				res += 10;
			}
			else if(!stk.isEmpty() && n - i == stk.size())
			{
				stk.pop();
				res += 5;
			}
			else stk.push(s[i]);
		}
		out.println(res);
		
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

