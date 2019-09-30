import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int[] c = new int[n];

        for(int i = 0; i < n; i++) {
            c[i] = in.nextInt();
        }

        double ans = 0.0;
        for(int i = 0; i < n; i++){
            double cnt = 0.0;
            for(int j = 0; j < n; j++) {
                if(i != j && c[i] % c[j] == 0){
                    cnt += 1.0;
                }
            }

            if(cnt % 2 == 0) {
                ans += (cnt + 2) / (cnt * 2 + 2);
            }else{
                ans += 0.5;
            }
        }
        System.out.println(ans);
    }
}