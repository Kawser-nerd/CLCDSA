import java.util.Scanner;
public class Main{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int limit=sc.nextInt();
		int min=1001,c,t;
		for(int i=0;i<n;i++) {
			c=sc.nextInt();
			t=sc.nextInt();
			if(t<=limit&&min>c) {
				min=c;
			}
		}
		if(min==1001) {
			System.out.println("TLE");
		}else {
			System.out.println(min);
		}
	}
}