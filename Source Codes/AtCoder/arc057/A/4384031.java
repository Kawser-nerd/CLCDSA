import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long k = sc.nextLong();
		long count = 0;
		if (k != 0) {
			while (a < 2000000000000L) {
				a += 1 + k * a;
				count++;
			}
		} else {
			count = 2000000000000L - a;
		}
		System.out.println(count);
	}
}