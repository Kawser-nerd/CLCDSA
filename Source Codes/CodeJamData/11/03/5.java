import java.io.*;
import java.util.*;

public class CandySplitting {

	public static void main(String args[]) throws Exception {
		String file =
		//	"C-example.in"
		//	"C-small-attempt0.in"
			"C-large.in"
		;
		BufferedReader in = new BufferedReader(new FileReader(file));
		PrintWriter out = new PrintWriter(new FileWriter(file + ".out"));
		final int T = Integer.parseInt(in.readLine());
		for(int casenr = 1; casenr  <= T; casenr++) {
			int N = Integer.parseInt(in.readLine());
			StringTokenizer st = new StringTokenizer(in.readLine());
			int sum = 0;
			int min = 10000000;
			int xor = 0;
			for(int i = 0; i < N; i++) {
				int c = Integer.parseInt(st.nextToken());
				sum += c;
				if(c < min)
					min = c;
				xor ^= c;
			}
			out.println("Case #" + casenr + ": " + (xor != 0 ? "NO" : Integer.toString(sum - min)));
			out.flush();
		}
		out.close();
	}
}
