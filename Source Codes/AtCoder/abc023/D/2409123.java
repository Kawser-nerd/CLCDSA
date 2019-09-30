import java.util.Scanner;
import java.util.Arrays;

public class Main {
    
    private static double eps=1e-9;
    
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n=Integer.parseInt(sc.next());
        int[] h=new int[n];
        int[] s=new int[n];
        for(int i=0;i<n;i++){
            h[i]=Integer.parseInt(sc.next());
            s[i]=Integer.parseInt(sc.next());
        }
        // ????
        long left=0;
        long right=1000000000000000L;
        for(int t=0;t<50;t++){
            long mid=(left+right)/2;
            // ??????mid??????????
            double[] costTime=new double[n];
            for(int i=0;i<n;i++){
                costTime[i] = (double)(mid - h[i]) / s[i];
            }
            Arrays.sort(costTime);
            // ????????????
            boolean ok=true;
            for(int i=0;i<n;i++){
                if(costTime[i] - i < -eps){
                    ok=false;
                }
            }
            if(ok){
                right=mid;
            }
            else{
                left=mid;
            }
        }
        System.out.println(right);
    }
}