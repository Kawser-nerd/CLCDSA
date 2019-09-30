//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int a = sc.nextInt(); int b = sc.nextInt(); int c = sc.nextInt(); 
		int ans = 0;
		if (a == b) ans = c;
		else if (b == c) ans = a;
		else ans = b;
		System.out.println(ans);
		
	}
}