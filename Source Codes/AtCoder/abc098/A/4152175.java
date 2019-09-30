//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {

//		int n = sc.nextInt();
//		int m = sc.nextInt();

//		int a = sc.nextInt();
//		int b = sc.nextInt();

//		int x = sc.nextInt();
		int a = sc.nextInt(); int b = sc.nextInt();
//		int a = sc.nextInt(); int b = sc.nextInt(); int c = sc.nextInt();
//		int a = sc.nextInt(); int b = sc.nextInt(); int c = sc.nextInt(); int d = sc.nextInt();
		
		
		System.out.println(max(a+b,a-b,a*b));
	}
	
	public static int max(int... ar) {
		Arrays.sort(ar);
		return ar[ar.length-1];
	}
	public static int min(int... ar) {
		Arrays.sort(ar);
		return ar[0];
	}
	
}