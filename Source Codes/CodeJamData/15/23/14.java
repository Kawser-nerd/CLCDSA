import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;

public class ProblemC {
	public static void main(String[] args) throws NumberFormatException, IOException {
		FileWriter writer = new FileWriter("C:/Users/Max/Documents/Java Workspaces/Google Code Jam/Round 1B 2015/src/output.txt");		
		try {
			BufferedReader br = new BufferedReader(new FileReader("C:/Users/Max/Documents/Java Workspaces/Google Code Jam/Round 1B 2015/src/input.txt"));
			int numCases = Integer.parseInt(br.readLine());
			for (int caseNum = 1; caseNum <= numCases; caseNum++) {
				String line = br.readLine();
				int n = Integer.parseInt(line);
				long[][] hikerInfo = new long[2][2];
				int start = 0;
				int speed = 1;
				int index = 0;
				for(int i  = 0; i < n; i++){
					line = br.readLine();
					Scanner sc = new Scanner(line);
					long d = Long.parseLong(sc.next());
					long h = Long.parseLong(sc.next());
					long m = Long.parseLong(sc.next());
					for(int j = 0; j < h; j++){
						hikerInfo[index][start] = d;
						hikerInfo[index][speed] = m;
						m++;
						index++;
					}
				}
				if(index == 1 || hikerInfo[0][speed] == hikerInfo[1][speed]){
					System.out.println("ECIT");
					printAnswer("0", caseNum, writer);
				} else {
					int slow = 0;
					int fast = 1;
					if(hikerInfo[0][speed] < hikerInfo[1][speed]){
						slow = 1;
						fast = 0;
					}
					long distanceNeedSlow = 360 - hikerInfo[slow][start];
					long distanceNeedFast = 720 - hikerInfo[fast][start];

					System.out.println(distanceNeedSlow + " " + hikerInfo[slow][speed]);
					System.out.println(distanceNeedFast + " " + hikerInfo[fast][speed]);
					if(distanceNeedSlow * hikerInfo[slow][speed] < distanceNeedFast*hikerInfo[fast][speed]){
						printAnswer("0", caseNum, writer);
						//System.out.println("DECISION");
					} else {
						printAnswer("1", caseNum, writer);
					}
				}
				
			}
			br.close();
		} catch (FileNotFoundException e) {

			e.printStackTrace();
		}
		writer.close();
	}

	public static void printAnswer(String answer, int caseNumber, FileWriter writer) throws IOException {
		writer.write("Case #" + caseNumber + ": " + answer + "\n");
	}
}
