import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int q = sc.nextInt();
		String s = sc.next();
		int[] data = new int[n];
		data[n-1] = 0;
		for(int i = s.length()-2; i >= 0; i--) {
			data[i] = data[i+1];
			if(s.substring(i, i+2).equals("AC"))
				data[i]++;
		}
		for(int i =0; i < q; i++) {
			int l = sc.nextInt()-1;
			int r = sc.nextInt()-1;
			System.out.println(data[l] - data[r]);
		}
	}
}