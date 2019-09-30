import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt()+1;
        long[] nums=new long[n];
        nums[0]=0;
        long output=0;
        for(int i=1;i<n;i++){
            nums[i]=sc.nextInt();
        }
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        Arrays.sort(nums);
        long tmp=Integer.MIN_VALUE;
        int outtmp=0;
        for(int i=0;i<n;i++){
            if(tmp==nums[i]){
               outtmp++; 
               if(i==n-1){
                   i--;
                   tmp=Integer.MIN_VALUE;
               }
            }else{
                if(outtmp>1){
                    output+=nc2(outtmp);
                }
                tmp=nums[i];
                outtmp=1;
            }
            
        }
        System.out.println(output);
        
    }
    static long nc2(long input){
        long output=1;
        output=input*(input-1)/2;
        return output;
    }
        

    

}