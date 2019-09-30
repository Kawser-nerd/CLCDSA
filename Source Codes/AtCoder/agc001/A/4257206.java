import java.util.Arrays;
import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	int b[]=new int[a*2];
	for(int i=0;i<a*2;i++) {
		b[i]=scan.nextInt();
	}
	Arrays.sort(b);
	int count=0;
	for(int i=0;i<a*2;i+=2) {
		count+=b[i];
	}
	System.out.println(count);
	scan.close();
	}
}