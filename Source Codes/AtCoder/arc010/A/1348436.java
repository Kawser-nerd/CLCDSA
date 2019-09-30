import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] param = br.readLine().split(" ");
		Integer defo  = Integer.valueOf(param[0]);
		Integer nissu = Integer.valueOf(param[1]);
		Integer limit = Integer.valueOf(param[2]);
		Integer hojuu = Integer.valueOf(param[3]);

		Integer tmpMaisu = defo;
		if(tmpMaisu <= limit) {
			tmpMaisu += hojuu;
		}
		for(int i = 0; i < nissu; i ++) {
			tmpMaisu -= Integer.valueOf(br.readLine());
			if(tmpMaisu < 0) {
				System.out.println(i+1);
				return;
			}
			if(tmpMaisu <= limit) {
				tmpMaisu += hojuu;
			}
		}
		System.out.println("complete");
	}
}