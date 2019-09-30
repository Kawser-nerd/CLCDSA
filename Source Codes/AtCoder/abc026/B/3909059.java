import java.util.Arrays;
import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt();
		double ans=3.1415926535897932384626433832795028841971693993751058209;
		double ans2=0;
		int c[]=new int[a];
		for(int i=0;i!=a;i++) {
			c[i]=scan.nextInt();
		}
		Arrays.sort(c);
		for(int i=0;i!=a;i++) {
			if(i%2==0) {
				ans2+=c[i]*c[i];
			}
			else {
				ans2-=c[i]*c[i];
			}
		}
		ans*=ans2;
		if(ans<=0) {
			System.out.println(ans*-1);
		}
		else if(ans>0) {
			System.out.println(ans);
		}
		
	}
}