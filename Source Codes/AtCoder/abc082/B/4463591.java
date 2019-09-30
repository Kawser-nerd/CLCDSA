import java.util.Arrays;
import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		char[] s = sc.next().toCharArray(), t = sc.next().toCharArray();
		Arrays.sort(s);
		Arrays.sort(t);
		ArrayUtils.reverse(t);
		int compared = String.valueOf(s).compareTo(String.valueOf(t));
		System.out.println(compared < 0 ? "Yes" : "No");
	}

	static class ArrayUtils {
		static void reverse(char[] array) {
			for (int i = 0; i < array.length / 2; i++) {
				char tmp = array[i];
				array[i] = array[array.length - i - 1];
				array[array.length - i - 1] = tmp;
			}
		}
	}
}