import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		long[] SMatch = new long [5];
		for(int i=0;i<n;i++) {
			String s = sc.next();
				 if(s.substring(0, 0+1).equals("M"))SMatch[0]++;
			else if(s.substring(0, 0+1).equals("A"))SMatch[1]++;
			else if(s.substring(0, 0+1).equals("R"))SMatch[2]++;
			else if(s.substring(0, 0+1).equals("C"))SMatch[3]++;
			else if(s.substring(0, 0+1).equals("H"))SMatch[4]++;
		}
		sc.close();
		long res=0;
		int[] P={0,0,0,0,0,0,1,1,1,2};
		int[] Q={1,1,1,2,2,3,2,2,3,3};
		int[] R={2,3,4,3,4,4,3,4,4,4};
		for(int i=0;i<10;i++)res += SMatch[P[i]]*SMatch[Q[i]]*SMatch[R[i]];

		System.out.println(res);
	}

}