import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long x = sc.nextLong();
		long y = sc.nextLong();
		long count = 10000000000L;
		long tmp = y - x;
		if (tmp >= 0) {
			count = Math.min(tmp, count);
		}
		tmp = y - x * -1 + 1;
		if (tmp >= 0) {
			count = Math.min(tmp, count);
		}
		tmp = y * -1 - x + 1;
		if (tmp >= 0) {
			count = Math.min(tmp, count);
		}
		tmp = y * -1 - x * -1 + 2;
		if (tmp >= 0) {
			count = Math.min(tmp, count);
		}
		System.out.println(count);
	}
}