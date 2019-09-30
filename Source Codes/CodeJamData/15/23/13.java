import java.io.*;
import java.util.*;
import java.math.*;

public class HikingDeer {
	static int c;

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("out.out"));
		int t = Integer.parseInt(br.readLine());
		for(c = 1; c <= t; c++){
			bw.write("Case #" + c + ": ");
			String line = br.readLine();
			int n = Integer.parseInt(line);
			long[][] hikers = new long[2][2];
			int index = 0;
			for(int i = 0; i < n; i++){
				line = br.readLine();
				String[] fields = line.split(" ");
				for(int j = 0; j < Integer.parseInt(fields[1]); j++){
					hikers[index][0] = Long.parseLong(fields[0]);
					hikers[index][1] = Long.parseLong(fields[2]) + j;
					index++;
				}
			}
			System.out.println(hikers[0][0] + " " + hikers[0][1]);
			System.out.println(hikers[1][0] + " " + hikers[1][1]);
			if(hikers[1][1] == 0){
				bw.write(0 + "\n");
				continue;
			}
			System.out.println((720 - hikers[0][0]) * hikers[0][1]);
			System.out.println();
			if((720 - hikers[0][0]) * hikers[0][1] <= (360 - hikers[1][0]) * hikers[1][1]){
				bw.write(1 + "\n");
				continue;
			}
			if((720 - hikers[1][0]) * hikers[1][1] <= (360 - hikers[0][0]) * hikers[0][1]){
				bw.write(1 + "\n");
				continue;
			}
			bw.write(0 + "\n");
		}
		br.close();
		bw.close();
	}


}