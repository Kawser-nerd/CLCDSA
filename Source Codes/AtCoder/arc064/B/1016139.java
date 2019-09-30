import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] s = sc.next().toCharArray();
		int N = s.length;
		
		System.out.println((s[0]==s[N-1])^(N%2==0) ? "Second" : "First");
		
		sc.close();
	}
}