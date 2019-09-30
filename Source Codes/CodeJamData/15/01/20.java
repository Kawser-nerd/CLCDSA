package round0;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class StandingOvation {
	private static FileWriter writer;

	public static void main(String[] args) throws IOException {
		File file = new File("round0/A-large.in");
		BufferedReader reader = new BufferedReader(new FileReader(file));
	
		File outputFile = new File("round0/output-ovation.txt");
		writer = new FileWriter(outputFile);
		int numberOfPerformances = Integer.parseInt(reader.readLine());
		for (int show = 1; show <= numberOfPerformances; show++) {
			String[] split = reader.readLine().split(" ");
			int length = Integer.parseInt(split[0]);
			char[] audience = split[1].toCharArray();
			
			generateOutput("Case #" + show + ": " + invitedFriends(length, audience));
		}
		
		
		reader.close();
		writer.close();
	}
	
	private static int invitedFriends(int length, char[] audience) {
		int friends = 0;
		int totalStanding = 0;
		for (int i = 0; i < length + 1; i++) {
			totalStanding += Integer.parseInt("" + audience[i]);
			if (totalStanding < i + 1) {
				friends++;
				totalStanding++;
			}
		}
		return friends;
	}

	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}
}
