import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int a=sc.nextInt(); int b = sc.nextInt(); int c = sc.nextInt(); int d = sc.nextInt();
		int x = c-a; int y = d-b;
		System.out.println((c-y)+" "+(d+x)+" "+(a-y)+" "+(b+x));
		
	}
}