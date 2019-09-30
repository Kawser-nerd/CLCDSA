import java.util.Scanner;

class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int A = scan.nextInt();
        int B = scan.nextInt();
        int C = scan.nextInt();
        int D = scan.nextInt();
        scan.close();
        if ((float)B / A == (float)D / C) {
            System.out.println("DRAW");
            return;
        }
        System.out.println((float)B / A > (float)D / C ? "TAKAHASHI" : "AOKI");
    }
}