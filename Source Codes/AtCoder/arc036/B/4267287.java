import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int prev = sc.nextInt();
		int count = 1;
		int max = 1;
		boolean isDown = false;
		for (int i = 1; i < n; i++) {
			int h = sc.nextInt();
			if (isDown && prev < h) {
				isDown = false;
				count = 2;
			} else {
				count++;
				if (max < count) {
					max = count;
				}
				if (prev > h) {
					isDown = true;
				}
			}
			prev = h;
		}
		System.out.println(max);
	}
}