import java.util.Scanner;
import java.util.Arrays;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int m = sc.nextInt();
        int mongen = 18*60;
        int now = h*60+m;
        System.out.println(mongen-now);
    }
}