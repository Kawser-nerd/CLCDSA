import java.util.Scanner;
import java.util.Stack;

public class Main {
	private static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int n = sc.nextInt();
		int l = sc.nextInt();
		String s = sc.next();
		Stack<Integer> st = new Stack<>();
		st.push(0);
		int ret = 0;
		for (int i = 0;i < s.length();i++) {
			char c = s.charAt(i);
			if (c=='+') {
				st.push(0);
				if (st.size()>l) {
					st.clear();
					st.push(0);
					ret++;
				}
			} else {
				st.pop();
			}
		}

		System.out.println(ret);
	}
}