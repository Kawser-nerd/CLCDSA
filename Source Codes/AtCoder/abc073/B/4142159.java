import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int a=scan.nextInt();
		int count=0;
		for(int i=0;i!=a;i++) {
			int b=scan.nextInt();
			int c=scan.nextInt();
			count+=c-b+1;
		}
		System.out.println(count);
		}
}