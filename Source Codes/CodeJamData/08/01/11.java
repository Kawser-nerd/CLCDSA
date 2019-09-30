
import java.io.*;
import java.util.*;



public class ProblemA {

	public static final int STAGE_SAMPLE = 0;
	public static final int STAGE_SMALL  = 1;
	public static final int STAGE_LARGE  = 2;
	
	public static final String strDir        = "c:\\project\\codejam\\data\\";
	public static final String strFileBase   = "A";	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		ProblemA problem = new ProblemA();
		
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

				// read the number of engines
				String strLine = reader.readLine();
				info.nEngine = Integer.parseInt(strLine);

				// read the engines
				for(int e=0; e<info.nEngine; e++) {
					strLine = reader.readLine();
					strLine = strLine.trim();
					info.vectEngine.add(strLine);
				}
				
				// read the number of queries
				strLine = reader.readLine();
				info.nSearch = Integer.parseInt(strLine);

				// read the searches
				for(int e=0; e<info.nSearch; e++) {
					strLine = reader.readLine();
					strLine = strLine.trim();
					info.vectSearch.add(strLine);
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
		
		// count the occurences
		info.minSwitches(-1, null);
		
		String strLineOut = "Case #" + info.nCase + ": " + info.nSwitches;
		
		try {
			System.out.println(strLineOut);
			writer.write(strLineOut + "\n");
		}
		catch(IOException ioex) {
			ioex.printStackTrace();
			return false;
		}
		
		return true;
	}
	

	
	class Info {
		public int nCase;
		
		public int nEngine;
		public Vector<String> vectEngine = new Vector();
		
		public int nSearch;
		public Vector<String> vectSearch = new Vector();
		
		public int nSwitches;
		
		public Info() {
			nSwitches = 0;
		}
		
		public void minSwitches(int nPos, String sCurrent) {
						
			int nBest = -1;
			String sBest = null;
						
			for(int i=0; i<nEngine; i++) {
				String sEngine = (String)vectEngine.get(i);
				
				if(sCurrent != null && sEngine.equals(sCurrent))
					continue;
				
				int nRun = runLength(nPos+1, sEngine);
				
				if(nRun == -1)
					return;
				
				if(nRun > nBest) {
					nBest = nRun;
					sBest = sEngine;
				}
			}
			
			// switch 
			nSwitches++;
			
			minSwitches(nPos + nBest, sBest);
		}
				
		public int runLength(int index, String s) {	
			for(int i=index; i<nSearch; i++) {
				String sSearch = (String)vectSearch.get(i);
				if(sSearch.equals(s)) 
					return i-index;
			}
			return -1;
		}
		
	}

	
}
