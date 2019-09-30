//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		String[] ar = new String[3];
		for (int i=0; i<3; i++) ar[i] = sc.next();
		
		if (ar[0].charAt(ar[0].length()-1)==ar[1].charAt(0) && ar[1].charAt(ar[1].length()-1)==ar[2].charAt(0)) {
			System.out.println("YES");
		}
		else System.out.println("NO");
		
	}
}