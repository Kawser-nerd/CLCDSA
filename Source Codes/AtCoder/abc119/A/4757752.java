import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		if (s.compareTo("2019/04/30") < 1) {
			System.out.println("Heisei");
		} 
        else {
			System.out.println("TBD");
		}
	}
}