import java.util.Scanner;


public class Candy {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int nbCase = s.nextInt();
        for (int numCase = 1 ; numCase <= nbCase ; numCase++) {
            s.nextLine();
            int nbCandy = s.nextInt();
            s.nextLine();
            int min = Integer.MAX_VALUE;
            int sum = 0;
            int xor = 0;
            for (int i = 0 ; i < nbCandy ; i++) {
                int n = s.nextInt();
                min = Math.min(min, n);
                sum += n;
                xor ^= n;
            }
            System.out.print("Case #");
            System.out.print(numCase);
            System.out.print(": ");
            if (xor == 0) {
                System.out.println(sum-min);
            } else {
                System.out.println("NO");
            }
        }
    }
}
