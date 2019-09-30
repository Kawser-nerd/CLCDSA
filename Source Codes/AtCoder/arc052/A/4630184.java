import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		for (int i = 99; i > 0; i--) {
			if (s.contains(String.valueOf(i))) {
				System.out.println(i);
				break;
			}
		}
	}
}