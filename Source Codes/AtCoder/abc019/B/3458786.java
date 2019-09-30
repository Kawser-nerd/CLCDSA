import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		sc.close();
		
		StringBuilder ans = new StringBuilder();
		char c = str.charAt(0);
		int num = 1;
		for(int i = 1;i < str.length();++i) {
			if(str.charAt(i) != c) {
				ans.append(c);
				ans.append(num);
				num = 1;
				c = str.charAt(i);
			} else {
				num++;
			}
		}
		ans.append(c);
		ans.append(num);
		System.out.println(ans.toString());
	}
}