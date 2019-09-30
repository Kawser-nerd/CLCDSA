import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	long c[]=new long[a];
	long count=0;
	for(int i=0;i!=a;i++) {
		int b=scan.nextInt();
		c[i]=b;
	}
	for(int i=0;i<a-1;i++) {
		if(c[i]==c[i+1]) {
			count++;
			i++;
		}
	}
	System.out.println(count);
	}
}