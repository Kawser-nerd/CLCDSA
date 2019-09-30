//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int a = sc.nextInt(); int b = sc.nextInt(); 
		if (a == 1) a = 14;
		if (b == 1) b = 14;
		
		
		if (a == b) System.out.println("Draw");
		else System.out.println(a>b?"Alice":"Bob");
		
	}
}