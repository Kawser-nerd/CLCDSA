import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		long n = Long.parseLong(sc.next());
		sc.close();
		long num = 1;

		for(long i=2;i<=Math.sqrt(n);i++){
		    if(n%i==0){
				if(i==Math.sqrt(n))num += i;
				else num += i+n/i;
		    }
		}
		System.out.println(n==1?"Deficient":num==n?"Perfect":num>n?"Abundant":"Deficient");
	}

}