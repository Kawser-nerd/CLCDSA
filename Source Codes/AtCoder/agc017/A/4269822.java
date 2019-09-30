import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt(); int p = sc.nextInt();
		//p=0?????????1?????
		boolean containOdd = false;
		for (int i=0; i<n; i++) {
			if (sc.nextInt()%2 != 0) containOdd = true;
		}
		
		if (containOdd == false) {
			if (p == 0) System.out.println((long)Math.pow(2,n));
			else System.out.println(0);
		}
		else {
			System.out.println((long)Math.pow(2,n-1));
		}
		
	}
}