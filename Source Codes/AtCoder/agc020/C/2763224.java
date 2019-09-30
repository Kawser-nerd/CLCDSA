import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int[] a = new int[n];
        
        int sum = 0;
        for(int i=0; i<n; i++){
            a[i] = Integer.parseInt(sc.next());
            sum += a[i];
        }
        
        int len = 4000001;
        BitSet bs = new BitSet(len);
        bs.set(len);
        for(int i=0; i<n; i++){
            BitSet shift = bs.get(a[i], len+1);
            //System.out.println(shift);
            bs.or(shift);
        }
        
        for(int i=len-(sum+1)/2; i>0; i--){
            //System.out.println(len-i);
            if(bs.get(i)){
                System.out.println(len-i);
                break;
            }
        }
        
    }
}