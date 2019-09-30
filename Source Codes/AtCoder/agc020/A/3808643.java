import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int A=sc.nextInt();
		int B=sc.nextInt();
		if(Math.abs(A-B)%2==0) {
			System.out.println("Alice");
		}
		else if(Math.abs(A-B)%2==1) {
			System.out.println("Borys");
		}
	}
}