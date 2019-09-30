import java.util.Scanner;
 
class Main {
	static long gcd(long a,long b) {
		if(b == 0)
			return a;
		return gcd(b,a % b);
	}
 
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String in = scan.next();
		String[] in2 = in.split("/");
		long x = Long.parseLong(in2[0]);
		long y = Long.parseLong(in2[1]);
		long g = gcd(x,y);
		x /= g;y /= g;
		scan.close();
		long s = (2 * x - y) / y + 1;
		s = (s + y - 1) / y * y;
		long n = Math.max(s, y);
		boolean f = true;
		while(n * y + y - 2 * x <= 2 * y) {
            long m = n * (n + 1) / 2 - n / y * x; 
			System.out.println(n + " " + m);
			f = false;
			n += y;
		}
		if(f)
			System.out.println("Impossible");
	}
}