import java.io.*;
import java.security.SecureRandom;
import java.util.*;
import java.math.*;

public class Main {
	static boolean debug = false;
	static boolean debug2 = false;

	public static void main(String[] args) throws java.io.IOException {
		debug = 1 <= args.length;
		debug2 = 2 <= args.length;

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		String[] ia = in.readLine().split(" ");
		final int N = Integer.parseInt(ia[0]);
		final int M = Integer.parseInt(ia[1]);
		final int K = Integer.parseInt(ia[2]);

		if (N == 2 && 0 < M) {
			System.out.println(0);
			return;
		}

		boolean[][] pair = new boolean[N][N];
		for (int i = 0; i < M; ++i) {
			ia = in.readLine().split(" ");
			final int A = Integer.parseInt(ia[0]);
			final int B = Integer.parseInt(ia[1]);
			pair[A][B] = pair[B][A] = true;
		}

		final int count = 10000000 / N;
		int valid = 0;
		int[] line = new int[N];
		Random sr = new Random();
		test:
		for (int c = 0; c < count; ++c) {
			for (int i = 0; i < line.length; ++i) {
				line[i] = i;
			}
			for (int i = 0; i < K; ++i) {
				final int a = sr.nextInt(N);
				while (true) {
					final int b = sr.nextInt(N);
					if (a != b) {
						final int t = line[a];
						line[a] = line[b];
						line[b] = t;
						break;
					}
				}
			}
			for (int i = 1; i < line.length; ++i) {
				if (pair[line[i - 1]][line[i]]) {
					continue test;
				}
			}
			if (!pair[line[line.length - 1]][line[0]]) {
				++valid;
			}
		}

		System.out.println(String.format("%.9f", 1.0 * valid / count));
	}
}