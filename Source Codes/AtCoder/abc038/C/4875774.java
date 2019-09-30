import java.util.*;
class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        long[] nums=new long[n+1];
        for(int i=0;i<n;i++){
            nums[i]=sc.nextInt();
        }
        long output=0;
        long tmplength=1;
        for(int i=0;i<n;i++){
            if(nums[i]<nums[i+1]){
                tmplength++;
            }else{
                output+=tmplength*(tmplength+1)/2;
                tmplength=1;
            }
        }
        System.out.println(output);
    }
}