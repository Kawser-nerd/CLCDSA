import java.util.*;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Collections;
import java.awt.Point;


public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int w = Integer.parseInt(br.readLine());
        String[] nk = br.readLine().split(" ");
        int n = Integer.parseInt(nk[0]);
        int k = Integer.parseInt(nk[1]);
        int[] width = new int[n+1];
        int[] value = new int[n+1];
        
        for (int i = 1; i < n+1; i++) {
            String[] s = br.readLine().split(" ");
            width[i] = Integer.parseInt(s[0]);
            value[i] = Integer.parseInt(s[1]);
        }
        
        //i??????????j?????k???????
        //int[][] dp = new int[n+1][w+1];
        
        /*for (int i = 0; i < n+1; i++) {
            dp[i][0] = 0;
        }
        
        for (int j = 0; j < w+1; j++) {
            dp[0][j] = 0;
        }
        
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < w+1; j++) {
                if (j-width[i] >= 0) {
                    dp[i][j] = dp[i-1][j-width[i]] + value[i];
                }
            }
        }*/
        
        //i??????????j?????l???????
        int[][][] dp = new int[n+1][w+1][k+1];
        
        for (int i = 0; i < n+1; i++) {
            for (int l = 0; l < k+1; l++) {
                dp[i][0][l] = 0;
            }
        }
        
        for (int j = 0; j < w+1; j++) {
            for (int l = 0; l < k+1; l++) {
                dp[0][j][l] = 0;
            }
        }
        
        for (int i = 0; i < n+1; i++) {
            for (int j = 0; j < w+1; j++) {
                dp[i][j][0] = 0;
            }
        }
        
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < w+1; j++) {
                for (int l = 1; l < k+1; l++) {
                    if (j-width[i] >= 0) {
                        dp[i][j][l] = Math.max(dp[i-1][j-width[i]][l-1]+value[i], dp[i-1][j][l]);
                    }
                    else {
                        dp[i][j][l] = dp[i-1][j][l];
                    }
                }
            }
        }
        
        System.out.println(dp[n][w][k]);
    }
}

class Box {
    int w;
    int h;
    public Box(int w, int h) {
        this.w = w;
        this.h = h;
    }
}

class BoxComparator1 implements Comparator<Box>{
	public int compare(Box b1, Box b2) {
		return b1.w - b2.w;
	}
}

class BoxComparator2 implements Comparator<Box> {
    public int compare(Box b1, Box b2) {
        return b1.h - b2.h;
    }
}