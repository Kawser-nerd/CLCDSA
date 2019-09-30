import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		String a="1";

		for(int i=0; i<N-1; i++) {
			a=a+"0";
		}
		a=a+"7";
		System.out.println(a);
	}
}