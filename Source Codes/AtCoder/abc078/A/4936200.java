import java.util.*;
public class Main {
	public static void main(String[] args) {
		A();
	}
	
	public static void A() {
		Scanner sc = new Scanner(System.in);
		String s1 = sc.next();
		String s2 = sc.next();
		if(s1.compareTo(s2) < 0) System.out.println("<");
		else if(s1.compareTo(s2) == 0) System.out.println("=");
		else System.out.println(">");
	}
}