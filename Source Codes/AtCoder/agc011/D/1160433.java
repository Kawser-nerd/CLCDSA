import java.util.*;

public class Main {
	
	static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		int k = sc.nextInt();
		String s = sc.next();
		char[] ss = s.toCharArray();
		boolean[] a = new boolean[n];
		
		for (int i = 0; i < n; i++) {
			if(ss[i] == 'A') {
				a[i] = true;
			}
		}
		
		boolean flip = false;
		int index = 0;
		for (int i = 0; i < Math.min(k,  2 * n + k % 2); i++) {
			if(a[index] ^ flip) {
				a[index] = !a[index];
			} else {
				flip = !flip;
				index = (index + 1) % n;
			}
		}
		for (int i = 0; i < n ; i++) {
			if(a[(index+i) % n] ^ flip) {
				System.out.print('A');
			} else {
				System.out.print('B');
			}
		}

	}
}