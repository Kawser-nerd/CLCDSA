import java.io.*;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) throws IOException{
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        boolean canTravel = true;

        int prevT = 0;
        int prevX = 0;
        int prevY = 0;

        for (int i = 0; i < n; i++) {
            int t = in.nextInt();
            int x = in.nextInt();
            int y = in.nextInt();

            canTravel = canTravel && canEvenOdd(x - prevX, y - prevY, t - prevT);
            canTravel = canTravel && insideDiamond(x - prevX, y - prevY, t - prevT);

            prevT = t;
            prevX = x;
            prevY = y;
        }
        
        if (canTravel) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    private static boolean canEvenOdd(int x, int y, int t){
        int absX = Math.abs(x);
        int absY = Math.abs(y);
        int absT = Math.abs(t);
        return (absX + absY) % 2 == absT % 2;
    }

    private static boolean insideDiamond(int x, int y, int segment){
        int absX = Math.abs(x);
        int absY = Math.abs(y);
        int absSegment = Math.abs(segment);
        return absY <= -absX + absSegment; 
    }
}