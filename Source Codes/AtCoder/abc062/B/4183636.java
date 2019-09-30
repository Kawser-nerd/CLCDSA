//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		int h = sc.nextInt(); int w = sc.nextInt();
		String[] ar = new String[h];
		for (int i=0; i<h; i++) {
			ar[i] = "#"+sc.next()+"#";
		}
		
		for (int i=0; i<w+2; i++) {
			System.out.print("#");
		}
		System.out.println();
		
		for (int i=0; i<h; i++) {
			System.out.println(ar[i]);
		}
		
		for (int i=0; i<w+2; i++) {
			System.out.print("#");
		}
		System.out.println();
		
		
	}
}