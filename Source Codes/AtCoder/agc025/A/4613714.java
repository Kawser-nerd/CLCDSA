import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String st = sc.next();
		long ans = 0;
		for(int i = 0; i < st.length(); i ++) {
			ans += st.charAt(i) - '0';
		}
		System.out.println(ans == 1 ? 10 : ans);
	}
}