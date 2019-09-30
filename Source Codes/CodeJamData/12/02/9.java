import java.io.*;
import java.util.*;

public class Dancing {

	public static void main(String [] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(in.readLine());

		for(int i = 0; i < T; i++){
			StringTokenizer st = new StringTokenizer(in.readLine());
			int N = Integer.parseInt(st.nextToken());
			int S = Integer.parseInt(st.nextToken());
			int p = Integer.parseInt(st.nextToken());
			int[] scores = new int[N];
			for(int j = 0; j < N; j++){
				scores[j] = Integer.parseInt(st.nextToken());
			}

			int ans = 0;
			for(int j = 0; j < N; j++){
				if(p==0){
					ans++;
					continue;
				}

				if(scores[j]==0) continue;
				
				if(scores[j]/3>=p){
					ans++;
				} else if(scores[j]/3==p-1&&scores[j]%3>0){
					ans++;
				} else if(scores[j]/3==p-1&&scores[j]%3==0 && S>0){
					ans++;
					S--;
				} else if(scores[j]/3==p-2&&scores[j]%3==2 && S>0){
					ans++;
					S--;
				}
			}
			System.out.println("Case #" + (i+1) + ": " + ans);
		}
	}

}