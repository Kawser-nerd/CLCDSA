import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String X = scanner.next();
		String s = scanner.next();
		char x = X.charAt(0);
		for(int i = 0; i < s.length(); i++){
			if(s.charAt(i) != x){
				System.out.print(s.charAt(i));
			}
		}
		System.out.println();
 	}
}