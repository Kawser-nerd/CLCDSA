import java.util.*;
public class Main {
	
	public static void main(String... args) {
		Scanner sc = new Scanner(System.in);
		
		String S = sc.nextLine();
		int index = S.indexOf("WWBWBWW");
		
		String[] map = {"Si", "Do", "#", "Re", "#", "Mi", "Fa", "#", "So", "#", "La", "#", "Si"};
		System.out.println(map[12 - index]);
	}
}