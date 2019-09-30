import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class ProblemA {
		
	public static void main(String[] args) throws NumberFormatException, IOException {
		FileWriter writer = new FileWriter("C:/Users/Max/Documents/Java Workspaces/Google Code Jam/Round 1B 2015/src/output.txt");		
		try {
			BufferedReader br = new BufferedReader(new FileReader("C:/Users/Max/Documents/Java Workspaces/Google Code Jam/Round 1B 2015/src/input.txt"));
			int numCases = Integer.parseInt(br.readLine());
			for (int caseNum = 1; caseNum <= numCases; caseNum++) {
				String line = br.readLine();
				long n = Long.parseLong(line);
				;
				if(n == 1){
					printAnswer("1", caseNum, writer);
				} else {
					boolean endsInZero = (n % 10 == 0);
					if(endsInZero){
						n--;
					}
					int numDigits = ("" + n).length();
					long answer = 0;
					for(int i = 1; i < numDigits; i++){
						if(i == 1){
							answer += 10;
						} else {
							int half = i/2;
							int otherHalf = i - half;
							answer += powerOfTen(half) + powerOfTen(otherHalf) - 1;
						}
					}
					int half = numDigits/2;
					int otherHalf = numDigits - half;
					long partialValue = n % powerOfTen(otherHalf);
					answer += partialValue;
					n -= partialValue;
					String partial = "" + n;
					String reverse = "";
					for(int i = 0; i < partial.length(); i++){
						reverse = partial.charAt(i) + reverse;
					}
					long otherPart = Long.parseLong(reverse);
					answer+= otherPart - 1;
					if(otherPart != 1){
						answer++;
					}
					if(endsInZero){
						answer++;
					}
					printAnswer("" + answer, caseNum, writer);
				}
			}
			br.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		writer.close();
	}

	public static long powerOfTen(int power){
		long result = 1;
		for(int i = 0; i < power; i++){
			result *= 10;
		}
		return result;
	}
	
	public static void printAnswer(String answer, int caseNumber, FileWriter writer) throws IOException {
		writer.write("Case #" + caseNumber + ": " + answer + "\n");
	}
}
