import java.util.Scanner;

class Main{
	public static void main(String arg[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		sc.close();
		int ans = 0;
		
		for(int i = 1; i <= N; i++) {
			if(splitN(i) >= A && splitN(i) <= B) {
				ans += i;
			}
		}
		System.out.println(ans);
	}
	
	public static int splitN(int n) {
		int sum = 0;
		String str = Integer.toString(n);
		String[] S = str.split("");
		
		for(int i = 0; i < S.length; i++) {
			sum += Integer.parseInt(S[i]); 
		}
		return sum;
	}
}