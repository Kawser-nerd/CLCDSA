import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		long r = sc.nextLong();
		long b = sc.nextLong();
		long x = sc.nextLong();
		long y = sc.nextLong();
		long Tmax = r + b + 1000L;
		long Tmin = 0L;
		long T = 0;
		while(Tmax - Tmin > 1) {
			T = Tmin + (Tmax-Tmin)/2;
			//T????????
			if(r >= T && b >= T && (r - T)/(x - 1) + (b - T)/(y - 1) >= T) {
				Tmin = T;
			} else {
				Tmax = T;
			}
		}
		long ans = Tmin;
		System.out.println(ans);
	}
}