//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int x = sc.nextInt(); int a = sc.nextInt(); int b = sc.nextInt();
		
		if (a >= b) System.out.println("delicious");
		else if (b-a <= x) {
			System.out.println("safe");
		}
		else System.out.println("dangerous");
	}
}