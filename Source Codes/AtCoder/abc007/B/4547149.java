import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		char[] c = new char[s.length()];
		for(int i=0;i<s.length();i++) {
			c[i]=s.charAt(i);
		}
		if(s.length()<2&&c[0]=='a') {
			System.out.println(-1);
		}else {
			System.out.println('a');
		}
	}
}