import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        double[] nums=new double[n];
        for(int i=0;i<n;i++){
            nums[i]=sc.nextInt();
        }
        Arrays.sort(nums);
        double output=0;
        for(int i=0;i<k;i++){
            if(nums[n-k+i]>output){
                output=(nums[n-k+i]+output)/2;
            }
        }
        System.out.println(output);
        
        

    }

}