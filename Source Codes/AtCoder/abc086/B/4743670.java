import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		String b = sc.next();
		int c = Integer.parseInt(a+b);
		boolean heihoukon = false;
		for(int i = 0;i<317;i++) {
			if(i*i == c) {
				heihoukon = true;
			}
		}
		if(heihoukon == true) {
			System.out.println("Yes");
		}else if(heihoukon == false) {
			System.out.println("No");
		}

	}
}