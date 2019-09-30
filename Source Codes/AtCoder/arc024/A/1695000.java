import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.HashMap;

public class Main {
    public static void main(String args[]) {
        int leftNum, rightNum, cnt = 0;

        Scanner scan = new Scanner(System.in);
        leftNum = scan.nextInt();
        rightNum = scan.nextInt();

        ArrayList<Integer> l_list = new ArrayList<Integer>();
        ArrayList<Integer> r_list = new ArrayList<Integer>();

        for(int i = 0; i < leftNum; i++)
            l_list.add(scan.nextInt());
        for(int i = 0; i < rightNum; i++)
            r_list.add(scan.nextInt());

        for(int i = 0; i < leftNum; i++) {
            int sameIndex = r_list.indexOf(l_list.get(i));
            if(sameIndex != -1) {
                cnt++;
                l_list.set(i, -1);
                r_list.set(sameIndex, -1);
            }
        }

        System.out.println(cnt);

    }
}