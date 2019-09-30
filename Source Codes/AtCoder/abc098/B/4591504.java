import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int K = reader.nextInt();
		String S = reader.next();
		int ans = 0;
		for (int i = 1; i < K; i++) {
			int tmp = 0;
			String bf = S.substring(0, i);
			String af = S.substring(i, S.length());
			while (bf.length() > 0) {
				if (af.indexOf(bf.charAt(0)) != -1) {
					tmp++;
				}
				bf = bf.replaceAll(Character.toString(bf.charAt(0)), "");
			}
			if (tmp > ans) {
				ans = tmp;
			}
		}

		reader.close();
		System.out.print(ans);
	}
}