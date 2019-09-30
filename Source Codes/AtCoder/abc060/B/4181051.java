//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		int a = sc.nextInt(); int b = sc.nextInt(); int c = sc.nextInt();
		
		for (int i=1; i<=b; i++) {
			if (a*i%b == c) {
				System.out.println("YES");
				return;
			}
		};
		
		System.out.println("NO");
		
	}
}