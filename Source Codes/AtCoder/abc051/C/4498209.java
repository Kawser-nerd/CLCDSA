public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int sx = scanner.nextInt(), sy = scanner.nextInt(), tx = scanner.nextInt(), ty = scanner.nextInt(), dx = tx - sx, dy = ty - sy;

        for (int i = 0; i < dy; i++)
            System.out.print('U');
        for (int i = 0; i < dx; i++)
            System.out.print('R');
        for (int i = 0; i < dy; i++)
            System.out.print('D');
        for (int i = 0; i <= dx; i++)
            System.out.print('L');
        for (int i = 0; i <= dy; i++)
            System.out.print('U');
        for (int i = 0; i <= dx; i++)
            System.out.print('R');
        System.out.print("DR");
        for (int i = 0; i <= dy; i++)
            System.out.print('D');
        for (int i = 0; i <= dx; i++)
            System.out.print('L');
        System.out.print('U');
    }
}