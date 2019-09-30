import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String st = String.valueOf(sc.nextLong() + 1);
		System.out.println((st.length() - 1) * 9 + st.charAt(0) - '1');
	}
}