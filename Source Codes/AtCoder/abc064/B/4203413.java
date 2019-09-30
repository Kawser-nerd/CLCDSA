import java.util.Arrays;
import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	int b[]=new int[a];
	for(int i=0;i!=a;i++) {
		b[i]=scan.nextInt();
	}
	Arrays.sort(b);
	System.out.println(b[a-1]-b[0]);
}
}