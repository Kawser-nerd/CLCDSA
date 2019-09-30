import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sx = sc.nextInt();
        int sy = sc.nextInt();
        int gx = sc.nextInt();
        int gy = sc.nextInt();
        int dx = gx - sx;
        int dy = gy - sy;
        for (int i = 0; i < dx; i++) {
            System.out.print("R");
        }
        for (int i = 0; i < dy; i++) {
            System.out.print("U");
        }
        for (int i = 0; i < dx; i++) {
            System.out.print("L");
        }
        for (int i = 0; i < dy; i++) {
            System.out.print("D");
        }
        System.out.print("D");
        for (int i = 0; i < dx; i++) {
            System.out.print("R");
        }
        System.out.print("R");
        for (int i = 0; i < dy; i++) {
            System.out.print("U");
        }
        System.out.print("U");
        System.out.print("L");
        System.out.print("U");
        for (int i = 0; i < dx; i++) {
            System.out.print("L");
        }
        System.out.print("L");
        for (int i = 0; i < dy; i++) {
            System.out.print("D");
        }
        System.out.print("D");
        System.out.print("R");
        System.out.println();
    }
}