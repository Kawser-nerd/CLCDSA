import java.io.*;
import java.util.*;

public class Main {
	private static boolean canReach(List<Integer> dists, int target) {
		int sum = 0;
		for (int d : dists) {
			sum += d;
		}
		if ((sum + target) % 2 != 0) {
			return false;
		}
		if ((target > sum) || (target < -1*sum)) {
			return false;
		}
		int realTarget = (sum + target) / 2;
		boolean[][] dp = new boolean[dists.size() + 1][sum + 1];
		dp[0][0] = true;
		for (int i = 1; i <= dists.size(); i++) {
			int next = dists.get(i - 1);
			for (int j = 0; j <= sum; j++) {
				dp[i][j] = dp[i - 1][j];
			}
			for (int j = 0; j <= sum - next; j++) {
				dp[i][j + next] = dp[i][j + next] || dp[i - 1][j];
			}
		}
		return dp[dists.size()][realTarget];
	}
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		String s = f.readLine();
		StringTokenizer st = new StringTokenizer(f.readLine());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		List<Integer> xSet = new ArrayList<>();
		List<Integer> ySet = new ArrayList<>();
		int counter = 0;
		while (counter < s.length() && s.charAt(counter) == 'F') {
			counter++;
		}
		x -= counter;
		int start = counter + 1;
		boolean isX = false;
		counter = 0;
		for (int i = start; i < s.length(); i++) {
			if (s.charAt(i) == 'T') {
				if (isX) {
					xSet.add(counter);
				} else {
					ySet.add(counter);
				}
				isX = !isX;
				counter = 0;
			} else {
				counter++;
			}
		}
		if (isX) {
			xSet.add(counter);
		} else {
			ySet.add(counter);
		}
		boolean good = canReach(xSet, x) && canReach(ySet, y);
		if (good) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}

}