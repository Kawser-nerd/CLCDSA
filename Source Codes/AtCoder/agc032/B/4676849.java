import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = 0;
        int[][] ans;
        if(n % 2 ==0){
            m = (n - 2) * n / 2;
            ans = new int[m][2];
            int c = 0;
            for (int i = 1; i < n; i++) {
                for (int j = i+1; j <= n; j++) {
                    if(i + j == n+1) continue;
                    ans[c][0] = i;
                    ans[c][1] = j;
                    c++;
                }
            }
        }else{
            int n2 = n-1;
            m = (n2 - 2) * n2 / 2 + n2;
            ans = new int[m][2];
            int c = 0;
            for (int i = 1; i < n; i++) {
                for (int j = i+1; j <= n; j++) {
                    if(i + j == n) continue;
                    ans[c][0] = i;
                    ans[c][1] = j;
                    c++;
                }
            }
        }
        System.out.println(m);
        for (int i = 0; i < m; i++) {
            System.out.println(ans[i][0] + " " + ans[i][1]);
        }
        sc.close();
    }

}