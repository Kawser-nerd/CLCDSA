import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class Main{
    public static void main(String []args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        int arr [] = new int[3];
        arr[0]=a;
        arr[1]=b;
        arr[2]=c;

        Arrays.sort(arr);

        int x = (arr[2]*10 + arr[1]);
        System.out.println(x+arr[0]);
    }
}