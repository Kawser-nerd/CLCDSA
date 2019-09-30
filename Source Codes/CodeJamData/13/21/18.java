import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class ProblemA {

	public static void main(String[] args) {

		try {

			final String fileIn = ProblemA.class.getSimpleName().toLowerCase() + ".in";
			final String fileOut = ProblemA.class.getSimpleName().toLowerCase() + ".out";

			final Scanner in = new Scanner(new File(fileIn));
			final PrintWriter out = new PrintWriter(new File(fileOut));

			new ProblemA().solve(in, out);

			out.flush();
			out.close();

		} catch (Exception ex) {

			ex.printStackTrace();
		}
	}

	private final void solve(final Scanner in, final PrintWriter out) throws Exception {

		final int testCount = in.nextInt();

		for (int testCase = 1; testCase <= testCount; ++testCase) {

			final int size = in.nextInt();
			final int n = in.nextInt();

			final int a[] = new int[n];

			for (int i = 0; i < n; ++i) {

				a[i] = in.nextInt();
			}

			Arrays.sort(a);

			int[] maxSize = new int[n + 2];

			Arrays.fill(maxSize, -1);

			maxSize[0] = size;

			for (int i = 0; i < n; ++i) {

				final int[] newMaxSize = new int[n + 2];

				Arrays.fill(newMaxSize, -1);

				final Queue<int[]> queue = new LinkedList<int[]>();

				for (int q = 0; q < maxSize.length; ++q) {

					if (maxSize[q] == -1) {

						continue;
					}

					queue.add(new int[] { q, maxSize[q] });
				}

				while (!queue.isEmpty()) {

					final int[] rec = queue.poll();

					final int cnt = rec[0];
					final int cntSize = rec[1];

					if (cntSize > a[i]) {

						if (newMaxSize[cnt] == -1 || newMaxSize[cnt] < cntSize + a[i]) {

							newMaxSize[cnt] = cntSize + a[i];
						}
					} else {

						if (cntSize > 1 && cnt + 1 < maxSize.length) {

							if (maxSize[cnt + 1] != -1 && cntSize + cntSize - 1 <= maxSize[cnt + 1]) {

							} else {

								maxSize[cnt + 1] = cntSize + cntSize - 1;

								queue.add(new int[] { cnt + 1, cntSize + cntSize - 1 });
							}
						}

						if (cnt + 1 < maxSize.length && (newMaxSize[cnt + 1] == -1 || newMaxSize[cnt + 1] < cntSize)) {

							newMaxSize[cnt + 1] = cntSize;
						}
					}
				}

				maxSize = newMaxSize;
			}

			int result = 0;

			for (int i = 0; i < maxSize.length; ++i) {

				if (maxSize[i] == -1) {
					continue;
				}

				result = i;
				break;
			}

			out.printf("Case #%d: %d%n", testCase, result);
		}
	}
}
