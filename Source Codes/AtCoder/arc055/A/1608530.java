import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().solve();
	}

	void solve(){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		String ans="1";
		for(int i=0;i<n-1;i++) {
			ans+="0";
		}
		ans+="7";
		System.out.println(ans);
	}
}