//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		int ans = 0;
		for (int i=0; i<n; i++) {
			int l = sc.nextInt(); int r = sc.nextInt();
			ans += r - l + 1;
		}
		
		System.out.println(ans);
		
		
		
	}
}