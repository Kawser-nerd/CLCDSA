import java.util.*;

public class Main {
	static ArrayList<Integer>[] lists;

	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		lists = new ArrayList[n + 1];
		for (int i = 1; i <= n; i++) {
			lists[i] = new ArrayList<Integer>();
		}
		int[] a = new int[m];
		int[] b = new int[m];
		for (int i = 0; i < m; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			lists[a[i]].add(b[i]);
			lists[b[i]].add(a[i]);
		}
		int count = 0;
		for (int i = 0; i < m; i++) {
			boolean[] test = new boolean[n + 1];
			Arrays.fill(test, false);
			search(1, a[i], b[i], test);
			if (!isAllTrue(test)) {
				count++;
			}
		}
		System.out.print(count);
	}
	
	static void search(int idx, int a, int b, boolean[] test) {
		for (int i : lists[idx]) {
			if (!test[i] && !((a == i && b == idx) || (a == idx && b == i))) {
				test[i] = true;
				search(i, a, b, test);
			}
		}
	}
	
	static boolean isAllTrue(boolean[] bs) {
		for (int i = 1; i < bs.length; i++) {
			if (!bs[i]) {
				return false;
			}
		}
		return true;
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.