import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextLong(), B = sc.nextLong(), ans = 0;
        if (A%2==1) {
            ans^=A-1;
            A--;
        }
        while ((B-A+1)%4!=0) {
            ans ^= B+1;
            B++;
        }
        System.out.println(ans);
    }
}