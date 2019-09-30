import java.util.Scanner;

class Main{
	public static void main(String arg[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		sc.nextLine();
		String str = sc.nextLine();
		sc.close();
		String[]S = str.split(" "); 
		int[] n = new int[N];
		int count = 0;
		
		for(int i = 0; i < N; i++) {
			n[i] = Integer.valueOf(S[i]);
		}
		while(true) {
			for ( int j = 0; j< n.length; j++) {
				if(n[j] % 2 == 0) {
					n[j]= n[j]/2;
				}else {
					System.out.println(count);
					System.exit(0);
				}
			}
			count++;
		}
	}
}