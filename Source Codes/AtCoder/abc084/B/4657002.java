import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		String [] s = sc.next().split("");
		for(int i = 0; i < a+b+1; i++) {
			if(i < a && s[i].equals("-")) {
				System.out.println("No");
				return;
			}
			if(i > a && s[i].equals("-")) {
				System.out.println("No");
				return;
			}
		}
		if(!s[a].equals("-")) {
			System.out.println("No");
		}
		else System.out.println("Yes");
		sc.close();
	}

}