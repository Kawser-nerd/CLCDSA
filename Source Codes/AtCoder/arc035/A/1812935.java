import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] s = sc.next().toCharArray();
		int n = s.length;
		char[] s1 = new char[n];
		for(int i = 0 ; i < n ; i++) {
			s1[i] = s[n - 1 - i];
		}
		boolean ok = true;
		for(int i = 0 ; i < n ; i++) {
			if(s[i] == s1[i] || s[i] == '*' || s1[i] == '*');
			else ok = false;
		}
		System.out.println(ok == true ? "YES" : "NO");
	}
}