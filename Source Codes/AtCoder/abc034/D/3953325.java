import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[]$) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        int[] w=new int[n];
        int[] p=new int[n];
        for (int i = 0; i < n; i++) {
            w[i]=sc.nextInt();
            p[i]=sc.nextInt();
        }

        double max=100,min=0,mid=0;
        for (int i = 0; i <40 ; i++) {
            double[] d=new double[n];
            double sum=0;
            mid=(max+min)/2;
            for (int j = 0; j <n ; j++) {
                d[j]=(p[j]-mid)*w[j];
            }//????????????????????????????????????
            Arrays.sort(d);
            for (int j = 1; j <=k; j++) {
                sum+=d[n-j];
            }
            if(sum>=0){
                min=mid;
            }else{
                max=mid;
            }
        }
        out.println(mid);
    }
}