import java.util.Arrays;
import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	long c[]=new long[a+1];
	long count=0;
	for(int i=1;i!=a+1;i++) {
		int b=scan.nextInt();
		count+=b;
		c[i]=count;
	}
	Arrays.sort(c);
	long co=0;
	for(int i=0;i!=a+1;i++) {
	}
	count=0;
	for(int i=0;i!=a;i++) {
		co++;
		if(c[i]!=c[i+1]) {
			count+=co*(co-1)/2;
			co=0;
		}
	}
	count+=(co+1)*(co)/2;
	System.out.println(count);
	}
}