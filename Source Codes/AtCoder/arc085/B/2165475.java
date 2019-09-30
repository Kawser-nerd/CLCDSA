import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Main m = new Main();
		m.run();
	}

	Scanner sc = new Scanner(System.in);

	void run() {
		int n = sc.nextInt();
		int z = sc.nextInt();
		int w = sc.nextInt();
		
		int a[] = new int[n+1];
		
		a[0] = w;
		for(int i = 0 ; i < n ; i ++){
			a[i+1] = sc.nextInt();
		}	
		
		for(int i = 0 ; i < n ; i++){
			a[i] = Math.abs(a[i] - a[n]);
		}
		
		System.out.println(Math.max(a[0],a[n-1]));
	}
}