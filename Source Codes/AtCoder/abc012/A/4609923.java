import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int tmp = 0;
		tmp = A;
		A = B;
		B = tmp;
		System.out.println(A + " " + B);
	}
}