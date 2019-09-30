import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt();
		int ans=1145148101;
		for(int i=1;i<=a;i++){
			for(int j=1;j<=a/i;j++) {
				int sum=Math.abs(j-i)+a-j*i;
				if(sum<ans) {
					ans=sum;
				}
			}
		}
		System.out.println(ans);
}
	}