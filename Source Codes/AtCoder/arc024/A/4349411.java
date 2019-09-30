import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int L=sc.nextInt();
        int R=sc.nextInt();
        int[] l=new int[L];
        int[] r=new int[R];
        for (int i = 0; i < L; i++) {
            l[i]=sc.nextInt();
        }
        for (int i = 0; i < R; i++) {
            r[i]=sc.nextInt();
        }
        Arrays.sort(r);
        Arrays.sort(l);
        int i=0,j=0,ans=0;
        while (i<L&&j<R){
            if(l[i]==r[j]){
                i++;
                j++;
                ans++;
            }else if(l[i]>r[j]){
                j++;
            }else {
                i++;
            }
        }
        out.println(ans);
    }
}