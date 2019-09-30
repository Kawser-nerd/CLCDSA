import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), len, i, j = 0, k;
		sc.close();
		String tmp;
		for (i = 1; j < N; ++i) {
			tmp = Integer.toString(i);
			len = tmp.length();
			for (k = 1; k < len; ++k) {
				if (tmp.charAt(k - 1) != tmp.charAt(k)) break;
			}
			if (k == len) ++j;
		}
		System.out.println(i - 1);
	}
}