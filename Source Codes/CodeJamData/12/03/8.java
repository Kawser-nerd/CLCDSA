import java.util.Scanner;

public class RecycledSmall {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int cases = scan.nextInt();
		for (int trial = 1; trial <= cases; trial++) {
			System.out.print("Case #" + trial + ": ");
			int a = scan.nextInt();
			int b = scan.nextInt();
			int rots = 0;
			for (int v = a; v < b; v++) {
				rots += countRotations(v, b);
			}
			System.out.println(rots);
		}
	}

	private static int countRotations(int v, int b) {
		String vString = Integer.toString(v);
		String nextString = vString;
		int count = 0;
		while (true) {
			nextString = rotate(nextString);
			if (nextString.equals(vString))
				break;
			int newV = Integer.parseInt(nextString);
			if (newV > v && newV <= b)
				count++;
		}
		return count;
	}

	private static String rotate(String nextString) {
		return nextString.substring(1) + nextString.charAt(0);
	}
}
