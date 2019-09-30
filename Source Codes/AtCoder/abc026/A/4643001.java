import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int max = 0;
        for (int i = 1 ; i <= a ; i++) {
            max = Math.max(max, i * (a - i));
        }
        System.out.println(max);


    }

}