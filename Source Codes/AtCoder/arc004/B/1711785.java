import java.util.*;
import java.io.*;

public class Main {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int d[] = new int[N];

        for(int i = 0; i < N; i++)
            d[i] = scan.nextInt();

        int max = 0;
        int sum = 0;
        for(int num : d) {
            max = Math.max(max, num);
            sum += num;
        }
        if(2*max > sum)
            System.out.printf("%d\n%d\n", sum, 2*max - sum);
        else
            System.out.printf("%d\n%d\n", sum, 0);
    }
}