//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		for (int i=0; i<=n/4; i++) {
			for (int j=0; j<=n/7; j++) {
				if (4*i + 7*j == n) {
					System.out.println("Yes");
					return;
				}
			}
		}
		
		System.out.println("No");
		
		
	}
}