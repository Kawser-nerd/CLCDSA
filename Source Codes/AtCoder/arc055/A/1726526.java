import java.util.Scanner;

public class Main {

    static Scanner in = new Scanner(System.in);

    void solve() {
        int n = in.nextInt();
        if(n == 0) {
            System.out.println(8);
            return;
        }
        else {
            System.out.print(1);
            for(int i = 0; i < n - 1; i++) {
                System.out.print(0);
            }
            System.out.println(7);
        }
    }



    public static void main(String[] args) {
        new Main().solve();
    }
}