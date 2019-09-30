import java.io.*;
import java.util.Scanner;
import java.lang.Math;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
class Main{
    public static void main(String[]args){
        Scanner scanner = new Scanner(System.in);

        int X = scanner.nextInt();
        int A = scanner.nextInt();
        int B = scanner.nextInt();

        System.out.println(X-A-(X-A)/B *B);

        scanner.close();
    }

}