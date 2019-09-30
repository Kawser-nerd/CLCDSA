import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int dif=Math.abs(sc.nextInt()-sc.nextInt());
		int ans=dif/10;
		int mod=dif%10;
		if(mod==1||mod==5) {
			ans++;
		}else if(mod==8||mod==7||mod==3) {
			ans+=3;
		}else if(mod==0){
		}else {
			ans+=2;
		}
		System.out.println(ans);
	}
}