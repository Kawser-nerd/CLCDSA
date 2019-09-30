import java.util.Scanner;
public class Main
{
	Scanner cin = new Scanner(System.in);
	int L,X,Y,S,D;
	public void solve(){
		L = cin.nextInt();
		X = cin.nextInt();
		Y = cin.nextInt();
		S = cin.nextInt();
		D = cin.nextInt();
		
		double ans = Double.MAX_VALUE;
		if(D >= S){
			ans = (double)(D - S) / (X + Y);
			if(X < Y){
				ans = Math.min(ans,(double)(L - D + S) / (Y - X));
			}
		}else{
			ans = (double)(L - S + D) / (X + Y);
			if(X < Y){
				ans = Math.min(ans,(double)(S - D) / (Y - X));
			}
		}
		
		
		
		System.out.println(ans);
		
	}
	public static void main(String[] args)
	{
		new Main().solve();
	}
}