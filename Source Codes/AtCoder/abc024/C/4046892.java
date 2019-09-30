import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int N=sc.nextInt();
        int D=sc.nextInt();
        int K=sc.nextInt();
        int[] ans=new int[K];
        int[] L=new int[D+1];
        int[] R=new int[D+1];
        int[] S=new int[K];
        int[] T=new int[K];
        for (int i = 1; i <= D; i++) {
            L[i]=sc.nextInt();
            R[i]=sc.nextInt();
        }
        for (int i = 0; i < K; i++) {
            S[i]=sc.nextInt();
            T[i]=sc.nextInt();
        }
        for (int i = 1; i <= D; i++) {
            for (int j = 0; j < K; j++) {
                if(range(S[j],L[i],R[i])==0){
                    if(range(T[j],L[i],R[i])==0&&ans[j]==0){
                        ans[j]=i;
                    }else if(range(T[j],L[i],R[i])==-1){
                        S[j]=L[i];
                    }else{
                        S[j]=R[i];
                    }
                }
            }
        }
        for(int k:ans)out.println(k);
    }
    static int range(int now,int left,int right){
        if(left<=now&&now<=right)return 0;
        if(now<left)return -1;
        else return 1;
    }
}