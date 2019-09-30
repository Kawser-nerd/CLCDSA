import java.util.Scanner;

public class Main{
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		double a=sc.nextInt();
		for(int i=0;i<2;i++)a=Math.sqrt(a);
		System.out.println((int)a);
	}
}