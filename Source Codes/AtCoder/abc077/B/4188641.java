//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		
		int ans = 0;
		for (int i=1; i<100000; i++) {
			ans = i*i;
			if (ans == n) break;
			else if (ans > n) {
				ans = (i-1)*(i-1);
				break;
			}
		}
		
		System.out.println(ans);
		
	}
}