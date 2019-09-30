//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		int k = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		
		if (n-k > 0) System.out.println(k*x+(n-k)*y);
		else System.out.println(n*x);
		
	}
}