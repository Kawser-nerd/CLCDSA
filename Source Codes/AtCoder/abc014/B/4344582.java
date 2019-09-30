import java.util.*;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);        
        
        int N = sc.nextInt();
        int X = sc.nextInt();
        
        int[] map = new int[N];
		for (int i = N-1; 0 <= i; i--) {
			map[i] = sc.nextInt();
		}
		
		String bi = "00000000000000000000" + Integer.toBinaryString(X);
		bi = bi.substring(bi.length()-N,bi.length());
		
		int ans = 0;
		for (int i = 0; i < bi.length(); i++) {
			ans += bi.charAt(i) == '1' ? map[i] : 0;
		}
		
		System.out.println(ans);
    }
}