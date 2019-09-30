import java.util.*;
import java.io.*;
import java.math.*;

public class A {
	public static void main(String[] args) throws IOException {
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Scanner sc = new Scanner(new InputStreamReader(System.in));
		int T = sc.nextInt(); for (int t=1; t<=T; t++) {
			int N = sc.nextInt();

			int[][] nums = new int[N][3];
			for (int i=0; i<N; i++)
			for (int j=0; j<3; j++) nums[i][j] = sc.nextInt();


			int ans = 0;
			for (int i=0; i<N; i++)
			{

Vector<Integer> low = new Vector<Integer>();
			Vector<Integer> high = new Vector<Integer>();
				int cur = 0;
				int A = nums[i][0];
				//System.out.println("Trying A = "+A);
				for (int j=0; j<N; j++) {
					if (A<nums[j][0]) continue;
					if (nums[j][1]<=10000-A-nums[j][2]) {
					low.add(nums[j][1]);
					high.add(10000-A-nums[j][2]);
					//System.out.println(j+" "+"Add "+nums[j][1]+" "+(10000-A-nums[j][2]));
				}

					// nums[j][1]
				}
				if (low.size()==0) continue;
				//System.out.println(i+" "+low.size());
				Collections.sort(low);
				Collections.sort(high);
				int lc = 0, hc = 0, lcur=low.get(0), hcur=high.get(0);
				while (lc<low.size()) {

					if (lcur<=hcur) {
						cur++;
						ans = Math.max(ans,cur);
						lc++;
						if (lc<low.size()) lcur=low.get(lc);
					} else {
						cur--;
						hc++;
						if (hc<high.size()) hcur=high.get(hc);
					}
				}
			}

			System.out.println("Case #"+t+": "+ans);
		}
	}
}