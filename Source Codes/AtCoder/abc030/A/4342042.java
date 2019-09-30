import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        int a, b, c, d;
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();

        double x = (double)b / a;
        double y = (double)d / c;

        String output = "";
        if(x > y)output = "TAKAHASHI";
        else if(x < y)output = "AOKI";
        else output = "DRAW";

        System.out.println(output);
    }
}