import java.util.*;
import java.util.stream.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt();
        int[] d = new int[n + 1];
        int cd = 0;
        for(int i = 1; i <= n; d[i] = i++);
        for(int i = 0; i < m; i++) {
            int dd = in.nextInt();
            for(int k = 1; k < d.length; k++) {
                if(d[k] == dd) {
                    d[k] = cd; cd = dd;
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            System.out.println(d[i]);
        }
    }
}