//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		String s = sc.next();
		
		int max = 0;
		int x = 0;
		for (int i=0; i<s.length(); i++) {
			if (s.charAt(i) == 'I') {
				x++;
				max = Math.max(max, x);
			}
			else {
				x--;
				max = Math.max(max, x);
			}
		}
		
		System.out.println(max);
		
		
	}
}