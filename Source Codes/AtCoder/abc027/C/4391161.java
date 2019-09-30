import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long m = n;
		int depth = 0;
		while (m > 0) {
			m /= 2;
			depth++;
		}
		long x = 1;
		int teban = 1;
		if (depth % 2 != 0) {
			while (x <= n) {
				if (teban == 1) {
					x = x * 2 + 1;
				} else {
					x *= 2;
				}
				teban *= -1;
			}
		} else {
			while (x <= n) {
				if (teban == 1) {
					x *= 2;
				} else {
					x = x * 2 + 1;
				}
				teban *= -1;
			}
		}
		if (teban == 1) {
			System.out.println("Takahashi");
		} else {
			System.out.println("Aoki");
		}
	}
}