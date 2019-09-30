import java.util.Scanner;
public class Main {
	public static void main(String[] args) throws Exception{
		Scanner scan=new Scanner(System.in);
		int a=scan.nextInt();
		int b=scan.nextInt();
		int c=scan.nextInt();
		int fig=0;
		for(int i=1;i!=b+1;i++) {
			if((b*i+c)%a==0) {
				fig=1;
			}
		}
		System.out.println(fig==1?"YES":"NO");
	}
}