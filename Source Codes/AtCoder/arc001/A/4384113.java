import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = sc.next();
		int[] count = new int[5];
		for (int i = 0; i < n; i++) {
			count[Integer.parseInt(String.valueOf(s.charAt(i)))]++;
		}
		int max = Math.max(count[1], Math.max(count[2], Math.max(count[3], count[4])));
		int min = Math.min(count[1], Math.min(count[2], Math.min(count[3], count[4])));
		System.out.println(max + " " + min);
	}
}