import java.util.*;
public class Main {
	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);

		String number = sc.next();

		String start = number.substring(0, 1);
		String end = number.substring(2, 3);

		if (start.equals(end)) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}