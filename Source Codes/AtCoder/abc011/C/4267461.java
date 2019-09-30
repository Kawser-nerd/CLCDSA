import java.util.Scanner;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        
        int[] map = new int[3];
		for (int i = 0; i < 3; i++) {
			map[i] = sc.nextInt();
			
			if (map[i] == N) {
				System.out.println("NO");
				return;
			}
		}
        
        int now = N;
        for (int i = 1; i <= 100; i++) {
        	boolean flg = false;
        	for (int j = 3; 1 <= j; j--) {
        		int next = now - j;
        		if (next == map[0] || next == map[1] || next == map[2]) {
        			continue;
        		} else {
        			flg = true;
        			now = next;
        			break;
        		}
        	}
        	
        	if (!flg) {
        		System.out.println("NO");
        		return;
        	}
        	
        }
        
        System.out.println(now <= 0 ? "YES" : "NO");
    }
}