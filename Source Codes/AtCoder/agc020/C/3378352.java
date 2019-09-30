import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int sum= 0;
        //int len = 4000000;
        for(int i=0;i<n;i++) {
            a[i] = sc.nextInt();
            sum += a[i];
        }
        BitSet bs = new BitSet(sum+1);
        bs.set(sum);
        for(int i=0;i<n;i++){
            BitSet cur = bs.get(a[i],sum+1);
            bs.or(cur);
        }
        int ini = sum%2==0?sum/2:(sum+1)/2;
        for(int i=ini;i<=sum;i++){
            if(bs.get(i)){
                System.out.println(i);
                break;
            }
        }
    }
}