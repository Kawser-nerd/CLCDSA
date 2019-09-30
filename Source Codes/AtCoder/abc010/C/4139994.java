import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String[] ttttTV = scanner.nextLine().split(" ", 6);
        int txa = Integer.parseInt(ttttTV[0]);
        int tya = Integer.parseInt(ttttTV[1]);
        int txb = Integer.parseInt(ttttTV[2]);
        int tyb = Integer.parseInt(ttttTV[3]);
        int T = Integer.parseInt(ttttTV[4]);
        int V = Integer.parseInt(ttttTV[5]);

        double maxDistance = (double)(T * V);

        int n = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < n; i++) {
            String[] xy = scanner.nextLine().split(" ", 2);
            int x = Integer.parseInt(xy[0]);
            int y = Integer.parseInt(xy[1]);

            double distanceA = distance(txa - x, tya - y);
            double distanceB = distance(txb - x, tyb - y);
            if (distanceA + distanceB <= maxDistance) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }

    private static double distance(long xDiff, long yDiff) {
        return Math.sqrt(xDiff * xDiff + yDiff * yDiff);
    }
}