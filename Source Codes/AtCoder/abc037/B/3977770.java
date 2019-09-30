import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt();
		int b=scan.nextInt();
		int c[]=new int[a];
		for(int i=0;i!=a;i++) {
			c[i]=0;
		}
		for(int i=0;i!=b;i++) {
			int d=scan.nextInt();
			int e=scan.nextInt();
			int f=scan.nextInt();
			for(int j=d-1;j!=e;j++) {
				c[j]=f;
			}
		}
		for(int i=0;i!=a;i++) {
			System.out.println(c[i]);
		}
	}
}