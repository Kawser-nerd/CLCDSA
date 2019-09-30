import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c = 0;
        for (int i = 0 ; i < n ; i++) {
            int a = sc.nextInt();
            if (a % 2 == 1) {
                c++;
            }
        }
        
        System.out.println(c % 2 == 0 ? "YES" : "NO");
    }

}