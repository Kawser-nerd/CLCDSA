//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		int n = sc.nextInt(); int k = sc.nextInt();
		int ans = 1;
		for (int i=0; i<n; i++) {
			ans = Math.min(ans+k, 2*ans);
		}
		System.out.println(ans);
		
	}
}