import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();
		int b = sc.nextInt();
		int length = a+b+1;
		String post = sc.next();
		char c = post.charAt(a);
		String start = post.substring(0,a);
		String end = post.substring(a+1,post.length());

		String ans = "";
		if(post.length() == length) {
			if(c == '-') {
				if(start.contains("-") || end.contains("-")) {
					ans = "No";
				}else {
				ans = "Yes";
				}
			}else {
				ans = "No";
			}
		}else {
			ans = "No";
		}
		System.out.println(ans);

	}
}