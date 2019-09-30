import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		int n=s.nextInt(),m=s.nextInt(),a=s.nextInt(),b=s.nextInt();
		for(int d=0;d<m;d++) {
			if(n<=a)
				n+=b;
			n-=s.nextInt();
			if(n<0) {
				System.out.println(d+1);
				return;
			}
		}
		System.out.println("complete");
	}
}