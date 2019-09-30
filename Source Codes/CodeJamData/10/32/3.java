import java.io.*;
import java.util.*;

public class TWO
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int t = 1; t <= T; t++) {
			String[] line = br.readLine().split(" ");
			long L = Integer.parseInt(line[0]);
			long P = Integer.parseInt(line[1]);
			long C = Integer.parseInt(line[2]);
			int y = 1;
			while(L*C < P && L*C > 0)
			{
				L *= C;
				y++;
			}
			System.out.println("Case #"+t+": "+(int)(Math.log(y)/Math.log(2)+0.9999));
		}
	}
}