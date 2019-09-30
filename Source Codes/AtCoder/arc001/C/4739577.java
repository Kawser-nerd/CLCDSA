import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int count = 0;
		while (a != b) {
			if (b < a) {
				int tmp = a;
				a = b;
				b = tmp;
			}
			if (b - a >= 8) {
				a += 10;
				count++;
			} else if (b - a >= 3) {
				a += 5;
				count++;
			} else {
				a += 1;
				count++;
			}
		}
		System.out.println(count);
	}
}