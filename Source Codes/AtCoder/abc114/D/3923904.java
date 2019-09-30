import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.close();
        int[] P = new int[48];
        int over74 = 0;
        int over24 = 0;
        int over14 = 0;
        int over4 = 0;
        int over2 = 0;
        for(int i = 2; i <= N; i++){
            int x = i;
            for(int j = 2; j < Math.min(N, 48); j++){
                while(x % j == 0){
                    x /= j;
                    P[j]++;
                }
            }
        }
        for(int p: P){
            if(p >1) over2++;
            if(p >3) over4++;
            if(p >13) over14++;
            if(p >23) over24++;
            if(p >73) over74++;
        }
        int ans = 0;
        ans += over74;
        if(over14 > 0 && over4 > 1) ans += over14 * (over4-1);
        if(over24 > 0 && over2 > 1) ans += over24 * (over2-1);
        if(over4 > 1 && over2 > 2) ans += (over4 * (over4-1) / 2) * (over2 - 2);

        System.out.println(ans);
    }

}