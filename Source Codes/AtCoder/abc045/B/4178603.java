//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		String sA = sc.next();
		String sB = sc.next();
		String sC = sc.next();
		
		int a = -1;
		int b = -1;
		int c = -1;
		
		char turn = 'a';
		String ans = "";
		
		while (true) {
			if (turn == 'a') {
				a++;
				if (a == sA.length()) {
					ans = "A";
					break;
				}
				turn = sA.charAt(a);

			}
			else if (turn == 'b') {

				b++;
				if (b == sB.length()) {
					ans = "B";
					break;
				}
				turn = sB.charAt(b);
			}
			else if (turn == 'c') {
				c++;
				if (c == sC.length()) {
					ans = "C";
					break;
				}
				turn = sC.charAt(c);
			}
		}
		
		System.out.println(ans);
	}
}