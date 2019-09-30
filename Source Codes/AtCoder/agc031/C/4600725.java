import java.util.*;
import java.io.*;

public class Main {

    static void impossible(){
        System.out.println("NO");
        System.exit(0);
    }

    static int[] answer(int N, int end){// route of 0 -> end
        //assert bitCount(end) is odd
        if(N==1) return new int[]{0, 1};
        if(N==2){
            switch(end){
                case 1: return new int[]{0,2,3,1};
                default: return new int[]{0,1,3,2};
            }
        }

        int[] ans = new int[1 << N];
        if((end&(1<<(N-1)))==0){
            int[] smaller = answer(N-1, end);
            for(int i=0; i<smaller.length; i++){
                if((i&1)==0){
                    ans[2*i] = smaller[i];
                    ans[2*i+1] = smaller[i] | (1<<(N-1));
                }else{
                    ans[2*i] = smaller[i] | (1<<(N-1));
                    ans[2*i+1] = smaller[i];
                }
            }
            return ans;
        }else{
            int[] smaller1 = answer(N-1, 1);
            for(int n=0; n<(1<<(N-1)); n++) ans[n]=smaller1[n];
            int[] smaller2 = answer(N-1, end^(1<<(N-1))^1);
            for(int n=0; n<(1<<(N-1)); n++) ans[(1<<(N-1))+n]=smaller2[n] ^ (1<<(N-1)) ^ 1;
            return ans;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();
        if(Integer.bitCount(A^B) %2 ==0) impossible();

        System.out.println("YES");
        int[] ans = answer(N, A^B);
        for(int i=0; i<ans.length; i++) ans[i] ^= A;
        for(int i=0; i<ans.length; i++){
            System.out.print(ans[i]);
            if(i==ans.length-1) System.out.println();
            else System.out.print(" ");
        }


    }
}