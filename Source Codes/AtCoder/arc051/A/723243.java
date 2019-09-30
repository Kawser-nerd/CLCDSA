import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static int[][] color;
    static void mark(int x, int y) {
        color[x + 250][y + 250]++;
    }


    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int x1 = sc.nextInt(), y1 = sc.nextInt(), r = sc.nextInt();
        int x2 = sc.nextInt(), y2 = sc.nextInt();
        int x3 = sc.nextInt(), y3 = sc.nextInt();

        int len = 500;
        color = new int[len][len];

        for(int x = -200; x <= 200; x++) {
            for(int y = -200; y <= 200; y++) {
                if((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) <= r * r) {
                    mark(x, y);
                }
                if(x2 <= x && x <= x3 && y2 <= y && y <= y3) {
                    mark(x, y);
                    mark(x, y);
                }
            }
        }

        boolean isRed = false;
        boolean isBlue = false;

        for(int x = -200; x <= 200; x++) {
            for(int y = -200; y <= 200; y++) {
                isRed |= color[x + 250][y + 250] == 1;
                isBlue |= color[x + 250
                        ][y + 250] == 2;
            }
        }

        if(isRed) System.out.println("YES");
        else System.out.println("NO");
        if(isBlue) System.out.println("YES");
        else System.out.println("NO");
    }
}