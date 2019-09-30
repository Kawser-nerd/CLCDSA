import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String sub = s.substring(0, 11);
		if (sub.equals("WBWBWWBWBWB")) {
			System.out.println("Do");
		} else if (sub.equals("WBWWBWBWBWW")) {
			System.out.println("Re");
		} else if (sub.equals("WWBWBWBWWBW")) {
			System.out.println("Mi");
		} else if (sub.equals("WBWBWBWWBWB")) {
			System.out.println("Fa");
		} else if (sub.equals("WBWBWWBWBWW")) {
			System.out.println("So");
		} else if (sub.equals("WBWWBWBWWBW")) {
			System.out.println("La");
		} else {
			System.out.println("Si");
		}
	}
}