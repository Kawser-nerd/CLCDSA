import java.util.Arrays;
import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	int b=scan.nextInt();
	int c[]=new int[a];
	for(int i=0;i!=a;i++) {
		c[i]=scan.nextInt();
	}
	Arrays.sort(c);
	int ans=0;
	for(int i=c.length-1,n=0;n!=b;i--,n++) {
		ans+=c[i];
	}
	System.out.println(ans);
}
}