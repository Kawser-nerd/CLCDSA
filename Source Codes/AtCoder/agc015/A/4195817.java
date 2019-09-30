//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		long n = sc.nextLong(); long a = sc.nextLong(); long b = sc.nextLong();
		if (a > b) System.out.println(0);
		else {
			if (n == 1) {
			if (a != b) System.out.println(0);
			else System.out.println(1);
		}
		else System.out.println((b-a)*(n-2)+1);
		}
		
		
	}
}