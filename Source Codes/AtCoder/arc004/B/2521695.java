import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static boolean debug = false;
	static boolean debug2 = false;

	public static void main(String[] args) throws java.io.IOException {
		debug = 1 <= args.length;
		debug2 = 2 <= args.length;

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		final int N = Integer.parseInt(in.readLine());
		int[] d = new int[N];
		int max = 0;
		for (int i = 0; i < N; ++i) {
			max += d[i] = Integer.parseInt(in.readLine());
		}

		int min = Integer.MAX_VALUE;
		switch (N) {
			case 1:
				min = max;
				break;
			case 2:
				min = Math.abs(d[1] - d[0]);
				break;
			default:
				for (int i = 1, a = d[0]; i < N; a += d[i++]) {
					for (int j = i + 1; j < N; ++j) {
						int b = 0;
						for (int n = i; n < j; ++n) {
							b += d[n];
						}
						int c = 0;
						for (int n = j; n < N; ++n) {
							c += d[n];
						}
						int[] abc = new int[]{a, b, c};
						Arrays.sort(abc);
						if (abc[0] + abc[1] < abc[2]) {
							min = Math.min(min, abc[2] - abc[1] - abc[0]);
						} else {
							min = 0;
						}
					}
				}
				break;
		}

		System.out.println(max);
		System.out.println(min);
	}
}