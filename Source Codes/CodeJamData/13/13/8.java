import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {

	public static void main(String[] args) throws Exception {
		String path = "D:\\C-small-1-attempt0";
		Scanner sc = new Scanner(new File(path + ".in"));
		PrintWriter pw = new PrintWriter(path + ".out");
		int testCases = sc.nextInt();
		for (int testCase = 1; testCase <= testCases; testCase++) {
			int R = sc.nextInt();
			int N = sc.nextInt();
			int M = sc.nextInt();
			int K = sc.nextInt();

			pw.println("Case #" + testCase + ":");

			for (int i = 0; i < R; i++) {
				Set<Integer> s = new HashSet<Integer>();
				for (int j = 0; j < K; j++) {
					s.add(sc.nextInt());
				}

				int[] b = new int[N + 1];
				Arrays.fill(b, 2);
				while (b[N] == 2) {
					Set<Integer> s1 = new HashSet<Integer>(s);
					for (int mask = 0; mask < 1 << N; mask++) {
						int p = 1;
						for (int j = 0; j < N; j++) {
							if ((mask & (1 << j)) != 0) {
								p *= b[j];
							}
						}
						s1.remove(p);
					}
					if (s1.isEmpty()) {
						break;
					}
					++b[0];
					for (int j = 0; j < N; j++) {
						if (b[j] > M) {
							b[j] = 2;
							++b[j + 1];
						}
					}
				}
				for (int j = 0; j < N; j++) {
					pw.print(b[j]);
				}
				pw.println();
				pw.flush();
			}
		}
		pw.close();
	}
}
