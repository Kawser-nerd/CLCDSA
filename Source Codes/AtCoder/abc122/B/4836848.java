import java.util.*;
 
public class Main {
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		char s;
		int cnt=0, ans=0;
		for (int i = 0; i < S.length(); i++) {
			s = S.charAt(i);
			if (s == 'A'||s=='T'||s=='G'||s=='C')
				cnt++;
			else {
				ans = Math.max(cnt, ans);
				cnt = 0;
			}
		}
		ans = Math.max(cnt, ans);
		System.out.println(ans);
	}
}