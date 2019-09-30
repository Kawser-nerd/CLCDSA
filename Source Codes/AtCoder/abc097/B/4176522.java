import java.util.Scanner;
public class Main {
	public static void main(String[] args) throws Exception{
		Scanner scan=new Scanner(System.in);
		int a=scan.nextInt();
		int ans=1;
		for(int i=0;i!=a+1;i++) {
			for(int j=2;j<=Math.sqrt(i);j++) {
				for(int k=j;k<=i;k*=j) {
					if(k==i) {
						ans=i;
					}
				}
			}
		}
		System.out.println(ans);
	}
}