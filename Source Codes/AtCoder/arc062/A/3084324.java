import java.util.*;
import java.lang.*;
import java.io.*;
public class Main {
    public static long divCeil(long a, long b){
        return (a+b-1)/b;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long tak = 1;
        long aok = 1;
        for(int n=0;n<N;n++){
        	long t = sc.nextLong();
        	long a = sc.nextLong();
        	long scale = Math.max(divCeil(tak,t), divCeil(aok,a));
        	tak = t*scale;
        	aok = a*scale;
        }
        System.out.println(tak+aok);
    }
}