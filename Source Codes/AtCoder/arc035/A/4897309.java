import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		String s=sc.next();
		int l=s.length();
		for(int i=0;i<l/2;i++) {
			if(!(s.charAt(i)==s.charAt(l-i-1)||s.charAt(i)=='*'||s.charAt(l-i-1)=='*')) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}
}