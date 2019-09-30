import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[] a = new int[n];
        
        for (int i = 0; i < q; i++) {
            int l = sc.nextInt()-1;
            int r = sc.nextInt();
            int t = sc.nextInt();
            for ( ; l < r; l++) {
                a[l] = t;
            }
        }
        
        for (int i : a) {
            System.out.println(i);
        }
    }
}