package CodeJam;

import java.util.*;
import java.io.*;
import org.apache.commons.lang.StringUtils;
import org.apache.commons.lang.ArrayUtils;
import java.lang.Math.*;
import java.math.BigInteger;
import static helper.Print.*;


public class B {

	private static String inFilename = "C-small-attempt0.in";

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileReader("src/CodeJam/" + inFilename));
		PrintWriter out = new PrintWriter(new FileWriter("src/CodeJam/output.txt"));
		int T = in.nextInt();

		for (int t = 0; t < T; t++) {
			String result = "NO";

			int N = in.nextInt();
			int L = in.nextInt();
			int H = in.nextInt();
			int[] f = new int[N];
			for (int i = 0; i < N; i++) {
				f[i] = in.nextInt();
			}

			loop:
			for (int i = L; i <= H; i++) {
				int j = 0;
				for (; j < N; j++) {
					if ( ! (f[j] % i == 0 || i % f[j] == 0)) {
						continue loop;
					}
				}
				if (j == N) {
					result = String.valueOf(i);
					break;
				}
			}

//			if (t == 1) {
//				print(N);
//				print(L);
//				print(H);
//				print(f);
//			}


			out.print("Case #" + (t+1) + ": " + result + "\n");
		}

		in.close();
		out.close();
	}

}