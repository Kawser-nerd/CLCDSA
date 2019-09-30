import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c = sc.nextInt();

        int[] odd = new int[10];
        int[] even = new int[10];

        for(int i = 0; i < n; i++) {
            int a = sc.nextInt();
            if((i+1) % 2 == 1) {
                odd[a-1]++;
            }
            else {
                even[a-1]++;
            }
        }

        int max = 0;
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if(i != j) {
                    max = Math.max(max, odd[i]+even[j]);
                }
            }
        }

        int ans = c * (n - max);
        System.out.println(ans);
    }
}