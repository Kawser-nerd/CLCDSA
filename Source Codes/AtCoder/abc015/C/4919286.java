import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[][] t = new int[n][k];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				t[i][j] = sc.nextInt();
			}
		}
		sc.close();

		boolean ret = dfs(n, k, t, new ArrayList<Integer>());
		if (ret) {
			System.out.println("Found");
		} else {
			System.out.println("Nothing");
		}
	}

	static boolean dfs(int n, int k, int[][] t, List<Integer> list) {
		if (list.size() == n) {
			int xor = 0;
			for (int val : list) {
				xor = xor ^ val;
			}
			if (xor == 0) {
				return true;
			} else {
				return false;
			}
		}

		for (int j = 0; j < k; j++) {
			List<Integer> list2 = new ArrayList<Integer>(list);
			list2.add(t[list.size()][j]);
			boolean ret = dfs(n, k, t, list2);
			if (ret) {
				return true;
			}
		}
		return false;
	}
}