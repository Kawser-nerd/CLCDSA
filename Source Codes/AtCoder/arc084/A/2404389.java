import java.util.Scanner;
import java.util.Arrays;

// ?????b?c?????a?b,c???????
public class Main {
    public static void main(String[] args) throws Exception {
        // ??
        Scanner sc = new Scanner(System.in);
        int n=Integer.parseInt(sc.next());
        int[] a=new int[n];
        for(int i=0;i<n;i++)    a[i]=Integer.parseInt(sc.next());
        int[] b=new int[n];
        for(int i=0;i<n;i++)   b[i]=Integer.parseInt(sc.next());
        int[] c=new int[n];
        for(int i=0;i<n;i++)    c[i]=Integer.parseInt(sc.next());
        Arrays.sort(a); Arrays.sort(b); Arrays.sort(c);
        
        // ?b[i]???????c?????
        // Arrays.binarySearch??????????????????????????
        // ??????????????????????s?i?N?????????1???N?????????O(N+N)=O(N)???
        int[] cnum=new int[n];
        int s=0;
        for(int i=0;i<n;i++){
            while(s<n&&b[i]>=c[s])  s++;
            cnum[i]=n-s;
        }
        // cnum????
        long[] accum=new long[n+1];
        for(int i=n-1;i>=0;i--){
            accum[i]=accum[i+1]+cnum[i];
        }
        // accum???????a[i]????????b,c????????????
        // ??????????????
        long ret=0;
        s=0;
        for(int i=0;i<n;i++){
            while(s<n&&a[i]>=b[s])  s++;
            ret += accum[s];
        }
        System.out.println(ret);
    }
}