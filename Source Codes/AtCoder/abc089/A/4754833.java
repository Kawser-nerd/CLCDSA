import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int a = Integer.parseInt(sc.next());
		a-=a%3;
		System.out.println(a/3);

	}
}