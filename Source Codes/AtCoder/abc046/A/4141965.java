import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int a=scan.nextInt();
		int b=scan.nextInt();
		int c=scan.nextInt();
		int count=3;
		if(a==b){count--;
			 }if(b==c){count--;
			 }if(a==c){count--;
			 }
		 if(count==0) {
			 count++;
		 }
		System.out.println(count);
	}
}