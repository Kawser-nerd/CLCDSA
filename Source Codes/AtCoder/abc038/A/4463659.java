import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String drink = sc.next();
		
		String lst = drink.substring(drink.length()-1);

		if(lst.equals("T")) {
			System.out.println("YES");
		}else {
			System.out.println("NO");
		}
	}
}