import java.util.*;
import java.lang.*;
import java.io.*;


public class Main {
    public static long givenFunc(long b, long n){
        if(b<=1) return -1;
        if (n<b) return n;
        else return givenFunc(b,n/b)+n%b;
    }
    public static long solve(long N, long S){
        //when b is small enough, we can check it with the definition of func
        for(long b=2;b*b<=N;b++){
        	if(givenFunc(b,N)==S) return b;
        }
        //if b>sqrt(N), N=pb+q and S=p+q where p<sqrt(n)
        for(long p=(int)Math.sqrt(N)+1;p>=1;p--){
        	long b = 1+(N-S)/p;
        	if(givenFunc(b,N)==S) return b;
        }
        return N==S ? N+1 : -1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long S = sc.nextLong();
        System.out.println(solve(N,S));
    }
}