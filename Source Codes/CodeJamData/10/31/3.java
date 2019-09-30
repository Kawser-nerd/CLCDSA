import java.io.*;
import java.util.*;

public class ONE
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int t = 1; t <= T; t++) {
			String[] line = br.readLine().split(" ");
			int N = Integer.parseInt(line[0]);
			int[][] wires = new int[N][2];
			for(int n = 0; n < N; n++)
			{
				line = br.readLine().split(" ");
				wires[n][0] = Integer.parseInt(line[0]);
				wires[n][1] = Integer.parseInt(line[1]);
			}
			int intersections = 0;
			for(int i = 0; i < N; i++)
				for(int j = 0; j < N; j++)
					if(wires[i][0] > wires[j][0] && wires[i][1] < wires[j][1])
						intersections++;
			System.out.println("Case #"+t+": "+intersections);
		}
	}
}