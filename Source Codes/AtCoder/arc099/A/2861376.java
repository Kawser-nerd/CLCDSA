import java.util.*;

public class Main{
	
	public static void main(String[] args){
		Scanner sc= new Scanner(System.in);
        int num = sc.nextInt();
        int cut = sc.nextInt();
        int tmp, ans;
		
		for(int i=0; i<num; i++){
			tmp = sc.nextInt();
        }

        ans = (num-cut)/(cut-1) + 1;
        if((num-cut)%(cut-1) != 0) ans++;

        System.out.println(ans);

	}

}