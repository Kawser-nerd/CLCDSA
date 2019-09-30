import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        int[][] t=new int[n][k];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                t[i][j]=sc.nextInt();
            }
        }
        Queue<Integer> rank=new ArrayDeque<>();
        Queue<Integer> q=new ArrayDeque<>();
        for (int i = 0; i < k; i++) {
            q.add(t[0][i]);
            rank.add(0);
        }
        while (!q.isEmpty()){
            int p=q.poll();
            int row=rank.poll();
            if(p==0){
                out.println("Found");
                exit(0);
            }
            for (int i = 0; i < k&&row<n-1; i++) {
                q.add(p^t[row+1][i]);
                rank.add(row+1);
            }
        }
        out.println("Nothing");
    }
}