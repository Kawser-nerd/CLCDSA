
import java.io.*;
import java.util.*;


public class ProblemB {

	public static final int STAGE_SAMPLE = 0;
	public static final int STAGE_SMALL  = 1;
	public static final int STAGE_LARGE  = 2;
	
	public static final String strDir        = "c:\\project\\codejam\\data\\";
	public static final String strFileBase   = "B";	

	public static final int NORTH = 1;
	public static final int SOUTH = 2;
	public static final int EAST  = 3;
	public static final int WEST  = 4;
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		ProblemB problem = new ProblemB();
		
		int nArgs = args.length;
		if(nArgs == 0) {	
			// test that sample input provided matches the sample output
			System.out.println("SAMPLE...");
			if(!problem.process(strDir + strFileBase + "-sample.in", strDir + strFileBase + "-sample.out", STAGE_SAMPLE)) {
				System.err.println("SAMPLE FAILED");
				System.exit(0);
			}
			System.out.println("SAMPLE DONE (PASSED)");
			
			// run the small input
			System.out.println("SMALL...");
			if(!problem.process(strDir + strFileBase + "-small.in", strDir + strFileBase + "-small.out", STAGE_SMALL)) {
				System.err.println("SMALL FAILED");
				System.exit(0);
			}
			System.out.println("SMALL DONE (WORKED)");

			// run the large input
			System.out.println("LARGE...");
			if(!problem.process(strDir + strFileBase + "-large.in", strDir + strFileBase + "-large.out", STAGE_LARGE)) {
				System.err.println("LARGE FAILED");
				System.exit(0);
			}
			System.out.println("LARGE DONE (WORKED)");
		}
		else if(nArgs == 2) 
			problem.process(args[0], args[1], STAGE_SMALL);
		else {
			System.err.println("Usage... java <problem> [infile] [outfile]");
			System.exit(0);
		}
		
		System.out.println("done");

	}
	
	/**
	 * Process all the cases in the input and write to output, or compare input and output file if STAGE_SAMPLE 
	 * @param sFileIn   The input file name 
	 * @param sFileOut  The output file name (or sample result when nStage = STAGE_SAMPLE)
	 * @param nStage    STAGE_SAMPLE, STAGE_SMALL, or STAGE_LARGE
	 * @return          true upon success
	 */
	public boolean process(String sFileIn, String sFileOut, int nStage) {
		
		BufferedReader reader  = null;
		Writer         writer  = null;
		StringWriter   writerT = null;
		BufferedReader readerT = null;
		
		try {
			reader = new BufferedReader(new FileReader(sFileIn));
			
			// open output for writing, or for reading if sample
			if(nStage != STAGE_SAMPLE)
				writer = new FileWriter(sFileOut);
			else 
				readerT = new BufferedReader(new FileReader(sFileOut));
			
			// get the number of cases
			String strCases = reader.readLine();
			int nCases = Integer.parseInt(strCases);
			
			// for each case
			for(int i=0; i<nCases; i++) {
							
				// create an input object
				////////////////////////////////////////////////
				/////////// DECODE INPUT START /////////////////
				Info info = new Info();
				info.nCase = i + 1;
				
				// read turnaround time
				String strLine = reader.readLine();
				info.nTurnAround = Integer.parseInt(strLine);

				// read nA nB
				strLine = reader.readLine();
				String[] strArgs = strLine.split(" ");
				int nA = Integer.parseInt(strArgs[0]);
				int nB = Integer.parseInt(strArgs[1]);
				
				// read trips A
				for(int j=0; j<nA; j++) {
					strLine = reader.readLine();
					strArgs = strLine.split(" ");
					String[] sStart = strArgs[0].split(":");
					int nStart = (Integer.parseInt(sStart[0]) * 60) + Integer.parseInt(sStart[1]);
					String[] sEnd = strArgs[1].split(":");
					int nEnd   = (Integer.parseInt(sEnd[0]) * 60) + Integer.parseInt(sEnd[1]); 
					
					Trip trip = new Trip();
					trip.bStartB = false;
					trip.nStart = nStart;
					trip.nEnd = nEnd;
					info.vectTrip.add(trip);
				}

				// read trips B
				for(int j=0; j<nB; j++) {
					strLine = reader.readLine();
					strArgs = strLine.split(" ");
					String[] sStart = strArgs[0].split(":");
					int nStart = (Integer.parseInt(sStart[0]) * 60) + Integer.parseInt(sStart[1]);
					String[] sEnd = strArgs[1].split(":");
					int nEnd   = (Integer.parseInt(sEnd[0]) * 60) + Integer.parseInt(sEnd[1]); 
					
					Trip trip = new Trip();
					trip.bStartB = true;
					trip.nStart = nStart;
					trip.nEnd = nEnd;
					info.vectTrip.add(trip);
				}
				
				/////////// DECODE INPUT END ///////////////////
				////////////////////////////////////////////////
				
				if(nStage == STAGE_SAMPLE) 
					writerT = new StringWriter();
				
				// process case
				Writer writerUse = (nStage == STAGE_SAMPLE ? writerT : writer);
				if(!processCase(info, writerUse)) {
					System.err.println("ERROR: processCase() Failed:" + info.nCase);
					return false;
				}
				
				// compare if stage sample
				if(nStage == STAGE_SAMPLE) {
					
					// read the processed output, and split
					String strLine1 = writerT.toString(); 
					String[] strArray1 = strLine.split(" ");
					int    nArray1 = strArray1.length;
					
					// read an output line, and split
					String strLine2 = readerT.readLine();
					String[] strArray2 = strLine.split(" ");
					int    nArray2 = strArray2.length;
					
					// whitespace independent comparison. Need a 1e-6 float point comparison.
					boolean bEqual = true;
					if(nArray1 != nArray2) 
						bEqual = false;
					else {
						for(int a=0; a<nArray1; a++) {
							if(strArray1[a].compareTo(strArray2[a]) != 0) {
								bEqual = false;
								break;
							}
						}
					}
						
					// report that processed output isn't the same as the sample output
					if(!bEqual) {
						System.err.println("ERROR: SAMPLE COMPARISON FAILED");
						System.err.println("OUTPUT (PROC):" + strLine1);
						System.err.println("OUTPUT (HTML):" + strLine2);
						return false;
					}
				}
			}
			
		}
		catch(IOException ioex) {
			ioex.printStackTrace();
			return false;
		}
		catch(Exception ex) {
			ex.printStackTrace();
			return false;
		}
		finally {
			if(reader !=  null) {
				try { 
					reader.close();
					if(nStage == STAGE_SAMPLE)
						readerT.close();
					else
						writer.close();
				} catch(Exception exz) {}
			}
		}
		
		return true;
	}
	
	
	/**
	 * Process one case.
	 * @param info    The decoded input in an object
	 * @param writer  The writer to write to
	 * @return        true upon success
	 */
	public boolean processCase(Info info, Writer writer) {
		
		info.process();
				
		try {
			System.out.println("Case #" + info.nCase + ": " + info.nStartA + " " + info.nStartB);
			writer.write("Case #" + info.nCase + ": " + info.nStartA + " " + info.nStartB + "\n");
										
	
		}
		catch(IOException ioex) {
			ioex.printStackTrace();
			return false;
		}
		return true;
	}


	class Info {
		
		public int nCase;
		
		public int nTurnAround;
				
		public Vector<Trip> vectTrip = new Vector(); 
		
		public Vector<Train> vectTrainA = new Vector();
		public Vector<Train> vectTrainB = new Vector();
		
		public int nStartA = 0;
		public int nStartB = 0;
		
		public Info() {}
		
		public void process() {
			
			int nTime = 0;
			
			// no trips left, we are done
			while(true) {
				int nTrip = vectTrip.size();
				if(nTrip == 0)
					return;
				
				// find earliest trip
				int nEarliest = 100000000;
				Trip trip = null;
				for(int i=0; i<nTrip; i++) {
					Trip tripX = (Trip)vectTrip.get(i);
					int nDepart = tripX.nStart;
					
					if(nDepart < nEarliest) {
						trip = tripX;
						nEarliest = nDepart;
					}
				}
				vectTrip.remove(trip);
				if(!trip.bStartB)
					System.out.println("Trip " + trip.nStart + " -> " + trip.nEnd);
				else
					System.out.println("Trip " + trip.nEnd + " <- " + trip.nStart);
				nTime = trip.nStart;
				
				// see if we have a train ready at A
				if(!trip.bStartB) {
					
					int nTrain = vectTrainA.size();
					Train train = null;
					for(int k=0; k<nTrain; k++) {
						Train t = (Train)vectTrainA.get(k);
						if(t.nReadyTime <= nTime) {
							train = t;
							break;
						}
					}
					
					if(train == null) {
						nStartA++;
						train = new Train();
					}
					else {
						vectTrainA.remove(train);
					}
					
					train.nReadyTime = trip.nEnd + nTurnAround;
					vectTrainB.add(train);
				}
				else {
					int nTrain = vectTrainB.size();
					Train train = null;
					for(int k=0; k<nTrain; k++) {
						Train t = (Train)vectTrainB.get(k);
						if(t.nReadyTime <= nTime) {
							train = t;
							break;
						}
					}
					
					if(train == null) {
						nStartB++;
						train = new Train();
					}
					else {
						vectTrainB.remove(train);
					}
					
					train.nReadyTime = trip.nEnd + nTurnAround;
					vectTrainA.add(train);
					
				}
			
			
			}
		}
	}
	
	class Trip  {
		
		public boolean bStartB = false;
		public int     nStart;
		public int     nEnd;
		
		public Trip() { }
	}
	
	class Train {
		
		public int nReadyTime;
			
		public Train() {}
	}
	
}
