import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int x1 = in.nextInt();
        int y1 = in.nextInt();

        int r = in.nextInt();

        int x2 = in.nextInt();
        int y2 = in.nextInt();
        int x3 = in.nextInt();
        int y3 = in.nextInt();

        int[] x = {x2, x2, x3, x3};
        int[] y = {y2, y3, y2, y3};

        if(x2 <= x1-r && x3 >= x1+r && y2 <= y1-r && y3 >= y1+r) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
        }

        for(int i=0; i<4; i++) {
            if((x[i]-x1) * (x[i]-x1) + (y[i]-y1) * (y[i]-y1) > r * r) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");

        in.close();
    }
}