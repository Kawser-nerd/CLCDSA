import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		String b = sc.next();
		String c = sc.next();
		System.out.print((char) (a.charAt(0) - 0x20));
		System.out.print((char) (b.charAt(0) - 0x20));
		System.out.print((char) (c.charAt(0) - 0x20));
	}
}