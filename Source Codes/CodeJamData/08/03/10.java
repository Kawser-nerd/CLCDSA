
import java.io.*;
import java.util.*;



public class ProblemC {

	public static final int STAGE_SAMPLE = 0;
	public static final int STAGE_SMALL  = 1;
	public static final int STAGE_LARGE  = 2;
	
	public static final String strDir        = "c:\\project\\codejam\\data\\";
	public static final String strFileBase   = "C";	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		ProblemC problem = new ProblemC();
		
		int nArgs = args.length;
		if(nArgs == 0) {	
			// test that sample input provided matches the sample output
			System.out.println("SAMPLE...");
			if(!problem.process(strDir + strFileBase + "-sample.in", strDir + strFileBase + "-sample.out", STAGE_SAMPLE)) {
				System.out.println("SAMPLE FAILED");
				System.exit(0);
			}
			System.out.println("SAMPLE DONE (PASSED)");
			
			// run the small input
			System.out.println("SMALL...");
			if(!problem.process(strDir + strFileBase + "-small.in", strDir + strFileBase + "-small.out", STAGE_SMALL)) {
				System.out.println("SMALL FAILED");
				System.exit(0);
			}
			System.out.println("SMALL DONE (WORKED)");

			// run the large input
			System.out.println("LARGE...");
			if(!problem.process(strDir + strFileBase + "-large.in", strDir + strFileBase + "-large.out", STAGE_LARGE)) {
				System.out.println("LARGE FAILED");
				System.exit(0);
			}
			System.out.println("LARGE DONE (WORKED)");
		}
		else if(nArgs == 2) 
			problem.process(args[0], args[1], STAGE_SMALL);
		else {
			System.out.println("Usage... java <problem> [infile] [outfile]");
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
			
				// read a line and split args
				String strLine = reader.readLine();
				String[] strArgs = strLine.split(" ");
				
				// create an input object
				////////////////////////////////////////////////
				/////////// DECODE INPUT START /////////////////
				Info info = new Info();
				info.nCase = i + 1;
				info.dBall      = Double.parseDouble(strArgs[0]);
				info.dRaquet    = Double.parseDouble(strArgs[1]);
				info.dThickness = Double.parseDouble(strArgs[2]);
				info.dString    = Double.parseDouble(strArgs[3]);
				info.dGap       = Double.parseDouble(strArgs[4]);

				/////////// DECODE INPUT END ///////////////////
				////////////////////////////////////////////////
				
				if(nStage == STAGE_SAMPLE) 
					writerT = new StringWriter();
				
				// process case
				Writer writerUse = (nStage == STAGE_SAMPLE ? writerT : writer);
				if(!processCase(info, writerUse)) {
					System.out.println("ERROR: processCase() Failed:" + info.nCase);
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
						System.out.println("ERROR: SAMPLE COMPARISON FAILED");
						System.out.println("OUTPUT (PROC):" + strLine1);
						System.out.println("OUTPUT (HTML):" + strLine2);
						return false;
					}
				}
			}
			
		}
		catch(java.io.FileNotFoundException iof) {
			System.out.println("File not Found.");
			return false;
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
		
		String strLineOut = "Case #" + info.nCase + ": " + info.dProb;
		
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
		public double dBall;
		public double dRaquet;
		public double dThickness;
		public double dString;
		public double dGap;		
		
		public double dProb;
		
		public Info() {}
		
		public void process() {
			
			// special case
			if(dBall * 2.0 >= dGap) {
				dProb = 1.0;
				return;
			}
						
			double dBigR = dRaquet;
			double dBigQtr = Math.PI * dBigR * dBigR / 4.0; // one quarter
			
			// do 1 quarter
			double dAreaMiss = 0.0;
			double dSpan = dGap + dString + dString;
			
			// the area in a full cell to miss
			double dLenF = dGap - (dBall * 2);
			double dAreaF = dLenF * dLenF;
			
			double dInner = dRaquet - dThickness;
			double dGapsPerp = (dInner - dString) / dSpan;
			int    nGaps = (int)Math.ceil(dGapsPerp);
			
			double dInnerB = dInner - dBall;    // half ball inside raquet
			
			for(int y=0; y<nGaps; y++) {
				double dY = dString + ((double)y * dSpan);
				double dY2 = dY + dGap;

				for(int x=0; x<nGaps; x++) {	
					double dX = dString + ((double)x * dSpan);
					double dX2 = dX + dGap;
					
					double dNear = Math.sqrt((dX * dX) + (dY * dY));
					double dFar  = Math.sqrt((dX2 * dX2) + (dY2 * dY2));
					
					if(dNear >= dInner)
						continue;  // we are completely outside inner
					
					if(dFar <= dInner) {
						// a whole square
						dAreaMiss += dAreaF;
						continue;
					}
					
					// a partial
					double dLowerB = dY + dBall;
					double dLeftB  = dX + dBall;
					
					double dDist = Math.sqrt((dLowerB * dLowerB) + (dLeftB * dLeftB));
					if(dDist >= dInnerB)
						continue; // no sliver at all for ball to pass through
					
					// see how many points are in or out
					double dRightFull = dLeftB + dLenF;
					double dTopFull   = dLowerB + dLenF;
					
					boolean bRightInside = (Math.sqrt((dLowerB * dLowerB) + (dRightFull * dRightFull)) <= dInnerB);
					boolean bTopInside   = (Math.sqrt((dLeftB * dLeftB) + (dTopFull * dTopFull)) <= dInnerB);
					
					if(!bRightInside && !bTopInside) {
						// find top
						double dRatioX = dLeftB / dInnerB;
						double dAngle1 = Math.acos(dRatioX);
						double dTopB   = Math.sin(dAngle1) * dInnerB;
						
						// find right
						double dRatioY = dLowerB / dInnerB;
						double dAngle2 = Math.asin(dRatioY);
						double dRightB = Math.cos(dAngle2) * dInnerB;

						double dSideX  = dRightB - dLeftB;
						double dSideY  = dTopB - dLowerB;
						
						if(dSideX < 0.0)
							System.out.println("ERROR side X 1\n");
						else if(dSideY < 0.0)
							System.out.println("ERROR side Y 1\n");
							
						double dTriangle = dSideX * dSideY / 2.0;
						double dTheta    = dAngle1 - dAngle2;
						double dSegment  = dInnerB * dInnerB * 0.5 * (dTheta - Math.sin(dTheta));
							
						dAreaMiss += (dTriangle + dSegment);
						
					}
					else if(bRightInside && !bTopInside) {
					
						// raise lowerB (findY)
						double dRatio2 = dRightFull / dInnerB;
						double dAngleM = Math.acos(dRatio2);
						double dNewM   = Math.sin(dAngleM) * dInnerB;
						
						dAreaMiss += (dNewM - dLowerB) * dLenF;
						dLowerB = dNewM;

						// find top (findY)
						double dRatioX = dLeftB / dInnerB;
						double dAngle1 = Math.acos(dRatioX);
						double dTopB   = Math.sin(dAngle1) * dInnerB;
						
						// find right
						double dRatioY = dLowerB / dInnerB;
						double dAngle2 = Math.asin(dRatioY);
						double dRightB = Math.cos(dAngle2) * dInnerB;

						double dSideX  = dRightB - dLeftB;
						double dSideY  = dTopB - dLowerB;
						
						if(dSideX < 0.0)
							System.out.println("ERROR side X 2\n");
						else if(dSideY < 0.0)
							System.out.println("ERROR side Y 2\n");
							
						double dTriangle = dSideX * dSideY / 2.0;
						double dTheta    = dAngle1 - dAngle2;
						double dSegment  = dInnerB * dInnerB * 0.5 * (dTheta - Math.sin(dTheta));
							
						dAreaMiss += (dTriangle + dSegment);						
					}
					else if(!bRightInside && bTopInside) {
						
						// shift leftB (findX)
						double dRatio2 = dTopFull / dInnerB;
						double dAngleN = Math.asin(dRatio2);
						double dNewN   = Math.cos(dAngleN) * dInnerB;
						
						dAreaMiss += (dNewN - dLeftB) * dLenF;
						dLeftB = dNewN;
						
						// find top (findY)
						double dRatioX = dLeftB / dInnerB;
						double dAngle1 = Math.acos(dRatioX);
						double dTopB   = Math.sin(dAngle1) * dInnerB;
												
						// find right (findX)
						double dRatioY = dLowerB / dInnerB;
						double dAngle2 = Math.asin(dRatioY);
						double dRightB = Math.cos(dAngle2) * dInnerB;

						double dSideX  = dRightB - dLeftB;
						double dSideY  = dTopB - dLowerB;
						
						if(dSideX < 0.0)
							System.out.println("ERROR side X 3\n");
						else if(dSideY < 0.0)
							System.out.println("ERROR side Y 3\n");
							
						double dTriangle = dSideX * dSideY / 2.0;
						double dTheta    = dAngle1 - dAngle2;
						double dSegment  = dInnerB * dInnerB * 0.5 * (dTheta - Math.sin(dTheta));
							
						dAreaMiss += (dTriangle + dSegment);
					
					}
					else {
						
						// raise lowerB (findY)
						double dRatio3 = dRightFull / dInnerB;
						double dAngleM = Math.acos(dRatio3);
						double dNewM   = Math.sin(dAngleM) * dInnerB;

						// shift leftB (findX)
						double dRatio2 = dTopFull / dInnerB;
						double dAngleN = Math.asin(dRatio2);
						double dNewN   = Math.cos(dAngleN) * dInnerB;
						
						dAreaMiss += (dNewM - dLowerB) * dLenF;
						dAreaMiss += (dNewN - dLeftB) * dLenF;
						dAreaMiss -= (dNewM - dLowerB) * (dNewN - dLeftB);
						
						
						dLeftB = dNewN;
						dLowerB = dNewM;
						
						// find top (findY)
						double dRatioX = dLeftB / dInnerB;
						double dAngle1 = Math.acos(dRatioX);
						double dTopB   = Math.sin(dAngle1) * dInnerB;
												
						// find right (findX)
						double dRatioY = dLowerB / dInnerB;
						double dAngle2 = Math.asin(dRatioY);
						double dRightB = Math.cos(dAngle2) * dInnerB;

						double dSideX  = dRightB - dLeftB;
						double dSideY  = dTopB - dLowerB;
						
						if(dSideX < 0.0)
							System.out.println("ERROR side X  4: " + dSideX + "\n");
						else if(dSideY < 0.0)
							System.out.println("ERROR side Y  4: \n");
							
						double dTriangle = dSideX * dSideY / 2.0;
						double dTheta    = dAngle1 - dAngle2;
						double dSegment  = dInnerB * dInnerB * 0.5 * (dTheta - Math.sin(dTheta));
							
						dAreaMiss += (dTriangle + dSegment);
						
					}
					
					
					
					/*double dTheta = dAngle1 - dAngle2;
					
					if(dTheta <= 0.0 || dTheta > Math.PI/2.0) 
						System.out.println("ERROR angle\n");
					*/
					
					//
					
					
					
					//dAreaMiss += dTriangle;
					
					/*
					// use longest side
					if(dSideX > dSideY) {
						for(double p=dLeftB; p<dRightB; p+=dInc) {
							// find top
							double dRatioP = p / dInnerB;
							double dA      = Math.acos(dRatioP);
							double dTB     = Math.sin(dA) * dInnerB;
							if(dTB > dLowerB) 
								dAreaMiss += ( (dTB-dLowerB) * dInc );
						}
					}
					else {
						for(double p=dLowerB; p<dTopB; p+=dInc) {
							// find right
							double dRatioP = p / dInnerB;
							double dA      = Math.acos(dRatioP);
							double dRB     = Math.sin(dA) * dInnerB;
							if(dRB > dLeftB) 
								dAreaMiss += ( (dRB-dLeftB) * dInc );
						}
					}
					*/
				}
			}
			
			
			// prob
			dProb = 1.0 - (dAreaMiss / dBigQtr);
		}
		
	}

	
}
