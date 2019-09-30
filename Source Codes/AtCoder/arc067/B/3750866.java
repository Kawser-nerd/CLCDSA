import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.Queue;
import java.text.DecimalFormat;

public class Main {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        long a = input.nextLong();
        long b = input.nextLong();
        long  fatiga = 0;

        input.nextLine();
        long pueblos[] = new long[n];
        for (int i = 0; i < n; i++) {
            pueblos[i] = input.nextLong();
        }
        input.nextLine();

        for (int i = 0; i <n-1 ; i++) {
            if((pueblos[i+1]-pueblos[i])*a < b)
                fatiga += (pueblos[i+1]-pueblos[i])*a;
            else
                fatiga += b;

        }
        System.out.println(fatiga);

        }
}