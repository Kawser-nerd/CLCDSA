import java.util.Scanner;
public class Main {
	static int N;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a=sc.nextInt(); int b=sc.nextInt();
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			int m=sc.nextInt();
			if(m<a)System.out.println(a-m);
			if(a<=m&&m<=b)System.out.println(0);
			if(m>b)System.out.println(-1);
		}
	}
}