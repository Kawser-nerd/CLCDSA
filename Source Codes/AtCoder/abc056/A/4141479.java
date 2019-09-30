//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		char a = sc.next().charAt(0);
		char b = sc.next().charAt(0);
		
		char ans = b;
		
		if (a == 'D') {
			if (ans == 'H') ans = 'D';
			else ans = 'H';
		}
		
		System.out.println(ans);
	}
}