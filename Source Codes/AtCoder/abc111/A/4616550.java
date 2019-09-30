import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int ans=0;
		if(n%10==9)ans+=1;
		else ans+=9;
		n/=10;
		if(n%10==9)ans+=1*10;
		else ans+=9*10;
		n/=10;
		if(n%10==9)ans+=1*100;
		else ans+=9*100;
		
		System.out.println(ans);
		
	}
}