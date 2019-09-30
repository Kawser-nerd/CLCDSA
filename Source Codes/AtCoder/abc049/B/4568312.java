import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        String s;
        for (int i = 0; i < h; i++) {
            s = sc.next();
            System.out.println(s);
            System.out.println(s);
        }
        sc.close();
    }
}