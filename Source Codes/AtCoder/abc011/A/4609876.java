import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int month = sc.nextInt();
		if (month == 12) {
			System.out.println("1");
		}else{
			System.out.println(month + 1);
		}
	}
}