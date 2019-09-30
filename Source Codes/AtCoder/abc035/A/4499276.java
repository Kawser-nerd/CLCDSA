import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int w = sc.nextInt();
        int h = sc.nextInt();
        if (w % 4 == 0 && h % 3 == 0 && w / 4 == h / 3) {
            System.out.println("4:3");
        } else {
            System.out.println("16:9");
        }
    }

}