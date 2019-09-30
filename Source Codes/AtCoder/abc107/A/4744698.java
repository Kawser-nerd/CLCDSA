import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int nagasa = sc.nextInt();
		int mae = sc.nextInt();
		int usiro = nagasa - mae +1;
		System.out.println(usiro);
	}

}