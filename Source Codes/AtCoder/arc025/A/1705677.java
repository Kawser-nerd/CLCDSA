import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        int max_sum = 0;
        Scanner scan = new Scanner(System.in);
        ArrayList<Integer> d = new ArrayList<Integer>();
        ArrayList<Integer> j = new ArrayList<Integer>();

        for(int i = 0; i < 7; i++)
            d.add(scan.nextInt());
        for(int i = 0; i < 7; i++)
            j.add(scan.nextInt());

        for(int i = 0; i < 7; i++)
            max_sum += Math.max(d.get(i), j.get(i));

        System.out.println(max_sum);

    }
}