import java.util.Scanner;

public class Main{
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
	int n=sc.nextInt();
	int min=n;
	for(int i=1;i<=Math.sqrt(n);i++) {
		int b=Math.abs((n/i)-i)+n%i;
		min=Math.min(min, b);
	}
	System.out.println(min);
	}
}