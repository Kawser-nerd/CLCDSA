import java.util.*;

class FreeCell {
	public static void main(String[] arg) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		for(int ctc = 1; ctc <= tc; ++ctc) {
			System.out.printf("Case #%d: ", ctc);
			boolean good = true;
			long n = sc.nextLong();
			int pd = sc.nextInt();
			int pg = sc.nextInt();
			if(100 / gcd(100, pd) > n) good = false;
			else {
				if(pg == 100 && pd != 100) good = false;
				if(pg == 0 && pd != 0) good = false;
			}
			System.out.println(good ? "Possible" : "Broken");
		}
	}

	static long gcd(long a, long b) {
		while(b != 0) {
			long t = b;
			b = a % b;
			a = t;
		}
		return a;
	}
}
