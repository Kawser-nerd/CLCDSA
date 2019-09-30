import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        double output=0;
        int tmp;
        int[] nums=new int[n];
        for(int i=0;i<n;i++){
            nums[i]=sc.nextInt();
        }
        Arrays.sort(nums);
        for(int i=n;i>0;i--){
            output+=((n-i)%2==0?1:-1)*Math.pow(nums[i-1], 2);
        }
        System.out.println(output*Math.PI);
    }
}