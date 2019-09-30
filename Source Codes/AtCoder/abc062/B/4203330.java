import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	int b=scan.nextInt();
	String an[]=new String[a];
	for(int i=0;i!=a;i++) {
		an[i]=scan.next();
	}
	for(int i=0;i!=b+2;i++) {
		System.out.print("#");
	}
	System.out.println();
	for(int i=0;i!=a;i++) {
		System.out.println("#"+an[i]+"#");
	}
	for(int i=0;i!=b+2;i++) {
		System.out.print("#");
	}
	System.out.println();
	
}
}