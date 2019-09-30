import java.util.*;

public class A {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int C = in.nextInt();
		for (int thisCase = 1; thisCase <= C; thisCase++) {
			String input = in.next();
			System.out.printf("Case #%d: %s%n", thisCase, getLastWord(input));
		}
	}

	private static String getLastWord(String str) {
		if (str.length() == 1) {
			return str;
		}
		else if (str.length() == 0) {
			return "";
		}

		int indexOfLargestLetter = 0;
		char[] arr = str.toCharArray();
		for (int i = 1; i < arr.length; i++) {
			if (arr[i] >= arr[indexOfLargestLetter]) {
				indexOfLargestLetter = i;
			}
		}

		String stuffBefore = getLastWord(str.substring(0,indexOfLargestLetter));
		String stuffAfter = str.substring(indexOfLargestLetter+1);


		return arr[indexOfLargestLetter] + stuffBefore + stuffAfter;

	}
}