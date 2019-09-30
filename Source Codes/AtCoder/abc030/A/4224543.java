import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = (long) (10000.0 / sc.nextLong() * sc.nextLong());
		long b = (long) (10000.0 / sc.nextLong() * sc.nextLong());
		System.out.println(a > b ? "TAKAHASHI" : a < b ? "AOKI" : "DRAW");
	}
}