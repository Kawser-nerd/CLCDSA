import java.util.Scanner;

public class Main{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		int total=0,max=0,x;
		for(int i=0;i<3;i++) {
			x=sc.nextInt();
			total+=x;
			if(max<x) {
				max=x;
			}
		}
		System.out.println(total-max+max*(int)Math.pow(2,sc.nextInt()));
	}
}