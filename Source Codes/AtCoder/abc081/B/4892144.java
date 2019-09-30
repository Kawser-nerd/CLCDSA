import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int bit = 0;
        for (int i=0; i<N; i++) {
            bit |= sc.nextInt();
        }
        System.out.println(Integer.numberOfTrailingZeros(bit));
    }
}