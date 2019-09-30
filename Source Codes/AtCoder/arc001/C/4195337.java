import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int x = Math.abs(a - b);
		int count = 0;
		while (x >= 8) {
			x = Math.abs(x -10);
			count++;
		}
		while (x >= 4) {
			x = Math.abs(x - 5);
			count++;
		}
		count += x;
		System.out.println(count);
	}
}