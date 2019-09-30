import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String S = sc.next();
		sc.close();
		int cnt = 0;
		String ans = S;
		for(int i = 0; i < N; i++) {
			if(S.charAt(i) == '(') {
				cnt++;
			}else {
				cnt--;
			}
			if(cnt < 0) {
				ans = "(" + ans;
				cnt++;
			}
		}
		for(int i = 0; i < cnt; i++) {
			ans = ans + ")";
		}
		System.out.println(ans);
	}
}