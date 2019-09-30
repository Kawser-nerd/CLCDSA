import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long s = sc.nextLong();
		long t = sc.nextLong();
		long w = 0;
		int count = 0;
		for(int i = 0; i < n; i ++) {
			w += sc.nextLong();
			if(w >= s && w <= t) {
				count ++;
			}
		}
		System.out.println(count);
	}
}