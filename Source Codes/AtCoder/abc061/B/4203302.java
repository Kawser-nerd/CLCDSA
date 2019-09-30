import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	int b=scan.nextInt();
	int an[]=new int[a];
	for(int i=0;i!=b;i++) {
		int c=scan.nextInt();
		int d=scan.nextInt();
		an[c-1]++;
		an[d-1]++;
	}
	for(int i=0;i!=a;i++) {
		System.out.println(an[i]);
	}
}
}