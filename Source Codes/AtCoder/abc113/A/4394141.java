import java.io.*;
import java.util.Scanner;
import java.lang.Math;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
class Main{
    public static void main(String[]args){
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int A = scanner.nextInt();
        scanner.close();
        System.out.println(N+A/2);
    }

}