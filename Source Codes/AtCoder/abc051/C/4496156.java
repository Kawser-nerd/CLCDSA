import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sx = sc.nextInt();
        int sy = sc.nextInt();
        int tx = sc.nextInt();
        int ty = sc.nextInt();
        int dx = tx - sx;
        int dy = ty - sy;
        StringBuilder sb = new StringBuilder();
        go(sb, 'R', dx);
        go(sb, 'U', dy);
        go(sb, 'L', dx);
        go(sb, 'D', dy+1);
        go(sb, 'R', dx+1);
        go(sb, 'U', dy+1);
        go(sb, 'L', 1);
        go(sb, 'U', 1);
        go(sb, 'L', dx+1);
        go(sb, 'D', dy+1);
        go(sb, 'R', 1);

        System.out.println(sb.toString());
        sc.close();
    }

    private static void go(StringBuilder sb, char c, int dx) {
        for (int i = 0; i < dx; i++) {
            sb.append(c);
        }
    }

}