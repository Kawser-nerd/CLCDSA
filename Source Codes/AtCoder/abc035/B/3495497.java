import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		int T = sc.nextInt();
		sc.close();

		int v = 0, h = 0, unk = 0;
		for(int i = 0;i < S.length();++i) {
			switch(S.charAt(i)) {
			case 'L':
				--h;
				break;
			case 'R':
				++h;
				break;
			case 'U':
				++v;
				break;
			case 'D':
				--v;
				break;
			case '?':
				++unk;
				break;
			}
		}
		
		int ans = Math.abs(v) + Math.abs(h);
		if(T == 1) {
			System.out.println(ans + unk);
		} else {
			if(ans < unk)
				ans = (unk - ans) % 2;
			else
				ans = ans - unk;
			System.out.println(ans);
		}
	}
}