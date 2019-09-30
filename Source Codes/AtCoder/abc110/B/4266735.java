import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {

		int n = sc.nextInt(); int m = sc.nextInt(); int x = sc.nextInt(); int y = sc.nextInt();
		int[] xar = new int[n];
		for (int i=0; i<n; i++) xar[i] = sc.nextInt();
		Arrays.sort(xar);
		int[] yar = new int[m];
		for (int i=0; i<m; i++) yar[i] = sc.nextInt();
		Arrays.sort(yar);
		int xMax = xar[n-1];
		int yMin = yar[0];
		
		if (xMax >= yMin) {
			System.out.println("War"); return;
		}
		else {
			System.out.println(x<=xMax&&yMin<=y?"No War":"War");
		}
		
		
		
	}
}