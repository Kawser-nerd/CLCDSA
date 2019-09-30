import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int X = Integer.parseInt(sc.next(), 16);
		int Y = Integer.parseInt(sc.next(), 16);
		if(X < Y) {
			System.out.println("<");
		} else if(X > Y) {
			System.out.println(">");
		} else {
			System.out.println("=");
		}
	}
}