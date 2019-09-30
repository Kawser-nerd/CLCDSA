import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int dif = (a / 15) * 200;

        long sum = a * 800l;

        sum -= dif;
        System.out.println(sum);
    }
}