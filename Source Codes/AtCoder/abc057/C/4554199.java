import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        int r = (int) Math.ceil(Math.sqrt(n));
        long tmp = n;
        for (int i = r; i > 0; i--) {
            if(n % i == 0){
                tmp = n / i;
                break;
            }
        }
        int ans = String.valueOf(tmp).length();

        System.out.println(ans);
        sc.close();
    }

}