import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[][] p = new long[N][2];
		for (int i = 0; i < N; ++i) {
			p[i][0] = sc.nextLong();
			p[i][1] = sc.nextLong();
			Arrays.sort(p[i]);
		}
		Arrays.sort(p, new Comparator<long[]>() {
			@Override
			public int compare(long[] o1, long[] o2) {
				return Long.compare(o1[0], o2[0]);
			}
		});

		solve(N, p);
	}

	void solve(int N, long[][] p) {
		long ans = Long.MAX_VALUE;

		{
			long Rmax = -Long.MAX_VALUE / 16;
			long Bmax = -Long.MAX_VALUE / 16;
			long Rmin = Long.MAX_VALUE / 16;
			long Bmin = Long.MAX_VALUE / 16;
			for (int i = 0; i < N; ++i) {
				Rmax = Math.max(Rmax, p[i][1]);
				Rmin = Math.min(Rmin, p[i][1]);
				Bmax = Math.max(Bmax, p[i][0]);
				Bmin = Math.min(Bmin, p[i][0]);
			}
			ans = Math.min(ans, (Rmax - Rmin) * (Bmax - Bmin));
		}

		{
			long[] uXmin = new long[N];
			long[] lXmin = new long[N];
			long[] uXmax = new long[N];
			long[] lXmax = new long[N];
			long[] uYmin = new long[N];
			long[] lYmin = new long[N];
			long[] uYmax = new long[N];
			long[] lYmax = new long[N];
			for (int i = 0; i < N; ++i) {
				uXmin[i] = Math.min(i > 0 ? uXmin[i - 1] : Long.MAX_VALUE / 16, p[i][0]);
				uXmax[i] = Math.max(i > 0 ? uXmax[i - 1] : -Long.MAX_VALUE / 16, p[i][0]);
				uYmin[i] = Math.min(i > 0 ? uYmin[i - 1] : Long.MAX_VALUE / 16, p[i][1]);
				uYmax[i] = Math.max(i > 0 ? uYmax[i - 1] : -Long.MAX_VALUE / 16, p[i][1]);
			}
			for (int i = N - 1; i >= 0; --i) {
				lXmin[i] = Math.min(i + 1 < N ? lXmin[i + 1] : Long.MAX_VALUE / 16, p[i][0]);
				lXmax[i] = Math.max(i + 1 < N ? lXmax[i + 1] : -Long.MAX_VALUE / 16, p[i][0]);
				lYmin[i] = Math.min(i + 1 < N ? lYmin[i + 1] : Long.MAX_VALUE / 16, p[i][1]);
				lYmax[i] = Math.max(i + 1 < N ? lYmax[i + 1] : -Long.MAX_VALUE / 16, p[i][1]);
			}
			for (int i = 0; i < N; ++i) {
				long Rmax = Math.max(uXmax[i], i + 1 < N ? lYmax[i + 1] : -Long.MAX_VALUE / 16);
				long Rmin = Math.min(uXmin[i], i + 1 < N ? lYmin[i + 1] : Long.MAX_VALUE / 16);
				long Bmax = Math.max(uYmax[i], i + 1 < N ? lXmax[i + 1] : -Long.MAX_VALUE / 16);
				long Bmin = Math.min(uYmin[i], i + 1 < N ? lXmin[i + 1] : Long.MAX_VALUE / 16);
				ans = Math.min(ans, (Rmax - Rmin) * (Bmax - Bmin));
			}
		}
		System.out.println(ans);

	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}