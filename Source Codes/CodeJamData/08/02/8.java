import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;

class Train {
	/** 0 means A, 1 means B */
	int loc;
	/** true means the train is being used */
	boolean[] used;
	
	public Train(int loc) {
		this.loc = loc;
		used = new boolean[24 * 60];
	}
	/**
	 * Makes the train used starting at start to end -1 inclusive
	 * @param start
	 * @param end
	 */
	public void fill(int start, int end) {
		int max = Math.min(1440, end);
		for (int i = start ; i < max; i++) {
			used[i] = true;
		}
	}
}

class Trip implements Comparable<Trip>{
	/** 0 means starts at A */
	int loc;
	/** time in minutes */
	int start, end;
	
	public Trip(int loc, int start, int end) {
		this.loc = loc;
		this.start = start;
		this.end = end;
	}

	@Override
	public int compareTo(Trip o) {
		
		if (start < o.start) {
			return -1;
		}
		else if (start == o.start) {
			return 0;
		}
		else {
			return 1;
		}
		
	}
	
	
	
	
}

public class TrainTimetable {
	public int convertMin(String time) {
		//parse the :
		int t;
		int h = Integer.parseInt(time.substring(0, 2));
		int m = Integer.parseInt(time.substring(3,5));
		t = h * 60 + m;
		return t;
	}
	
	public void solve(Scanner in, PrintStream out) throws Exception {
		int numTests = in.nextInt();
		for (int test = 1; test <= numTests; test++) {
			//Turnaround time in MINUTES
			int delay = in.nextInt();
			
			//Number of trains leaving from x to !x
			int na = in.nextInt();
			int nb = in.nextInt();
			
			Vector<Trip> trips = new Vector<Trip>();
			
			//Load the trains leaving from a
			for (int i = 0; i < na; i++) {
				//Loading the HH:MM into minutes
				String time = in.next();
				int tStart = convertMin(time);
				
				time = in.next();
				int tEnd = convertMin(time);
				
				//System.out.println(tStart + " " + tEnd);
				trips.add(new Trip(0, tStart, tEnd));
			}
			
			//Load the trains leaving from b
			for (int i = 0; i < nb; i++) {
				//Loading the HH:MM into minutes
				String time = in.next();
				int tStart = convertMin(time);
				
				time = in.next();
				int tEnd = convertMin(time);
				
				//System.out.println(tStart + " " + tEnd);
				trips.add(new Trip(1, tStart, tEnd));
			}
			
			//Sort the trip by start time
			Collections.sort(trips);
			
			//Display all the trips
			/*for (int i = 0; i < trips.size(); i++) {
				if (trips.get(i).loc == 0) {
					System.out.print("Start at a: ");
				}
				else {
					System.out.print("Start at b: ");
				}
				System.out.println(trips.get(i).start + " " + trips.get(i).end);
			}
			*/
			
			
			int numA = 0, numB = 0;
			Vector<Train> trains = new Vector<Train>();
			
			for (int i = 0; i < trips.size(); i++) {
				//Go through each trip
				Trip trip = trips.get(i);
				
				//Try to find a suitable train
				boolean findTrain = false;
				for (int j = 0; j < trains.size(); j++) {
					//See if the train is at the right place and is unused
					Train train = trains.get(j);
					if (train.loc == trip.loc && train.used[trip.start] == false) {
						//Used the train
						//Move the train from a to b and vice versa
						if (train.loc == 1) {
							train.loc = 0;
						}
						else {
							train.loc = 1;
						}
						train.fill(trip.start, trip.end + delay);
						findTrain = true;
						break;						
					}
				}
				
				if (!findTrain) {
					//Otherwise create one
					if (trip.loc == 0) {
						//Create a train at a
						numA++;
						//train is now at b
						Train train = new Train(1);
						train.fill(trip.start, trip.end + delay);
						trains.add(train);
						
					}
					else {
						//Create a train at a
						numB++;
						//train is now at a
						Train train = new Train(0);
						train.fill(trip.start, trip.end + delay);
						trains.add(train);
					}
				}
				
			}
			
			out.println("Case #" + test + ": " + numA + " " + numB);
		}
	}

	public static void main(String[] args) throws Exception {
		Scanner in = null;
		PrintStream out = null;
		in = new Scanner(System.in);
		out = System.out;
		in = new Scanner(new FileReader("B-large.in"));
		out = new PrintStream(new FileOutputStream("b-large.out"));
		new TrainTimetable().solve(in, out);
		out.close();
		System.exit(0);
	}
}
