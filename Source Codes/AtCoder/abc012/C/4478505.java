import java.util.Scanner;
public class Main {
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
	int n=sc.nextInt();
	int distans=2025-n;
	for(int i=1;i<=9;i++) {
		for(int j=1;j<=9;j++) {
			if(i*j==distans)System.out.println(i+" x "+j);
		}
	}
	}
}