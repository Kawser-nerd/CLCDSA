import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class C {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("c.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("c.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
			pw.printf("Case #%d: ", casenum);
			int n = readInt();
			int[] day = new int[n];
			int[] numAttack = new int[n];
			int[] west = new int[n];
			int[] east = new int[n];
			int[] startStr = new int[n];
			int[] deltaDay = new int[n];
			int[] deltaDist = new int[n];
			int[] deltaStr = new int[n];
			PriorityQueue<Event> q = new PriorityQueue<Event>();
			for (int i = 0; i < deltaStr.length; i++) {
				day[i] = readInt();
				numAttack[i] = readInt();
				west[i] = readInt();
				east[i] = readInt();
				startStr[i] = readInt();
				deltaDay[i] = readInt();
				deltaDist[i] = readInt();
				deltaStr[i] = readInt();
				for(int k = 0; k < numAttack[i]; k++)	{
					int w = west[i] + k * deltaDist[i];
					int e = east[i] + k * deltaDist[i];
					int time = day[i] + deltaDay[i] * k;
					int str = startStr[i] + deltaStr[i] * k;
					q.add(new Event(w,e,time,str));
				}
			}
			int ret = 0;
			TreeSet<State> wall = new TreeSet<State>();
			LinkedList<Cover> covers = new LinkedList<Cover>();
			int lastDay = -1;
			while(!q.isEmpty())	{
				Event curr = q.poll();
				if(curr.time != lastDay)	{
					//pw.println("NEW UPDATES");
					while(!covers.isEmpty())	{
						Cover currentCover = covers.removeFirst();
						//pw.println(currentCover);
						State rightBefore = wall.floor(new State(currentCover.right, 0));
						if(rightBefore == null)	{
							wall.add(new State(currentCover.right, 0));
							//pw.println(new State(currentCover.right, 0) + "A");
						}
						else	{
							wall.remove(new State(currentCover.right, 0));
							wall.add(new State(currentCover.right, rightBefore.height));
							//pw.println(new State(currentCover.right, rightBefore.height) + "B");
						}
						State push = new State(currentCover.left, currentCover.height);
						State left = wall.lower(push);
						if(left == null)	{
							wall.remove(push);
							wall.add(push);
							//pw.println(push + "C");
						}
						else if(left.height < currentCover.height)	{
							wall.remove(push);
							wall.add(push);
							//pw.println(push + "D");
						}
						while(push.position != currentCover.right)	{
							push = wall.higher(push);
							if(push.position == currentCover.right) {
								break;
							}
							if(push.height < currentCover.height)	{
								push.height = currentCover.height;
								wall.remove(push);
								wall.add(push);
								//pw.println(push + "E");
							}
						}
					}
					//pw.println("UPDATES OVER");
				}
				lastDay = curr.time;
				State artificial = new State(curr.west, 0);
				artificial = wall.floor(artificial);
				boolean bad = false;
				if(artificial == null)	{
					bad = true;
				}
				else	{
					while(!bad && (artificial != null && artificial.position < curr.east))	{
						//pw.println(artificial);
						if(artificial.height < curr.strength)	{
							//pw.println("Observe height " + artificial.height + " at " + artificial.position);
							bad = true;
						}
						artificial = wall.higher(artificial);
					}
				}
				if(bad)	{
					ret++;
					//pw.println(curr.west + " " + curr.east + " " + curr.time + " " + curr.strength + " fails");
					covers.add(new Cover(curr.west, curr.east, curr.strength));
				}
				else	{
					//pw.println(curr.west + " " + curr.east + " " + curr.time + " " + curr.strength + " passes");
				}
			}
			pw.println(ret);
		}
		pw.close();
	}

	static class Cover	{
		public int left,right,height;

		public Cover(int left, int right, int height) {
			super();
			this.left = left;
			this.right = right;
			this.height = height;
		}
		
		public String toString()	{
			return "GO FROM " + left + " to " + right + " at height " + height;
		}
		
	}
	
	static class Event implements Comparable<Event> {
		public int west, east;
		public int time;
		public int strength;
		public Event(int west, int east, int time, int strength) {
			super();
			this.west = west;
			this.east = east;
			this.time = time;
			this.strength = strength;
		}
		public int compareTo(Event e)	{
			return time - e.time;
		}
	}
	
	static class State implements Comparable<State> {
		public int position;
		public int height;
		public State(int position, int height) {
			super();
			this.position = position;
			this.height = height;
		}
		public int compareTo(State s)	{
			return position - s.position;
		}
		public String toString()	{
			return "Position: " + position + " and Height: " + height;
		}
	}
	
	public static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	public static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	public static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}

	public static String readLine() throws IOException	{
		st = null;
		return br.readLine();
	}


}
