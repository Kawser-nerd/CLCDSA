import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	static int[] type;
	static int[] num;
	static int n;
	static int[][] dp;

	public static int f(int i, int mask) {
		if (mask == (1 << n) - 1)
			return 0;
		if (i >= 16)
			return 16;

		if (dp[i][mask] != -1)
			return dp[i][mask];
		int result = 16;
		int left = mask ^ ((1 << n) - 1);
		for (int j = left; j >= 0; j = (j - 1) & left) {
			boolean niceMask = true;
			int last = 3;
			for (int k = 0; k < n && niceMask; k++) {
				if ((j & 1 << k) != 0) {
					if (num[k] != i && num[k] != 0)
						niceMask = false;
					else {
						if ((last & type[k]) != type[k])
							niceMask = false;
						else
							last = 3 ^ type[k];
					}
				} else {
					if (num[k] == i)
						niceMask = false;
				}
			}
			if (niceMask) {
				int add = 0;
				if (last == 2)
					add = 1;
				result = Math.min(result, add + f(i + 1, mask | j));
			}
			if (j == 0)
				break;
		}
		return dp[i][mask] = result;
	}

	public static void main(String[] args) throws Exception {
		 Scanner in = new Scanner(new File("C.in"));
//		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter("C.out");
		int tc = in.nextInt();
		for (int cc = 1; cc <= tc; cc++) {
			n = in.nextInt();
			type = new int[n];
			num = new int[n];
			dp = new int[16][1 << n];
			for (int[] a : dp)
				Arrays.fill(a, -1);
			for (int i = 0; i < n; i++) {
				String s = in.next();
				int v = in.nextInt();
				type[i] = s.equals("E") ? 1 : 2;
				num[i] = v;
			}
			int[] nums = num.clone();
			Arrays.sort(nums);
			int[] id = new int[2005];
			Arrays.fill(id, -1);
			id[0] = 0;
			int top = 1;
			for (int i = 0; i < n; i++) {
				if (id[nums[i]] == -1)
					id[nums[i]] = top++;
			}
			 System.out.println(Arrays.toString(num));
			for (int i = 0; i < n; i++)
				num[i] = id[num[i]];
			 System.out.println(Arrays.toString(num));
			// System.out.println();
			// System.out.println();
			int result = f(1, 0);
			if (result < 16) {
				System.out.printf("Case #%d: %d\n", cc, result);
				out.printf("Case #%d: %d\n", cc, result);
			} else {
				System.out.printf("Case #%d: %s\n", cc, "CRIME TIME");
				out.printf("Case #%d: %s\n", cc, "CRIME TIME");
			}
		}
		out.close();
	}

}
