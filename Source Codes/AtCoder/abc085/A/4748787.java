import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s;
        s = sc.next();
        char str[] = s.toCharArray();
        str[3] = '8';
        System.out.println(str);
        sc.close();
    }
}