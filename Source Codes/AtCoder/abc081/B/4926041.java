import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int N=s.nextInt();
        int bit=1000000007;
        for(int i=0;i<N;i++){
            int x = s.nextInt();
            bit=Math.min(bit,Integer.lowestOneBit(x));
        }
        
        System.out.println((int)(Math.log(bit)/Math.log(2)));
    }  
}