import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int ans = 0;
		int N = scn.nextInt();
		if(N/100==1)ans++;
		if((N%100)/10==1)ans++;
		if(N%10==1)ans++;
		System.out.println(ans);
	}

}