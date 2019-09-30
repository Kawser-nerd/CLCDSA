import java.util.*;

public class b {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int numCases = stdin.nextInt();

		for (int loop=1; loop<=numCases; loop++) {

			int n = stdin.nextInt();
			int k = stdin.nextInt();
			int[] smooth = new int[n-k+1];
			for (int i=0; i<smooth.length; i++)
				smooth[i] = stdin.nextInt();

			int[] offset = new int[n];
			for (int i=k; i<n; i++)
				offset[i] = offset[i-k] + smooth[i-k+1] - smooth[i-k];

			// Figures out each range.
			int[][] ranges = new int[k][2];
			for (int i=0; i<k; i++) {
				for (int j=i; j<n; j+=k) {
					ranges[i][0] = Math.min(ranges[i][0], offset[j]);
					ranges[i][1] = Math.max(ranges[i][1], offset[j]);
				}
			}

			int widest = 0, mWidth = ranges[0][1] - ranges[0][0];

			for (int i=1; i<k; i++) {
				if (ranges[i][1] - ranges[i][0] > mWidth) {
					widest = i;
					mWidth = ranges[i][1] - ranges[i][0];
				}
			}

			// Here is the fudge factor.
			int min = 0, max = 0;
			for (int i=0; i<k; i++) {
				min += (ranges[widest][0] - ranges[i][0]);
				max += (ranges[widest][1] - ranges[i][1]);
			}

			int res = -1;
			if (max - min >= k)  res = mWidth;
			else {
				int target = smooth[0]%k;
				if (target < 0) target += k;
				int low = min%k;
				if (low < 0) low += k;
				int high = max%k;
				if (high < 0) high += k;

				if (low <= high) {
					if (low <= target && target <= high) res = mWidth;
					else res = mWidth+1;
				}
				else {
					if (target <= low || target >= high) res = mWidth;
					else res = mWidth+1;
				}
			}

			System.out.println("Case #"+loop+": "+res);
		}
	}
}