import java.util.Scanner;
								
public class Main{
			public static void main(String[] args) {
			Scanner sc = new Scanner(System.in);
			
			String str = sc.next();
			int[] tv = new int[str.length()];
			int n = str.length();
			for(int i=0;i<str.length();i++) {
				if(str.charAt(i)=='o') {
					tv[i] = 1;
				}
				else {
					tv[i] = 0;
				}
			}
			
			
			boolean can = false;
			int ret = 9999;
			for(int i=0;i<(1<<n);i++) {			//???(1<<n)???
				int cnt = 0;
				boolean[] now = new boolean[n];
				for(int j=0;j<n;j++) {		//????TV????????
					if((i>>j)%2==0)continue;
					cnt++;
					for(int k=0;k<n;k++) {
						if(tv[k]==0)continue;
						now[(j+k)%n] = true;  //????????????????
					}
				}
				boolean flag = true;
				for(int j=0;j<n;j++) if(!now[j])flag = false;
				if(flag) ret = Math.min(ret, cnt);
			}

			System.out.println(ret);
	}
}