import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int c = sc.nextInt();
		int k = sc.nextInt();
		int[] t = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = sc.nextInt();
		}
		Arrays.sort(t);
		int count = 0;
		int i = 1;
		int ft = t[0];
		int pc = 1;
		while (i < n) {
			if (t[i] <= ft + k && pc < c) {
				pc++;
			} else {
				count++;
				ft = t[i];
				pc = 1;
			}
			i++;
		}
		count++;
		System.out.println(count);
 	}
}