import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int cases = scan.nextInt();
		int e, r, n;
		long result;
		int[] maxE, minE;
		ArrayList<Activity> activities = new ArrayList<Activity>();
		for (int c = 1; c <= cases; c++) {
			e = scan.nextInt();
			r = scan.nextInt();
			if (r > e)
				r = e;
			n = scan.nextInt();
			activities.clear();
			for (int i = 0; i < n; i++)
				activities.add(new Activity(i, scan.nextInt()));
			Collections.sort(activities);
			maxE = new int[n];
			minE = new int[n];
			Arrays.fill(maxE, e);
			Arrays.fill(minE, 0);
			result = 0;
			for (Activity act : activities) {
				result += (maxE[act.i] - minE[act.i]) * (long) act.v;
				for (int i = act.i + 1, rNext = minE[act.i] + r;
						i < n && rNext < maxE[i]; i++, rNext += r)
					maxE[i] = rNext;
				for (int i = act.i - 1, rNext = maxE[act.i] - r;
						i >= 0 && rNext >= minE[i]; i--, rNext -= r)
					minE[i] = rNext;
			}
			System.out.println("Case #" + c + ": " + result);
		}
	}

	private static class Activity implements Comparable<Activity> {
		public final int i, v;

		public Activity(int i, int v) {
			this.i = i;
			this.v = v;
		}

		public int compareTo(Activity other) {
			return -1 * ((Integer) v).compareTo(other.v);
		}
	}
}
