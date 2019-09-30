import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] grid = new String[n];
		for (int i=0;i<n;i++) {
			grid[i] = sc.next();
		}

		int ans = 0;
		for (int i=0;i<n;i++) {
			boolean sym = true;
			for (int j=0;j<n;j++) {
				for(int k=0;k<n;k++) {
					if (grid[j].charAt((k+i)%n) != grid[k].charAt((j+i)%n)) {
						sym=false;
					}
				}
			}
			if(sym) {
				ans += n;
			}
		}
		System.out.println(ans);
	}

}