import java.util.*;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int H = sc.nextInt();
        int W = sc.nextInt();
        
        int[][] wf = new int[10][10];
        for (int i = 0; i < 10; i++) {
        	for (int j = 0; j < 10; j++) {
        		wf[i][j] = sc.nextInt();
        	}
        }
        
        for (int k = 0; k < 10; k++) {
        	for (int i = 0; i < 10; i++) {
        		for (int j = 0; j < 10; j++) {
        			wf[i][j] = Math.min(wf[i][j], wf[i][k] + wf[k][j]);
        		}
        	}
        }
        
        int[] count = new int[10];
        for (int i = 0; i < H; i++) {
        	for (int j = 0; j < W; j++) {
        		int a = sc.nextInt();
        		if (a >= 0) {
        			count[a]++;
        		}
        	}
        }
        
        int sum = 0;
        for (int i = 0; i < 10; i++) {
        	if (i == 1)
        		continue;
        	
        	int cost = wf[i][1];
        	sum += cost*count[i];
        }
        
        System.out.println(sum);
    }
}