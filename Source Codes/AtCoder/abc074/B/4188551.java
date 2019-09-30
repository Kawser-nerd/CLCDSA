//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		int k = sc.nextInt();
		
		int ans = 0;
		for (int i=0; i<n; i++) {
			int x = sc.nextInt();
			ans += 2 * Math.min(Math.abs(x-0), Math.abs(x-k));
		}
		
		System.out.println(ans);
		
	}
}