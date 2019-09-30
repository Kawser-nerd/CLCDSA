import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int sx = scanner.nextInt();
    int sy = scanner.nextInt();
    int tx = scanner.nextInt();
    int ty = scanner.nextInt();

    int x = ((tx - sx) >> 31) | 1;
    int y = ((ty - sy) >> 31) | 1;
    int nx = (tx - sx) * x;
    int ny = (ty - sy) * y;

    //System.out.printf("x = %d, y = %d, nx = %d, ny = %d\n", x, y, nx, ny);

    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < ny; i++) sb.append(y > 0 ? 'U' : 'D');
    y *= -1;
    for (int i = 0; i < nx + 1; i++) sb.append(x > 0 ? 'R' : 'L');
    x *= -1;
    for (int i = 0; i < ny + 1; i++) sb.append(y > 0 ? 'U' : 'D');
    y *= -1;
    for (int i = 0; i < nx + 1; i++) sb.append(x > 0 ? 'R' : 'L');
    sb.append(y > 0 ? 'U' : 'D');
    sb.append(x > 0 ? 'R' : 'L');
    x *= -1;
    for (int i = 0; i < ny + 1; i++) sb.append(y > 0 ? 'U' : 'D');
    y *= -1;
    for (int i = 0; i < nx + 1; i++) sb.append(x > 0 ? 'R' : 'L');
    x *= -1;
    for (int i = 0; i < ny + 1; i++) sb.append(y > 0 ? 'U' : 'D');
    for (int i = 0; i < nx; i++) sb.append(x > 0 ? 'R' : 'L');

    System.out.println(sb.toString());
  }
}