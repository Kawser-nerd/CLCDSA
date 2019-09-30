import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double l = sc.nextDouble();
		double x = sc.nextDouble();
		double y = sc.nextDouble();
		double s = sc.nextDouble();
		double d = sc.nextDouble();
		if (x >= y) {
			if (s <= d) {
				System.out.println((d - s) / (x + y));
			} else {
				System.out.println((l - (s - d)) / (x + y));
			}
		} else {
			if (s <= d) {
				System.out.println(Math.min((d - s) / (x + y), (l - (d - s)) / (y - x)));
			} else {
				System.out.println(Math.min((l - (s - d)) / (x + y), (s - d) / (y - x)));
			}
		}
 	}
}