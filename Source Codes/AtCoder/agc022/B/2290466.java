import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] e = {2, 4, 3, 9, 8, 10, 6, 12};
        int[] o = {6, 2, 4 ,3, 9, 8, 10, 12};
        
        if (n == 3) {
            System.out.println("2 5 63");
            return;
        }
        
        int m = 0;
        boolean isEven = n % 2 == 0;
        for (int i = 0; i < n; i++) {
            System.out.print(isEven ? e[i % 8] + 12*m : o[i % 8] + 12*m);
            System.out.print(" ");
            if (i % 8 == 7) {
                m++;
            }
        }
    }
}