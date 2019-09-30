import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int x , a , b;
        Scanner sc = new Scanner(System.in);
        x = sc.nextInt();
        a = sc.nextInt();
        b = sc.nextInt();
        simpleDist(x, a, b);

    }

    private static void simpleDist(int x, int a, int b) {
        int max = 1000, min =1;
        if ((x <= max && a<=max && b<=max) && (x >= min && a >=min && b>=min)  ){
            String res= Math.abs(x-a) < Math.abs(x-b) ? "A" : "B";
            System.out.println(res);
        }
    }
}