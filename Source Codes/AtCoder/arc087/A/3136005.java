import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] count = new int[100001];
        for(int i=0; i<n; i++){
            int a = sc.nextInt();
            if(a <= 100000){
                count[a]++;
            }else{
                count[0]++;
            }
        }
        sc.close();

        int ans = count[0];
        for(int i=1; i<=100000; i++){
            if(count[i] >= i){
                ans += count[i] - i;
            }else{
                ans += count[i];
            }
        }

        System.out.println(ans);
    }
}