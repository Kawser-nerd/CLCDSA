import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int[] nums=new int[n];
        for(int i=0;i<n;i++){
            nums[i]=sc.nextInt();
        }
        for(int i=0;i<n;i++){
            nums[i]=nums[i]/(int)Math.pow(2,dividebyN(nums[i],2));
        }
        Arrays.sort(nums);
        int tmp=0;
        int output=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=tmp){
                tmp=nums[i];
                output++;
            }
        }
        System.out.println(output);
    }
    static int dividebyN(int input,int n){
        int output=0;
        while(true){
            if(input%n==0){
                output++;
                input/=n;
            }else{
                break;
            }
        }
        return output;
    }

}