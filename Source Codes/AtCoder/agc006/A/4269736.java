import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		String L = sc.next();
		String R = sc.next();
		for (int i=0; i<n; i++) {
			//L?????n-i???R????n-i??
			if (L.substring(i,L.length()).equals(R.substring(0,n-i))) {
				System.out.println(n+i); return;
			}
		}
		
		System.out.println(2*n);
		
	}
}