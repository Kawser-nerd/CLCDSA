import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int t = sc.nextInt();
		int[] type = new int[5];
		for (int i = 0; i < s.length(); i++) {
			switch (s.charAt(i)) {
				case 'L' :
				type[0]++;
				break;
				case 'R' :
				type[1]++;
				break;
				case 'U' :
				type[2]++;
				break;
				case 'D' :
				type[3]++;
				break;
				case '?' :
				type[4]++;
				break;
			}
		}
		int d = Math.abs(type[0] - type[1]) + Math.abs(type[2] - type[3]);
		if (t == 1) {
			System.out.println(d + type[4]);
		} else {
			if (d >= type[4]) {
				System.out.println(d - type[4]);
			} else {
				System.out.println((type[4] - d) % 2);
			}
		}
	}
}