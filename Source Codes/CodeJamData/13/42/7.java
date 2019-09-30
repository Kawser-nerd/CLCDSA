import java.io.*;
import java.util.*;

public class Main {
//	static Scanner in;
	static PrintWriter out;
//	static StreamTokenizer in; static int next() throws Exception {in.nextToken(); return (int) in.nval;}
	static BufferedReader in;

	public static void main(String[] args) throws Exception {
//		in = new Scanner(System.in);
		out = new PrintWriter(System.out);
//		in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		in = new BufferedReader(new InputStreamReader(System.in));
		
		String text = in.readLine();
		int tests = Integer.parseInt(text);

		for (int test = 1; test <= tests; test++) {
			
			String[] texts = in.readLine().split(" ");
			int n = Integer.parseInt(texts[0]);
			long p = Long.parseLong(texts[1]);

			long place = 1L << n;
			int t = 0;
			while (place > p) {
				place >>= 1;
				t++;
			}
			long answ2 = (1L << n) - (1L << t);
			
			t = 1;
			place = (1L << n) - p;
			for (int i = n - 1; i >= 0; i--) {
				if (((1L << i) & place) == 0) t++;
				else break;
			}
			long answ1 = Math.min((1L << t) - 2, (1L << n) - 1);
			
			out.print("Case #" + test + ": ");
			out.println(answ1 + " " + answ2);
		}

		out.close();
	}
}
