import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		if(a<0 && b>0) {
			System.out.println((Math.abs(a)+b-1));
		}
		else if(a<0 && b<0) {
			System.out.println((Math.abs(a-b)));
		}
		else if(a>0 && b>0) {
			System.out.println(((b-a)));
		}
	}
}