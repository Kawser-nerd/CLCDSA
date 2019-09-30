import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String ans;

        if(n % S(n) == 0)ans = "Yes";
        else ans = "No";

        System.out.println(ans);
    }

    public static int S(int n){
        int ans = 0;
        while(n > 0){
            ans += n % 10;
            n /= 10;
        }

        return ans;
    }
}