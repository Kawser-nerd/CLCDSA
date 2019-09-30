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

		String[] ia = in.readLine().split(" ");
		final int N = Integer.parseInt(ia[0]);
		final int M = Integer.parseInt(ia[1]);

		int[] cds = new int[N];
		for (int i = 0; i < cds.length; ++i) {
			cds[i] = i + 1;
		}

		for (int b = 0, m = 0; m < M; ++m) {
			final int d = Integer.parseInt(in.readLine());
			for (int i = 0; i < cds.length; ++i) {
				if (cds[i] == d) {
					cds[i] = b;
					break;
				}
			}
			b = d;
		}

		for (int i = 0; i < cds.length; ++i) {
			System.out.println(cds[i]);
		}
	}
}