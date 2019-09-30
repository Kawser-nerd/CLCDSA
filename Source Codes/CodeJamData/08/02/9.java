package emm.cj08;

import java.io.*;
import java.util.*;

public class Train {
	private static final File IN = new File("/home/eric/cj/train-in.txt"), OUT = new File("/home/eric/cj/train-out.txt");
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(IN));
		PrintStream ps = new PrintStream(OUT);
		
		int trials = Integer.parseInt(br.readLine());
		for(int trial = 0; trial < trials; trial++) {
			int turn = Integer.parseInt(br.readLine());
			
			String[] line = br.readLine().split(" ");
			int na = Integer.parseInt(line[0]);
			int nb = Integer.parseInt(line[1]);
			
			PriorityQueue<TimeItem> queue = new PriorityQueue<TimeItem>();
			
			PriorityQueue<Integer> atA = new PriorityQueue<Integer>(), atB = new PriorityQueue<Integer>();
			int trainsA = 0, trainsB = 0;
			
			for(int n = 0; n < na; n++)
				queue.add(new TimeItem(br.readLine(), true));
			
			for(int n = 0; n < nb; n++)
				queue.add(new TimeItem(br.readLine(), false));
			
			while(!queue.isEmpty()) {
				TimeItem cur = queue.poll();
				PriorityQueue<Integer> curAt = cur.getDirection() ? atA : atB;
				
				if(!curAt.isEmpty() && curAt.peek() <= cur.getStart()) {
					curAt.poll();
				} else {
					if(cur.getDirection())
						trainsA++;
					else
						trainsB++;
				}
				
				if(cur.getDirection())
					atB.add(cur.getEnd() + turn);
				else
					atA.add(cur.getEnd() + turn);
			}
			
			ps.println("Case #" + (trial + 1) + ": " + trainsA + " " + trainsB);
		}
		
		br.close();
		ps.close();
	}
	
	private static class TimeItem implements Comparable<TimeItem> {
		private int start, end;
		private boolean direction;
		
		public TimeItem(String line, boolean direction) {
			String[] arr = line.split(" ");
			
			start = parseTime(arr[0]);
			end = parseTime(arr[1]);
			this.direction = direction;
		}
		
		public boolean getDirection() {
			return direction;
		}
		
		public int getStart() {
			return start;
		}
		
		public int getEnd() {
			return end;
		}
		
		private int parseTime(String time) {
			String[] parts = time.split(":");
			
			return Integer.parseInt(parts[0]) * 60 + Integer.parseInt(parts[1]); 
		}
		
		public int compareTo(TimeItem other) {
			return new Integer(start).compareTo(other.start);
		}
	}
}
