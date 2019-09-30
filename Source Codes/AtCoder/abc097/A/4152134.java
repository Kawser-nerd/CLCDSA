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
//		int a = sc.nextInt(); int b = sc.nextInt();
//		int a = sc.nextInt(); int b = sc.nextInt(); int c = sc.nextInt();
		int a = sc.nextInt(); int b = sc.nextInt(); int c = sc.nextInt(); int d = sc.nextInt();
		
		
		System.out.println(Math.abs(a-b)<=d&&Math.abs(b-c)<=d||Math.abs(a-c)<=d?"Yes":"No");
	}
}