//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		String[] ar = new String[3];
		for (int i=0; i<3; i++) ar[i] = sc.next();
		String ans = "";
		
		for (int i=0; i<3; i++) {
			ans += ar[i].charAt(0);
		}
		
		System.out.println(ans.toUpperCase());
	}
}