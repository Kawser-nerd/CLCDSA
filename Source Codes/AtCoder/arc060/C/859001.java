import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.Exception;
import java.util.Arrays;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		long[] x = new long[n];

		String[] tempX = br.readLine().split(" ");
		for (int i = 0; i < n; i++) 
			x[i] = Long.parseLong(tempX[i]);
		

		long l = Long.parseLong(br.readLine());
		int q = Integer.parseInt(br.readLine());

		int[] aa = new int[q];
		int[] bb = new int[q];

		for (int i = 0; i < q; i++) {
			String[] temp = br.readLine().split(" ");
			aa[i] = Integer.parseInt(temp[0])-1;
			bb[i] = Integer.parseInt(temp[1])-1;
		}


		int[][] dp = new int[n][17];
		int[] length = new int[n];


		int j = Math.abs(Arrays.binarySearch(x, x[0]+l)+1);
		int limit = 0;
		for (int i = 0; i < n; i++) {
			long bound = x[i] + l;
			for (; j < n && x[j] <= bound; j++);
			if (j == n) {
				limit = i;
				break;
			}
			else {
				dp[i][0] = j-1;
				length[i] = 1;
			}
		}

		for (int d = 0; limit > 0; d++) {
			for (int i = 0; i < limit; i++) {
				int t = dp[i][d];
				if (t < limit) {
					dp[i][d+1] = dp[t][d];
					length[i] += 1;
				}
				else {
					limit = i;
					break;
				}
			}
		}

		for (int i = 0; i < q; i++) {
			int a = aa[i];
			int b = bb[i];
			if (a > b) {
				int temp = a;
				a = b;
				b = temp;
			}

			int p = Math.abs(Arrays.binarySearch(dp[a], 0, length[a], b)+1) - 1;
			int cnt = 0;
			while (p >= 0) {
				cnt |= 1 << p;
				a = dp[a][p];
				p = Math.abs(Arrays.binarySearch(dp[a], 0, length[a], b)+1) - 1;
			}

			if (a < b)
				cnt++;
			System.out.println(cnt);
		}

	}
}