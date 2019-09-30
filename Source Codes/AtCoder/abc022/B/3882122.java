import java.util.Arrays;
import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt();
		int b[]=new int [a];
		int ans=0;
		for(int i=0;i!=a;i++) {
			b[i]=scan.nextInt();
		}
		Arrays.sort(b);
		for(int i=1;i!=a;i++) {
			if(b[i]==b[i-1]) {ans++;}
		}
		System.out.println(ans);
}
}