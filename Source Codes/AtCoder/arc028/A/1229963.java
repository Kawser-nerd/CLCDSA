import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		int n=s.nextInt(),take[]= {s.nextInt(),s.nextInt()};
		for(int i=0;n>0;i++) {
			n-=take[i%2];
			if(n<=0) {
				System.out.println(i%2==0?"Ant":"Bug");
				return;
			}
		}
	}
}