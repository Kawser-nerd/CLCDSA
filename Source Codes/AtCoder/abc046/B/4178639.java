//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		Long n = sc.nextLong();
		Long k = sc.nextLong();
		System.out.println(k*((long)Math.pow(k-1,n-1)));
		
	}
}