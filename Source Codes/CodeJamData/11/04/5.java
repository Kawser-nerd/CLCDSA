import java.io.*;
import java.util.*;

public class GoroSort {

	public static void main(String args[]) throws Exception {
		String file =
		//	"D-example.in"
		//	"D-small-attempt0.in"
			"D-large.in"
		;
		BufferedReader in = new BufferedReader(new FileReader(file));
		PrintWriter out = new PrintWriter(new FileWriter(file + ".out"));
		final int T = Integer.parseInt(in.readLine());
		for(int casenr = 1; casenr  <= T; casenr++) {
			int N = Integer.parseInt(in.readLine());
			StringTokenizer st = new StringTokenizer(in.readLine());
			int n[] = new int[N + 1];
			for(int i = 1; i <= N; i++) {
				int j = Integer.parseInt(st.nextToken());
				if(i != j)
					n[i] = j;
			}
			int sum = 0;
			for(int i = 1; i <= N; i++)
				if(n[i] > 0) {
					int j = i;
					for(;;) {
						int p = n[j];
						if(p <= 0)
							break;
						n[j] = 0;
						j = p;
						sum++;
					}
				}

			out.println("Case #" + casenr + ": " + sum);
			out.flush();
		}
		out.close();
	}
}
