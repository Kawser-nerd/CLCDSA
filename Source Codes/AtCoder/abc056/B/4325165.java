import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int w = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();

        int diff = Math.max(a, b) - (Math.min(a,b)+w);

        if (diff > 0)
            System.out.println(diff);
        else
            System.out.println(0);
    }
}