import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        boolean[] p = new boolean[100001];
        Arrays.fill(p, true);
        p[0] = false; p[1] = false;
        boolean[] s = new boolean[100001];
        int[] sum = new int[100001];
        for (int i = 2; i <= 100000; i++) {
            sum[i] += sum[i-1];
            if(p[i]){
                for(int j = 2 * i; j <= 100000; j += i) p[j] = false;
                if(p[(i+1)/2]){
                    s[i] = true;
                    sum[i]++;
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < q; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            sb.append(sum[r] - sum[l-1]).append("\n");
        }

        System.out.println(sb.toString());
        sc.close();
    }

}