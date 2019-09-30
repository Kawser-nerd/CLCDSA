import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

public class ProblemA {

	public static void solve(Scanner sc) {
		String s = sc.next();
		int[] arr = new int[26];
		for (char c : s.toCharArray()) {
			arr[c - 'A']++;
		}
		String[] strings = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE",
				"SIX", "SEVEN", "EIGHT", "NINE" };
		int[][] count = new int[10][26];
		for (int i = 0; i < strings.length; i++) {
			for (char c : strings[i].toCharArray()) {
				count[i][c - 'A']++;
			}
		}
		int[] todo = new int[10];
		todo[0] = arr[25];
		todo[2] = arr[22];
		todo[4] = arr['U' - 'A'];
		todo[6] = arr['X' - 'A'];
		todo[8] = arr['G' - 'A'];

		for (int j = 0; j < 26; j++) {
			arr[j] -= todo[0] * count[0][j];
			arr[j] -= todo[2] * count[2][j];
			arr[j] -= todo[4] * count[4][j];
			arr[j] -= todo[6] * count[6][j];
			arr[j] -= todo[8] * count[8][j];
		}
		todo[1] = arr['O' - 'A'];
		todo[3] = arr['R' - 'A'];
		todo[7] = arr['S' - 'A'];
		for (int j = 0; j < 26; j++) {
			arr[j] -= todo[1] * count[1][j];
			arr[j] -= todo[3] * count[3][j];
			arr[j] -= todo[7] * count[7][j];
		}
		todo[5] = arr['V' - 'A'];
		todo[9] = arr['N' - 'A'] / 2;
		for (int j = 0; j < 26; j++) {
			arr[j] -= todo[5] * count[5][j];
			arr[j] -= todo[9] * count[9][j];
			if (arr[j] != 0) {
				System.out.println("err");
			}
		}

		String sol = "";
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < todo[i]; j++)
				sol += i;
		}
		System.out.println(sol);
	}

	public static void main(String[] args) throws FileNotFoundException {
		// Scanner sc = new Scanner(new File("A-practice.in"));
//		Scanner sc = new Scanner(new File("A-small-attempt1.in"));
		 Scanner sc = new Scanner(new File("A-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			solve(sc);
		}
		sc.close();
	}
}
