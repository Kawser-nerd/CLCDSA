import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), l = in.nextInt();
		char[][] s = new char[l+1][2*n-1];
		in.nextLine().toCharArray();
		for (int i = 0; i < l+1; i++) {
			s[i] = in.nextLine().toCharArray();
		}

		int now = -1;
		for (int i = 0; i < 2*n-1; i++) {
			if (s[l][i] == 'o') {
				now = i;
				break;
			}
		}

		for (int i = l-1; i >= 0; i--) {
			if (now < 0 || now >= 2*n-1) continue;
			if (1 <= now && s[i][now-1] == '-') {
				now -= 2;
				continue;
			}
			if (now < 2*n-2 && s[i][now+1] == '-') {
				now += 2;
				continue;
			}
		}

		System.out.println((now+2)/2);
		in.close();
	}

}