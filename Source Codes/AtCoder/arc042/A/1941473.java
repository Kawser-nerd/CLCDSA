import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		boolean[] a = new boolean[n];
		Deque<Integer> d = new ArrayDeque<>();
		for(int i = 0 ; i < m ; i++) {
			int b = sc.nextInt();
			d.push(b);
		}
		while(!d.isEmpty()) {
			int c = d.poll();
			if(!a[c - 1]) {
				a[c - 1] = true;
				System.out.println(c);
			}
		}
		for(int i = 0 ; i < n ; i++) {
			if(!a[i]) System.out.println(i + 1);
		}
	}
}