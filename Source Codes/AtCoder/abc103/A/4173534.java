//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
//		int n = sc.nextInt();
//		String s = sc.next();
		
//		int a = sc.nextInt(); int b = sc.nextInt();
//		int a = sc.nextInt(); int b = sc.nextInt(); int c = sc.nextInt();
		
		int[] ar = new int[3];
		for (int i=0; i<3; i++) ar[i] = sc.nextInt();
		Arrays.sort(ar);
		
		System.out.println((ar[2]-ar[1])+(ar[1]-ar[0]));

	}
}