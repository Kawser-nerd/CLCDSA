import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		int cnt = 0;
		for(int i = 0; i < str.length() - 1; i++) {
			//System.out.println(str.substring(i, i + 1));
			//System.out.println(str.substring(i + 1, i + 2));
			if(str.substring(i, i + 1).equals(str.substring(i + 1, i + 2))) {
				cnt++;
				if(cnt >= 2) {
					System.out.println("Yes");
					return;
				}
			} else {
				cnt = 0;
			}
		}
		System.out.println("No");
	}
}