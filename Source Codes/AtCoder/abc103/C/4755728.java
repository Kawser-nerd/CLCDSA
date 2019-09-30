import java.util.Scanner;
class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int a=0;
		for(int i=0;i<n;i++) {
			a+=sc.nextInt()-1;
		}
		System.out.println(a);
	}
}