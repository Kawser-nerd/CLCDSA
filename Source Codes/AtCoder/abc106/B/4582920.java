import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int i, j, k, ans = 0, count;

        for(i = 1; i <= n; i++){
            count = 0;
            if(i % 2 == 1){
                for(j = 1; j <= i; j++){
                    if(i % j == 0)count++;
                }
            }

            if(count == 8)ans++;
        }

        System.out.println(ans);
    }
}