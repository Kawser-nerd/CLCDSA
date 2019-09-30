import java.util.Scanner;

public class Main {
	static byte[] asciiCodes;
	static int[] c = new int[26];//????a-z ? alphabet?????
	static long Mod = 1_000_000_007;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Integer.parseInt(sc.next());
		String S = sc.next();
		sc.close();
        try {
            asciiCodes = S.getBytes("US-ASCII");
        } catch (Exception e) {
            e.printStackTrace();
            return;
        }
        for (int i = 0; i < asciiCodes.length; i++) {
        	c[asciiCodes[i]-97]++;
        }

		Main main = new Main();
		main.solve();
	}

	void solve() {
        long res = 1;
        for(int i=0;i<26;i++) {
        	res *= (c[i]+1);
        	while(res>Mod)res-=Mod;
        }
        res--;
        System.out.println(res);
	}
}