import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		System.out.println(str.replace("a", "").length() == 2
			&& str.replace("b", "").length() == 2
			&& str.replace("c", "").length() == 2
			? "Yes" : "No");
	}
}