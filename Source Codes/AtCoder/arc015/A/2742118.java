import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Main {

    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        int cel = scan.nextInt();
        float mul = 9f / 5f;
        System.out.println(mul * cel + 32);
    }
}