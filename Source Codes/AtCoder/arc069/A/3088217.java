import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long M = sc.nextLong();
        if(N*2>M) System.out.println(M/2);
        else System.out.println((N*2+M)/4);
    }
}