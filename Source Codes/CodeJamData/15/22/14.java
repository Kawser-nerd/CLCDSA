import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class ProblemB {
		
	public static void main(String[] args) throws NumberFormatException, IOException {
		FileWriter writer = new FileWriter("C:/Users/Max/Documents/Java Workspaces/Google Code Jam/Round 1B 2015/src/output.txt");		
		try {
			BufferedReader br = new BufferedReader(new FileReader("C:/Users/Max/Documents/Java Workspaces/Google Code Jam/Round 1B 2015/src/input.txt"));
			int numCases = Integer.parseInt(br.readLine());
			for (int caseNum = 1; caseNum <= numCases; caseNum++) {
				String line = br.readLine();
				Scanner sc = new Scanner(line);
				int r = Integer.parseInt(sc.next());
				int c = Integer.parseInt(sc.next());
				int n = Integer.parseInt(sc.next());
				if(r < c){
					int temp = r;
					r = c;
					c = temp;
				}
				if(n <= r*c - (r*c / 2)){
					printAnswer("0", caseNum, writer);
				} else {
					if(r == 1){
						printAnswer("0", caseNum, writer);
					} else if(c == 1){
						printAnswer("" + (r - 1 - 2*(r - n)), caseNum, writer);
					} else {
						int answer1 = 0;
						int leftover1 = n - (r*c - (r*c / 2));
						int corners = 2;
						if(r % 2 == 1 && c % 2 == 1){
							corners = 0;
						}
						int edges = (2*r + 2*c - 4)/2 - corners;
						answer1 += 2*Math.min(leftover1, corners);
						leftover1 -= corners;
						if(leftover1 > 0){
							answer1 += 3*Math.min(leftover1, edges);
							leftover1 -= edges;
							if(leftover1 > 0){
								answer1 += 4*leftover1;
							}
						}
						
						int leftover2 = n - (r*c / 2);
						int answer2 = 0;
						corners = 2;
						if(r % 2 == 1 && c % 2 == 1){
							corners = 4;
						}
						edges = (2*r + 2*c - 4)/2 - corners;
						answer2 += 2*Math.min(leftover2, corners);
						leftover2 -= corners;
						if(leftover2 > 0){
							answer2 += 3*Math.min(leftover2, edges);
							leftover2 -= edges;
							if(leftover2 > 0){
								answer2 += 4*leftover2;
							}
						}
						
						printAnswer("" + Math.min(answer1, answer2), caseNum, writer);
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
