import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		if (a == b && b == c && a % 2 == 0) {
			System.out.println(-1);
		} else {
			int count = 0;
			while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
				int ta = a;
				int tb = b;
				int tc = c;
				a = (tb + tc) / 2;
				b = (ta + tc) / 2;
				c = (ta + tb) / 2;
				count++;
			}
			System.out.println(count);
		}
 	}
}