import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Round1A {

	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter("A.txt");

		//String[] spl = in.readLine().split(" ");
		int T = Integer.parseInt(in.readLine());
		for(int c=1;c<=T;c++){
			String s = in.readLine();
			int[] fl = new int[s.length()];
			int nfl = 0;
			while(nfl < s.length()){
				char last = (char)('A'-1);
				int firstL = -1;
				for(int i=0; i<s.length(); i++){
					if(fl[i]==0 && s.charAt(i) > last){
						last = s.charAt(i);
						firstL = i;
					}
				}
				for(int i=firstL; i<s.length();i++){
					if(fl[i]==0){
						nfl++;
						if(s.charAt(i) == last){
							fl[i] = 1;
						}
						else fl[i]=-1;
					}
				}
			}
			String ans = "";
			for(int i=0;i<s.length();i++){
				if(fl[i]==1){
					ans = s.charAt(i)+ans;
				}
				else if(fl[i]==-1){
					ans = ans+s.charAt(i);
				}
			}
			pw.println("Case #"+c+": "+ans);
		}
		pw.close();
	}

}
