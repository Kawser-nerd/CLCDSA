import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double n = sc.nextInt();
		String s = sc.next();
		double sum = 0;
		for (int i = 0; i < s.length(); i++) {
			switch (s.charAt(i)) {
				case 'A':
					sum += 4;
					break;
				case 'B':
					sum += 3;
					break;
				case 'C':
					sum += 2;
					break;
				case 'D':
					sum += 1;
			}
		}
		System.out.println(sum / n);
	}
}