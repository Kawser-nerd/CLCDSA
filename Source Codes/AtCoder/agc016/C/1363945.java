import java.util.*;
 
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		long h = sc.nextLong();
		long w = sc.nextLong();
		
		long x = (-1000)*(h*w-1)-1;
		String[] ans = new String[H];
		for(int i=0; i<H; ++i){
			ans[i] = "";
		}
		
		long sum = 0;
		for(int i=1; i<=H; ++i){
			StringBuilder sb = new StringBuilder();
			for(int j=1; j<=W; j++){
				if(i%h==0 &&j%w==0){
					sb.append(x);
					sb.append(" ");
					sum+=x;
				}else{
					sb.append(1000);
					sb.append(" ");
					sum+=1000;
				}
			}
			sb.deleteCharAt(sb.length()-1);	
			ans[i-1] = sb.toString();
		}
		
		if(sum<=0) System.out.println("No");
		else{
			System.out.println("Yes");
			for(int i=0; i<H; i++){
				System.out.println(ans[i]);
			}
		}
		return;
	}
}