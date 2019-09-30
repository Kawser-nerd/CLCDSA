import java.util.*;

public class Main {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int[][] rel = new int[n+1][n+1];
        for(int i = 0;i < m;i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            rel[x][y] = 1;
        }

        int[] ans = new int[n+1];
        int max = 0;
        for(int pat = 1;pat < Math.pow(2,n);pat++){
            boolean check = true;
            BitSet bs = BitSet.valueOf(new long[]{pat});
            for(int i = 0;i < n;i++){
                for(int j = i+1;j < n;j++){
                    if(bs.get(i) && bs.get(j)){
                        check = rel[i+1][j+1] == 1;
                    }
                    if(!check) break;
                }
                if(!check) break;
            }
            if(check){
                max = Math.max(max, bs.cardinality());
            }
        }
        System.out.println(max);
    }
}