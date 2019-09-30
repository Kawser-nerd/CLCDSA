import java.util.*;
 
public class Main {
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int[][] nums=new int[n][2];
        for(int i=0;i<n;i++){
            nums[i][0]=sc.nextInt();
            nums[i][1]=i+1;
        }
        
        Comp comp=new Comp();
        comp.setIndex(0);
        Arrays.sort(nums,comp);
        for(int i=n;i>0;i--){
            System.out.println(nums[i-1][1]);
        }
 
    }
    
 
}
class Comp implements Comparator{
    int index=0;
    void setIndex(int i){
        index=i;
    }
    public int compare (Object a, Object b) {
        int[] int_a = (int[]) a;
        int[] int_b = (int[]) b;
        return (int_a[index] - int_b[index]);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.