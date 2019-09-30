import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String N = sc.next();
		for(int i = 0; i < N.length(); i++) {
			if(N.substring(i, i + 1).equals("9")){
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");
	}
}