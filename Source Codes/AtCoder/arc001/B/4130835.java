import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int A = scn.nextInt();
		int B = scn.nextInt();
		int ans = 0;
		int DT = Math.abs(A-B);
		ans += DT/10;
		DT %= 10;
		if(DT < 4) {
			ans += DT;
		}else if(DT > 7){
			ans ++;
			ans += 10 - DT;
		}else {
			ans++;
			ans += Math.abs(DT-5);
		}
		System.out.println(ans);
	}

}