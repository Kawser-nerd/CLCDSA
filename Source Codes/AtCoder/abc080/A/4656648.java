import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		int p1 = 0, p2 = 0;
		p1 = n * a;
		p2 = b;
		if(p1 < p2) {
			System.out.println(p1);
		}else{
			System.out.println(p2);
		}
	}
}