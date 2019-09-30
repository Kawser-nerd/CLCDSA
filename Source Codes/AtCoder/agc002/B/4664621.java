import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] b = new int[n];
        Arrays.fill(b, 1);
        boolean[] r = new boolean[n];
        r[0] = true;
        int ans = 1;
        for (int i = 0; i < m; i++) {
            int x = sc.nextInt() -1;
            int y = sc.nextInt() -1;
            b[x]--;
            b[y]++;
            if(r[x]){
                if(!r[y]){
                    ans++;
                    r[y] = true;
                }
                if(b[x] == 0){
                    ans--;
                    r[x] = false;
                }
            }
        }

        System.out.println(ans);
        sc.close();
    }

}