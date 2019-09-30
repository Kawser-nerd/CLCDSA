import java.util.Scanner;

public class Main {
	static String original;
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		String S = reader.next();
		boolean flag = true;
		String ans;

		if (S.charAt(0) != 'A') {
			flag = false;
		}

		int C_index = S.indexOf('C');
		if (S.indexOf('C') > S.length() - 2 || S.indexOf('C') < 2) {
			flag = false;
		}

		for (int i = 1; i < S.length(); i++) {
			if (i != C_index && Character.isUpperCase(S.charAt(i))) {
				flag = false;
			}
		}
		
		if (flag) {
			ans = "AC";
		} else {
			ans = "WA";
		}

		System.out.print(ans);
	}


}