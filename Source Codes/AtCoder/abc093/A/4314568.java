import java.util.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();

        List<Character> ss = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            ss.add(s.charAt(i));
        }

        if (ss.contains('a') && ss.contains('b') && ss.contains('c')) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}