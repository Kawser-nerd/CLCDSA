import java.util.*;

public class Main {
	
	static int H;
	static int W;
	static int[] start;
	static int[] end;
	static int[] dx = {1,-1,0,0};
	static int[] dy = {0,0,1,-1};
	static char[][] map;
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);        
        
        H = sc.nextInt();
        W = sc.nextInt();
        
        long T = sc.nextLong();
        
        map = new char[H][W];
        for (int i = 0; i < H; i++) {
        	map[i] = sc.next().toCharArray();
        }
        
        for (int i = 0; i < H; i++) {
        	for (int j = 0; j < W; j++) {
        		if (map[i][j] == 'S') {
        			start = new int[]{i,j};
        		}
        		
        		if (map[i][j] == 'G') {
        			end = new int[]{i,j};
        		}
        	}
        }
        
        long l = 1;
        long r = T;
        while(l < r) {
        	long mid = (l + r) / 2;
        	
        	long max = warshallFloyd(mid);
        	
        	if (max == T) {
        		l = mid;
        		break;
        	} else if (max < T) {
        		l = mid+1;
        	} else {
        		r = mid-1;
        	}
        }
        
        System.out.println(warshallFloyd(l) <= T ? l : l - 1);
    }
    
    static long warshallFloyd(long t) {
    	long[][] wf = init(t);
    	
    	for (int k = 0; k < H*W; k++) {
    		for (int i = 0; i < H*W; i++) {
        		for (int j = 0; j < H*W; j++) {
        			wf[i][j] = Math.min(wf[i][j], wf[i][k] + wf[k][j]);
        		}
        	}
    	}
    	
    	long s = start[0] * W + start[1];
    	long e = end[0] * W + end[1];
		return wf[(int)s][(int)e];
    }
    
    static long[][] init(long t) {
    	long[][] wf = new long[H*W][H*W];
    	for (int i = 0; i < H*W; i++) {
    		for (int j = 0; j < H*W; j++) {
    			if (i == j)
    				wf[i][j] = 0;
    			else
    				wf[i][j] = Long.MAX_VALUE / 100;
    		}
    	}
    	
    	for (int i = 0; i < H*W; i++) {
    		int h = i / W;
    		int w = i % W;
    		
			for (int k = 0; k < 4; k++) {
				if (0 <= w + dx[k] && w + dx[k] < W && 0 <= h + dy[k] && h + dy[k] < H) {
					wf[i][(h+dy[k])*W + w + dx[k]] = map[h][w] == '#' ? t : 1;
				}
			}
    	}
    	
    	return wf;
    }
}