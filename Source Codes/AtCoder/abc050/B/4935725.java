import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int[] nums=new int[n];
        int sum=0;
        for(int i=0;i<n;i++){
            nums[i]=sc.nextInt();
            sum+=nums[i];
        }
        int m=sc.nextInt();
        for(int i=0;i<m;i++){
            System.out.println(sum-nums[sc.nextInt()-1]+sc.nextInt());
        }
    }
    
 
}