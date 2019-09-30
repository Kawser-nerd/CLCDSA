import java.util.Arrays;
import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner s=new Scanner(System.in);
	int a=s.nextInt();
	int x=s.nextInt();
	long c[]=new long[a];
	long count=0;
	int ans=0;
	long sum=0;
	for(int i=0;i!=a;i++) {
		int b=s.nextInt();
		c[i]=b;
		sum+=c[i];
	}
	Arrays.sort(c);
	for(int i=0;i<a;i++) {
		count+=c[i];
		if(count>x) {
			break;
		}
		ans++;
	}
	System.out.println(sum<x?ans-1:ans);
	}
}