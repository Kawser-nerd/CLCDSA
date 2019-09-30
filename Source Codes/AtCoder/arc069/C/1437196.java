import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[][] a = new long[n][2];

		for (int i = 0; i < n; ++i) {
			a[i][0] = sc.nextLong();
			a[i][1] = i;
		}
		// ????????
		Arrays.sort(a, new Comparator<long[]>() {
			@Override
			public int compare(long[] o1, long[] o2) {
				if (o1[0] != o2[0]) {
					return -Long.compare(o1[0], o2[0]);
				} else {
					return Long.compare(o1[1], o2[1]);
				}
			}
		});
		long[] cnt = new long[n];
		int s = 0, t = 0;
		while (true) {
			if (s == n)
				break;
			while (t != n && a[s][1] <= a[t][1]) {
				++t;
			}
			cnt[(int) a[s][1]] += (a[s][0] - (t == n ? 0 : a[t][0])) * s;
			// [s:t-1]???????????
			for (int i = t - 1; i >= s; --i) {
				cnt[(int) a[s][1]] += (a[i][0] - (t == n ? 0 : a[t][0]));
			}
			s = t;
		}
		for(int i=0;i<cnt.length;++i){
			System.out.println(cnt[i]);
		}
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}