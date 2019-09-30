import java.util.*;
public class Main {
	public static void main(String[] args) {
		A();
	}
	
	public static void A() {
		Scanner sc = new Scanner(System.in);
		String s1 = sc.next();
		String s2 = sc.next();
		for(int i=0;i<3;i++) {
			if(s1.charAt(i)!=s2.charAt(2-i)) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}
	
}