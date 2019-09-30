import java.io.*;
import java.util.*;

public class BotTrust {

	public static void main(String args[]) throws Exception {
		String file =
		//	"A-example.in"
		//	"A-small-attempt0.in"
			"A-large.in"
		;
		BufferedReader in = new BufferedReader(new FileReader(file));
		PrintWriter out = new PrintWriter(new FileWriter(file + ".out"));
		final int T = Integer.parseInt(in.readLine());
		for(int casenr = 1; casenr  <= T; casenr++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int N = Integer.parseInt(st.nextToken());
			int time = 0;
			int opos = 1, otime = 0;
			int bpos = 1, btime = 0;
			for(int i = 0; i < N; i++) {
				char robot = st.nextToken().charAt(0);
				int despos = Integer.parseInt(st.nextToken());
				if(robot == 'O') {
					otime += Math.abs(opos - despos);
					opos = despos;
					if(otime < time)
						otime = time;
					otime++;
					time = otime;
				}
				else {
					btime += Math.abs(bpos - despos);
					bpos = despos;
					if(btime < time)
						btime = time;
					btime++;
					time = btime;
				}
			}
			out.println("Case #" + casenr + ": " + time);
			out.flush();
		}
		out.close();
	}
}
