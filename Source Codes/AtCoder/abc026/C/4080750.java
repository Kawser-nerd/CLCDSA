import java.util.*;

public class Main {
	static ArrayList<Integer>[] lists;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		lists = new ArrayList[n + 1];
		for (int i = 1; i <= n; i++) {
			lists[i] = new ArrayList<Integer>();
		}
		for (int i = 2; i <= n; i++) {
			int x = sc.nextInt();
			lists[x].add(i);
		}
		System.out.println(getIncome(1));
	}
	
	static int getIncome(int idx) {
		if (lists[idx].size() == 0) {
			return 1;
		}
		int max = 0;
		int min = Integer.MAX_VALUE;
		for (int x : lists[idx]) {
			int y = getIncome(x);
			if (max < y) {
				max = y;
			}
			if (min > y) {
				min = y;
			}
		}
		return max + min + 1;
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.