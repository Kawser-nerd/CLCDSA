import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        char[][] mass = new char[n][n];
        
        for (int i = n-1; i >= 0; i--) {
            String s = sc.next();
            for (int j = 0; j < n; j++) {
                mass[j][i] = s.charAt(j);
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (char c : mass[i])
                System.out.print(c);
            System.out.println();
        }
    }
}