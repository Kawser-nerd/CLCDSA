import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {

		long a = sc.nextLong(); long b = sc.nextLong(); long c = sc.nextLong();
		if (a%2==0 || b%2==0 || c%2==0) {
			System.out.println(0);
		}
		else {
			System.out.println(min(a*b, b*c, c*a));
		}

	}

	public static long max(long... ar) {Arrays.sort(ar);return ar[ar.length-1];}
	public static long min(long... ar) {Arrays.sort(ar);return ar[0];}

}