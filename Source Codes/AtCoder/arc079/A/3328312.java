import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        boolean[][] d = new boolean[n][2];
        for(int i=0; i<m; i++){
            int a = sc.nextInt()-1;
            int b = sc.nextInt()-1;
            if(a == 0) d[b][0] = true;
            if(b == n-1) d[a][1] = true;
        }
        sc.close();

        boolean ans = false;
        for(int i=0; i<n; i++){
            if(d[i][0] && d[i][1]) ans = true;
        }

        if(ans){
            System.out.println("POSSIBLE");
        }else{
            System.out.println("IMPOSSIBLE");
        }
    }
}