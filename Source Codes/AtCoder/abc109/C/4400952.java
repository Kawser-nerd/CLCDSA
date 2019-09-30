import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		int k = sc.nextInt();
		int gcd = Math.abs(k - sc.nextInt());
		for (int i=1; i<n; i++) {
			gcd = gcd(gcd, Math.abs(k - sc.nextInt()));
		}
		System.out.println(gcd);
		
	}

	static int gcd (int a, int b) {return b>0?gcd(b,a%b):a;}
	static int lcm (int a, int b) {return a*b/gcd(a,b);}

}